 /*
 *        FILE: client.cpp
 *  Created on: June, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

using namespace std;


Client * Client::M_instance = 0;

Client::Client() 
{
	pthread_mutex_init( &M_message_queue_mutex, NULL     );
	pthread_mutex_init( &M_command_mutex, NULL           );
	pthread_mutex_init( &M_sending_cond_mutex, NULL      );
	pthread_mutex_init( &M_process_activator_mutex, NULL );

	pthread_cond_init( &M_sending_cond, NULL );
	pthread_cond_init( &M_process_activator, NULL );

}

Client & 
Client::instance()
{
	if( M_instance == 0 )
	{
		M_instance = new Client;
	}
	return *M_instance;
}


Client::~Client()
{
	if( M_agent ) delete M_agent;

	M_agent = 0;
}

std::string const &    
Client::host()
{
	return M_host;
}

unsigned               
Client::port()
{
	return M_port;
}


std::string const &    
Client::server_version()
{
	return M_server_version;
}

std::string const &    
Client::teamname()
{
	return M_teamname;
}

unsigned
Client::unum()
{
	return M_unum;
}

bool                   
Client::is_goalie()
{
	return M_is_goalie;
}


void 
Client::set_host( std::string const & host )
{
	if( M_active )
		Log::out( Log::ERROR, "Cannot change host while the client is active.\n" );
	else
		M_host = host;
}

void 
Client::set_port( unsigned port )
{
	if( M_active )
		Log::out( Log::ERROR, "Cannot change port while the client is active." );
	else
		M_port = port;
}

void 
Client::set_server_version( std::string const & version )
{
	if( M_active )
		Log::out( Log::ERROR, "Cannot change version while the client is active." );
	else
		M_server_version = version;
}

void 
Client::set_teamname( std::string const & teamname )
{
	if( M_active )
		Log::out( Log::ERROR, "Cannot change teamname while the client is active." );
	else	
		M_teamname = teamname;
}

void 
Client::set_unum ( unsigned unum )
{
	if( M_active )
		Log::out( Log::ERROR, "Cannot change teamname while the client is active." );
	else	
		M_unum = unum;
}

void 
Client::set_is_goalie( bool goalie )
{
	if( M_active )
		Log::out( Log::ERROR, "Cannot change goalie while the client is active." );
	else	
		M_is_goalie = goalie;
}


// void 
// Client::reg_driver( ClientParser::Driver * driver  )
// {
// 	M_driverforwarder.register_driver( driver );
// }

// void
// Client::reg_sensorhandler()
// {
// 	M_driverforwarder.register_driver( &M_psbridge );
// }

void 
Client::set_agent( Agent * agent )
{
	M_agent = agent;
	M_psbridge.set_sensorhandler( agent );
}


void Client::main_loop()
{
	{
		M_active = true;
	}

	{
		Log::init();
		Log::set_stream( stdout );
		Log::set_level( Log::DEBUG );
		char num[3]; snprintf( num, 3, "%u", unum() );
		std::string signature = teamname() + " " + num ;
		Log::set_signature( signature  );
	}

	{
		signal( SIGINT, Client::signal_handler );
	}

	{	
		M_agent->init( teamname(), unum(), 
			is_goalie(), server_version()  );
		//M_actuator = &(M_agent->actuator());
	}

	{
		pthread_create( &M_process_thread, NULL, Client::process_thread_function, &Client::instance() );
		pthread_create( &M_sending_thread, NULL, Client::sending_thread_function, &Client::instance() );
	}

	{
		USock::instance().init( host().c_str(), port() );	
		std::string connection_string = "(init " + teamname() + "(version " + server_version() + ")";
		if( is_goalie() ) connection_string += "(goalie)";
		connection_string += ")\n";
		USock::instance().send( connection_string.c_str() );
	}

	bool queue_was_empty = true;
	while( true )
	{
		USock::instance().recv( M_buffer_in );

		if( strncmp( M_buffer_in, "(sense_body", 11 ) == 0 )
		{
			pthread_mutex_lock( &M_sending_cond_mutex );
			pthread_cond_signal( &M_sending_cond );
			pthread_mutex_unlock( &M_sending_cond_mutex );
		}

		pthread_mutex_lock( &M_message_queue_mutex );
		queue_was_empty = M_message_queue.empty();
		M_message_queue.push_back( M_buffer_in );
		pthread_mutex_unlock( &M_message_queue_mutex );

		if( queue_was_empty )
		{	
			pthread_mutex_lock( &M_process_activator_mutex );
			pthread_cond_signal( &M_process_activator );
			pthread_mutex_unlock( &M_process_activator_mutex );
		}
		
	}
}

void * Client::process_thread_function( void * arg )
{
	((Client *)arg)->process_f();
	return NULL;
}

void * Client::sending_thread_function( void * arg )
{
	((Client *)arg)->sending_f();
	return NULL;
}

void Client::process_f()
{
	char 	message_buffer[4096];
	bool 	queue_not_empty;	
	timespec server_timeout;
	struct timeval now;
	int 	rc;
	pthread_mutex_lock( &M_process_activator_mutex );
	while ( true ) 
	{
		gettimeofday( &now, NULL );
		server_timeout.tv_sec  = now.tv_sec + 5;
		server_timeout.tv_nsec = 0;
		rc = pthread_cond_timedwait( &M_process_activator, &M_process_activator_mutex,
								&server_timeout ); 
		if( rc == ETIMEDOUT )
		{
			Log::out( Log::INFO, "Server timed out\n" );
			_exit( 1 );
		}
		else
		{
			pthread_mutex_lock( &M_message_queue_mutex );
			queue_not_empty = !M_message_queue.empty();
			pthread_mutex_unlock( &M_message_queue_mutex );

			while( queue_not_empty )
			{
				pthread_mutex_lock( &M_message_queue_mutex );
				strcpy( message_buffer,	M_message_queue.front().c_str() );
			 	M_message_queue.pop_front();
				pthread_mutex_unlock( &M_message_queue_mutex );

				M_psbridge.parse( &message_buffer[0] );

				M_agent->think();

				pthread_mutex_lock( &M_command_mutex );
				M_commands.clear();
				for( std::list<Action*>::iterator it = M_agent->actuator().actions().begin();
					it != M_agent->actuator().actions().end(); ++it )
					M_commands.push_back( (*it)->cstr() );	
				pthread_mutex_unlock( &M_command_mutex );

				M_agent->actuator().actions().clear();	

				pthread_mutex_lock( &M_message_queue_mutex );
				queue_not_empty = !M_message_queue.empty();
				pthread_mutex_unlock( &M_message_queue_mutex );
			}
		}
	}
	pthread_mutex_unlock( &M_process_activator_mutex );
}


void Client::sending_f()
{
	std::vector<string> commands;
	std::vector<string>::const_iterator it;
	timespec wait_time;
	timespec reM_time;

	wait_time.tv_nsec = 70000000;
	wait_time.tv_sec  = 0;

	pthread_mutex_lock( &M_sending_cond_mutex );	
	while ( true )
	{
		pthread_cond_wait( &M_sending_cond, &M_sending_cond_mutex );
	
		nanosleep( &wait_time, &reM_time ); 
		commands.clear();

		pthread_mutex_lock( &M_command_mutex );
		for( std::list<std::string>::const_iterator it = M_commands.begin();
				it != M_commands.end(); it ++ )
				USock::instance().send( it->c_str() );
		pthread_mutex_unlock( &M_command_mutex );
			
		
	}
	pthread_mutex_unlock( &M_sending_cond_mutex );
}
    


void 
Client::signal_handler(int sig_num)
{
	Log::out( Log::INFO, 
		"Signal '%s' received. Finished.\n", strsignal(sig_num) );
	exit(0);
}
