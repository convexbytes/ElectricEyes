/*
 *        FILE: dummyagent.cpp
 *  Created on: July, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */


void 
DummyAgent::think()
{
	std::stringstream msg;
	msg << "Hi " << M_time;
	M_actuator.say( msg.str() );
}

void 
DummyAgent::on_init( Sensor::Init const & init )
{
	Log::out( Log::DEBUG, "Init\n" );
}


void 
DummyAgent::on_timechange( int cycle )
{
	Log::out( Log::DEBUG, "New cycle\n" );
	M_time = cycle;
}


void 
DummyAgent::on_body( Sensor::Body const & bodysense )
{
	Log::out( Log::DEBUG, "Body\n" );
}


void 
DummyAgent::on_see( Sensor::See const & see )
{
	Log::out( Log::DEBUG, "See\n" );
}


void 
DummyAgent::on_hear( Sensor::Hear const & hear )
{
	Log::out( Log::DEBUG, "Hear\n" );
}


void 
DummyAgent::on_ok( Sensor::Ok const & ok )
{
	Log::out( Log::DEBUG, "Ok\n" );
}


void 
DummyAgent::on_changeplayertype( Sensor::ChgPlayerType const & chpt )
{
	Log::out( Log::DEBUG, "CHPT\n" );
}


void 
DummyAgent::on_serverparam( Sensor::ServerParam const & sp )
{
	Log::out( Log::DEBUG, "ServerParam\n" );
}


void 
DummyAgent::on_playerparam( Sensor::PlayerParam const & pp )
{
	Log::out( Log::DEBUG, "PlayerParam\n" );
}


void 
DummyAgent::on_playertype( Sensor::PlayerType const & pt )
{
	Log::out( Log::DEBUG, "PlayerType\n" );
}


void 
DummyAgent::on_error( Sensor::Error const & err )
{
	Log::out( Log::DEBUG, "Error\n" );
}


void 
DummyAgent::on_warning( Sensor::Warning const & warn )
{
	Log::out( Log::DEBUG, "Warning #%d\n", (int)warn.type );
}


void 
DummyAgent::on_score( Sensor::Score const & score )
{
	Log::out( Log::DEBUG, "Score\n" );
}

