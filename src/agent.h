/*
 *        FILE: agent.h
 *  Created on: July, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

#ifndef AGENT_H
#define AGENT_H

class Agent : public Sensor::Handler
{

public:
	Agent();
	virtual ~Agent();
	virtual void think() = 0;
	void init( std::string teamname, int unum, bool goalie, 
				std::string serverversion );
	std::string teamname();
	int 		unum();
	bool 		goalie();
	std::string serverversion();
	Actuator & 	actuator();
	std::string sign();
private:
	void r_init(  std::string teamname, int unum, bool goalie, 
					std::string serverversion );
	std::string M_teamname;
	int 		M_unum;
	bool 		M_goalie;
	std::string M_serverversion;
	std::string M_sign;
protected:
	Actuator  	M_actuator;
};

#endif /* AGENT_H */
