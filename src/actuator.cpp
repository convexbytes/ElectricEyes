/*
 *        FILE: actuator.cpp
 *  Created on: July, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */


//------------------  KICK  --------------------//
Kick::Kick()
{
	set( 0, 0 );
}

Kick::Kick( double power, double direction )
{
	set( power, direction );
}

double 
Kick::power()
{
	return M_power;
}

double 
Kick::direction()
{
	return M_direction;
}

void 
Kick::set( double power, double direction )
{
	M_power = power;
	M_direction = direction;	
	update_string();
}

void 
Kick::update_string()
{
	if( M_direction )
		snprintf( M_string, ACTSTRMAXSIZE, KICKFORMAT1P, M_power );
	else
		snprintf( M_string, ACTSTRMAXSIZE, KICKFORMAT2P, M_power, M_direction );
} 

const char * 
Kick::cstr()
{
	return M_string;
} 


//------------------  DASH  --------------------//
Dash::Dash()
{
	set( 0, 0 );
}

Dash::Dash( double power, double direction )
{
	set( power, direction );
}

void
Dash::set( double power, double direction )
{
	M_power = power;
	M_direction = direction;	
	update_string();
}

void
Dash::update_string()
{
	if( M_direction )
		snprintf( M_string, ACTSTRMAXSIZE, DASHFORMAT1P, M_power );
	else
		snprintf( M_string, ACTSTRMAXSIZE, DASHFORMAT2P, M_power, M_direction );	
}

const char * 
Dash::cstr()
{
	return M_string;
} 


//------------------  TURN  --------------------//
Turn::Turn()
{

}
Turn::Turn( double dir )
{
	set( dir );
}

void 
Turn::set(double dir)
{
	M_direction = dir;
	update_string();
}

void
Turn::update_string()
{
	snprintf( M_string, ACTSTRMAXSIZE, TURNFORMAT1P, M_direction );
}

const char * 
Turn::cstr()
{
	return M_string;
}


//------------------  TURNNECK  --------------------//

TurnNeck::TurnNeck()
{

}

TurnNeck::TurnNeck( double dir )
{
	set( dir );
}

void 
TurnNeck::set(double dir)
{
	M_direction = dir;
	update_string();
}


void
TurnNeck::update_string()
{
	snprintf( M_string, ACTSTRMAXSIZE, TURNNECKFORMAT1P, M_direction );
}


const char * 
TurnNeck::cstr()
{
	return M_string;
}

//------------------  SAY  --------------------//
Say::Say()
{

}

Say::Say( std::string msg )
{
	set( msg );
}

Say::Say( const char * msg  )
{
	set( msg );
}

void 
Say::set( std::string msg )
{
	M_message.assign(msg);
	update_string();
}

void 
Say::set( const char * msg )
{
	M_message.assign(msg);
	update_string();
}

void
Say::update_string()
{
	snprintf( M_string, ACTSTRMAXSIZE, SAYFORMAT1P, M_message.c_str() );
}


const char * 
Say::cstr()
{
	return M_string;
}


//------------------  CATCH  --------------------//

Catch::Catch()
{

}

Catch::Catch( double dir )
{
	set( dir );
}

void 
Catch::set( double dir )
{
	M_direction = dir;
	update_string();
}


void
Catch::update_string()
{
	snprintf( M_string, ACTSTRMAXSIZE, CATCHFORMAT1P, M_direction );
}


const char * 
Catch::cstr()
{
	return M_string;
}


//------------------  CHANGEVIEW  --------------------//
ChangeView::ChangeView()
{
	set( Sensor::VIEWWIDTH_NORMAL, Sensor::VIEWQUALITY_HIGH );
}

ChangeView::ChangeView( Sensor::ViewWidth w, Sensor::ViewQuality q )
{
	set(w,q);
}

void
ChangeView::set( Sensor::ViewWidth w, Sensor::ViewQuality q )
{
	M_width = w; M_quality = q;
	update_string();
}

void
ChangeView::update_string()
{
	snprintf( M_string,  ACTSTRMAXSIZE, CHANGEVIEWFORMAT2P, 
		width_cstr(M_width), quality_cstr(M_quality) );
}

const char * 
ChangeView::width_cstr( Sensor::ViewWidth w )
{
	static const char * cstr_w[] = 
		{
			"narrow",
			"normal",
			"wide"
		};
	const char * str = 0;
	switch( w )
	{
		case Sensor::VIEWWIDTH_NARROW: str = cstr_w[0]; break;
		case Sensor::VIEWWIDTH_NORMAL: str = cstr_w[1]; break;
		case Sensor::VIEWWIDTH_WIDE: str = cstr_w[2]; break;
	}
	return str;
}

