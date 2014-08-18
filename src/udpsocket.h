
#ifndef __UDPSocket_H__
#define __UDPSocket_H__

class USock
{
    USock();
public:
    ~USock();
    static USock & 	instance();
    void 			init ( const char *host, int port );
    int 			recv ( char * buffer ) ;
    int 			send ( const char * buffer );

private:
    bool        	M_is_initial_ok;
    sockaddr_in 	M_address;
    int 			M_sockfd;
};

#endif



