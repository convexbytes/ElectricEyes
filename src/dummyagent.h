/*
 *        FILE: dummyagent.h
 *  Created on: July, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

class DummyAgent : public Agent
{
public:
	virtual void think();
	virtual void on_init( Sensor::Init const & init ) ;
	virtual void on_timechange( int time ) ;
	virtual void on_body( Sensor::Body const & bodysense ) ;
	virtual void on_see( Sensor::See const & see ) ;
	virtual void on_hear( Sensor::Hear const & hear ) ;
	virtual void on_ok( Sensor::Ok const & ok ) ;
	virtual void on_changeplayertype( Sensor::ChgPlayerType const & chpt ) ;
	virtual void on_serverparam( Sensor::ServerParam const & sp ) ;
	virtual void on_playerparam( Sensor::PlayerParam const & pp ) ;
	virtual void on_playertype( Sensor::PlayerType const & pt ) ;
	virtual void on_error( Sensor::Error const & err ) ;
	virtual void on_warning( Sensor::Warning const & warn ) ;
	virtual void on_score( Sensor::Score const & score ) ;

private:
	int M_time;
};