const char * 
ChangeView::quality_cstr( Sensor::ViewQuality q)
{
	static const char * cstr_q[] = 
		{
			"low",
			"high"
		};
	const char * str = 0;
	switch( q )
	{
		case Sensor::VIEWQUALITY_LOW: str = cstr_q[0]; break;
		case Sensor::VIEWQUALITY_HIGH: str = cstr_q[1]; break;
	}
	return str;
}


const char * 
ChangeView::cstr()
{
	return M_string;
}


//------------------  ATTENTIONNTO  --------------------//
AttentionTo::AttentionTo()
{
	set(1,false);
}

AttentionTo::AttentionTo(int unum, bool opp )
{
	set(unum,opp);
}

void
AttentionTo::set(int num, bool opp)
{
	M_unum = num; M_opp = opp;
	update_string();
}

void
AttentionTo::update_string()
{
	if( M_opp )
		snprintf( M_string, ACTSTRMAXSIZE, ATTENTIONTOFORMAT1A, M_unum );
	else
		snprintf( M_string, ACTSTRMAXSIZE, ATTENTIONTOFORMAT1B, M_unum );
}


const char * 
AttentionTo::cstr()
{
	return M_string;
}


//------------------  SCORE  --------------------//
Score::Score()
{

}

void
Score::update_string()
{
	snprintf( M_string, ACTSTRMAXSIZE,  SCOREFORMAT0P );
}


const char * 
Score::cstr()
{
	return M_string;
}



//------------------  SYNCHSEE  --------------------//
SynchSee::SynchSee()
{

}

void
SynchSee::update_string()
{
	snprintf( M_string, ACTSTRMAXSIZE, SYNCHSEEFORMAT0P  );
}


const char * 
SynchSee::cstr()
{
	return M_string;
}


//------------------  MOVE  --------------------//
Move::Move()
{
	M_x = M_y = 0;
}

Move::Move( double x, double y )
{
	set( x,y );
}

void
Move::set( double x, double y )
{
	M_x = x; M_y = y;
	update_string();
}

void
Move::update_string()
{
	snprintf( M_string, ACTSTRMAXSIZE, MOVEFORMAT2P, M_x, M_y );
}


const char * 
Move::cstr()
{
	return M_string;
}


//------------------  ACTUATOR  --------------------//
Actuator::Actuator()
{

}

Actuator::~Actuator()
{
	
}


void 
Actuator::kick( double power, double direction  )
{
	M_kick = Kick(power, direction);
	M_requests.push_back(&M_kick);
}

void 
Actuator::dash( double power, double direction  )
{
	M_dash = Dash(power, direction);
	M_requests.push_back(&M_dash);
}

void 
Actuator::turn( double dir )
{
	M_turn = Turn(dir);
	M_requests.push_back(&M_turn);
}

void 
Actuator::turnneck( double dir )
{
	M_turnneck = TurnNeck(dir);
	M_requests.push_back(&M_turnneck);
}

void 
Actuator::say( std::string msg )
{
	M_say = Say(msg);
	M_requests.push_back(&M_say);
}

void 
Actuator::say( const char * msg )
{
	M_say = Say(msg);
	M_requests.push_back(&M_say);
}

void 
Actuator::catchh()
{
	M_catch = Catch();
	M_requests.push_back(&M_catch);
}

void 
Actuator::changeview( Sensor::ViewWidth w, Sensor::ViewQuality q )
{
	M_changeview = ChangeView(w,q);
	M_requests.push_back(&M_changeview);
}

void 
Actuator::attentionto( int unum, bool opp )
{
	M_attentionto = AttentionTo(unum,opp);
	M_requests.push_back(&M_attentionto);
}

void 
Actuator::move( double x, double y )
{
	M_move = Move(x,y);
	M_requests.push_back(&M_move);
}

void 
Actuator::score( )
{
	M_score = Score();
	M_requests.push_back(&M_score);
}

void 
Actuator::synchsee( )
{
	M_synchsee = SynchSee();
	M_requests.push_back(&M_synchsee);
}


void
Actuator::clear()
{
	M_requests.clear();
}


std::list<Action *> & 
Actuator::actions()
{
	return M_requests;
}
