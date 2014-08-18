 /*
 *        FILE: main.cpp
 *  Created on: July, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

/*
 *   Last modified by: Gilberto Monroy Aguilar
 * Last modified date: July 2014
*/

void parse_args( int argc, char * argv[] );
void setup_agent();

int main( int argc, char * argv[] )
{
	parse_args( argc, argv );
	setup_agent();
	Client::instance().main_loop();
	return 0;
}

void parse_args( int argc, char * argv[] )
{
	if( argc != 7 )
	{
		fprintf( stderr, 
			"Invalid arguments.\n"
			"%s <server_version> <server_host> <server_port> <team_name> <unum> <is_goalie>\n", 
			argv[0] );
		exit(0);
	}


	Client::instance().set_server_version	( argv[1] );
	Client::instance().set_host				( argv[2] );
	Client::instance().set_port				( (unsigned)atoi(argv[3]) );
	Client::instance().set_teamname			( argv[4] );
	Client::instance().set_unum				( (unsigned)atoi(argv[5]) );
	Client::instance().set_is_goalie		( strcmp(argv[6],"true") == 0 ? true:false );
}

void setup_agent()
{
	// Any customization should be done in this function

	// We use a test agent.
	static DummyAgent agent;
	{

		Client::instance().set_agent( &agent );
	}
	
}