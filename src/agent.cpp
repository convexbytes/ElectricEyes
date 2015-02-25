/*
 *        FILE: agent.cpp
 *  Created on: July, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

using namespace Sensor;

Agent::Agent()
{
	M_teamname = "";
	M_unum = 0;
	M_goalie = false;
	M_serverversion = "";
	M_sign = "Unkown Agent";
}

Agent::~Agent()
{

}
std::string
Agent::teamname()
{
	return M_teamname;
}

int
Agent::unum()
{
	return M_unum;
}

bool
Agent::goalie()
{
	return M_goalie;
}

std::string
Agent::serverversion()
{
	return M_serverversion;
}

Actuator &
Agent::actuator()
{
	return M_actuator;
}

void
Agent::init( std::string teamname, int unum, bool goalie, 
	std::string serverversion )
{
	r_init( teamname, unum, goalie, serverversion );
}

void 
Agent::r_init( std::string teamname, int unum, bool goalie, 
	std::string serverversion )
{
	static bool not_initialized = true;

	if( not_initialized )
	{
		M_teamname      = teamname;
		M_unum          = unum;
		M_goalie        = goalie;
		M_serverversion = serverversion;
		std::stringstream sign; sign << teamname << " " << unum;
		M_sign          = sign.str();
		not_initialized = false;
	}
}