 /*
 *        FILE: client.cpp
 *  Created on: June, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

#ifndef CLIENT_H
#define CLIENT_H

#define SERVER_MAX_DELAY_SECS 3


class Client
{
private:
    Client();
public:
	~Client();
    static Client &         instance();
    void                    set_host( std::string const & host );
    void                    set_port( unsigned port );
    void                    set_server_version( std::string const & version );
    void                    set_teamname( std::string const & teamname );
    void                    set_unum( unsigned unum );
    void                    set_is_goalie( bool goalie );

    void                    set_agent( Agent * agent );

    void                    reg_sensorhandler( );
    void                    reg_driver( ClientParser::Driver * driver  );


    void                    main_loop();

    std::string const &     host();
    unsigned                port();
    std::string const &     server_version();
    std::string const &     teamname();
    unsigned                unum();
    bool                    is_goalie();
    static void             signal_handler( int signum );

private: 
    static void *           process_thread_function( void * arg );
    static void *           sending_thread_function( void * arg );
    void                    process_f();
    void                    sending_f();

    static Client          *M_instance;
    char                    M_buffer_in[4096];
    Agent                   *M_agent;
    std::list<std::string>  M_commands;
    std::deque<std::string> M_message_queue;

    pthread_mutex_t         M_message_queue_mutex;
    pthread_mutex_t         M_command_mutex;
    pthread_t               M_process_thread;
    pthread_t               M_sending_thread;
    pthread_cond_t   	    M_sending_cond;
    pthread_mutex_t		    M_sending_cond_mutex;
    pthread_cond_t 		    M_queue_cond;
    pthread_mutex_t 	    M_queue_cond_mutex;
    pthread_cond_t          M_process_activator;
    pthread_mutex_t         M_process_activator_mutex;

    PSBridge                M_psbridge;

    bool                    M_active;
    std::string             M_host;
    unsigned                M_port;
    std::string             M_server_version;
    std::string             M_teamname;
    unsigned                M_unum;
    bool                    M_is_goalie;
};


#endif

