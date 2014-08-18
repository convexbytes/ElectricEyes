

USock::USock()
{
	M_is_initial_ok = false;
}


USock::~USock()
{
}


USock & USock::instance()
{
    static USock u_sock;
    return u_sock;
}

void USock::init( const char *host, int port)
{
	struct hostent *host_ent ;
	struct in_addr *addr_ptr ;
    
    host_ent = (struct hostent *)gethostbyname(host);
	if ( (host_ent == 0) )
	{
		if (inet_addr(host) == INADDR_NONE)
			printf("Invalid host name \n");
	}
	else
	{
		addr_ptr = (struct in_addr *) *host_ent->h_addr_list ;
		host = inet_ntoa(*addr_ptr) ;
	}
    
	M_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if( (M_sockfd) < 0)
	{
		printf("Can't create socket \n") ;
	}

	memset(&M_address, 0, sizeof(M_address)) ;
	M_address.sin_family      = AF_INET ;
	M_address.sin_addr.s_addr = htonl(INADDR_ANY) ;
	M_address.sin_port        = htons(0) ;

	if(bind(M_sockfd, (sockaddr *)&M_address, sizeof(M_address)) < 0)
	{
		close(M_sockfd);

		printf("Can't bind client to any port \n");
	}

	memset(&M_address, 0, sizeof(M_address)) ;
	M_address.sin_family      = AF_INET ;
	M_address.sin_addr.s_addr = inet_addr( host ) ;
	M_address.sin_port        = htons( port ) ;
	M_is_initial_ok           = true;
}

int USock::recv(char *buffer)
{
	socklen_t 	servlen ;
	sockaddr_in serv_addr;
    
	servlen = sizeof(serv_addr);
	int n   = recvfrom(M_sockfd, buffer, 4096, 0, (sockaddr *)&serv_addr, &servlen);
	if (n > 0)
	{
		M_address.sin_port = serv_addr.sin_port ;
	}

	return n ;
}

int USock::send(const char *buffer)
{
	if (M_is_initial_ok == true)
	{
		int n = std::strlen(buffer) ;
		n     = sendto(M_sockfd, buffer, n+1, MSG_EOR, (sockaddr *)&M_address, sizeof(M_address));
		return n;
	}

	return std::strlen(buffer);
}
