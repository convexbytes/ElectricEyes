/*
 *        FILE: actuator.h
 *  Created on: July, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

#ifndef ACTUATOR_H
#define ACTUATOR_H


#define ACTSTRMAXSIZE 50
#define KICKFORMAT1P "(kick %.2f)"
#define KICKFORMAT2P "(kick %.2f %.2f)"
#define DASHFORMAT1P "(dash %.2f)"
#define DASHFORMAT2P "(dash %.2f %.2f)"
#define TURNFORMAT1P "(turn %.2f)"
#define TURNNECKFORMAT1P "(turn_neck %.2f)"
#define SAYFORMAT1P "(say %s)"
#define CATCHFORMAT1P "(catch %.2f)"
#define CHANGEVIEWFORMAT2P "(change_view %s %s)"
#define ATTENTIONTOFORMAT1A "(attentionto %d our)"
 #define ATTENTIONTOFORMAT1B "(attentionto %d opp)"
#define MOVEFORMAT2P "(move %.2f %.2f)"
#define SCOREFORMAT0P "(score)" 
#define SYNCHSEEFORMAT0P "(synch_see)"



class Action
{
public:
	virtual const char * cstr() = 0;
protected:
};


class Kick : public Action
{
public:
	Kick();
	Kick( double power, double direction = 0);
	virtual const char * cstr();
	double power();
	double direction();
	void set( double power, double direction = 0 );
	void update_string();
protected:
	double M_power;
	double M_direction;
	char  M_string[ACTSTRMAXSIZE];
};


class Dash : public Action
{
public:
	Dash();
	Dash( double power, double direction  = 0 );
	virtual const char * cstr();
	double power();
	double direction();
	void set( double power, double direction = 0 );
	void update_string();
protected:
	double M_power;
	double M_direction;
	char  M_string[ACTSTRMAXSIZE];
};


class Turn : public Action
{
public:
	Turn();
	Turn( double dir );
	virtual const char * cstr();
	void update_string();
	double 	direction();
	void set(double dir);
protected:
	double M_direction;
	char  M_string[ACTSTRMAXSIZE];
};


class TurnNeck: public Action
{
public:
	TurnNeck();
	TurnNeck( double dir );
	virtual const char * cstr();
	void update_string();
	void set(double dir);
	double direction();
protected:
	double M_direction;
	char  M_string[ACTSTRMAXSIZE];
};


class Say : public Action
{
public:
	Say();
	Say( std::string msg );
	Say( const char * msg  );
	virtual const char * cstr();
	void set( const char * msg );
	void set( std::string msg );
	void update_string();
	std::string message();
protected:
	std::string M_message;
	char  M_string[ACTSTRMAXSIZE];
};


class Catch : public Action
{
public:
	Catch();
	Catch( double dir );
	virtual const char * cstr();
	void update_string();
	void set( double dir );
	double direction();
protected:
	double M_direction;
	char  M_string[ACTSTRMAXSIZE];
};


class ChangeView : public Action
{
public:
	ChangeView();
	ChangeView( Sensor::ViewWidth w, Sensor::ViewQuality q );
	virtual const char * cstr();
	void set( Sensor::ViewWidth w, Sensor::ViewQuality q );
	void update_string();
	Sensor::ViewWidth width();
	Sensor::ViewQuality quality();
	static const char * width_cstr( Sensor::ViewWidth w );
	static const char * quality_cstr( Sensor::ViewQuality q);
protected:
	Sensor::ViewWidth M_width;
	Sensor::ViewQuality M_quality;
	char  M_string[ACTSTRMAXSIZE];
};


class AttentionTo : public Action
{
public:
	AttentionTo();
	AttentionTo(int unum, bool opp );
	virtual const char * cstr();
	void update_string();
	void set( int unum, bool opp );
	int unum();
	Sensor::Side side();
protected:
	int M_unum;
	bool M_opp;
	char  M_string[ACTSTRMAXSIZE];
};


class Move : public Action
{
public:
	Move();
	Move( double x, double y );
	virtual const char * cstr();
	void update_string();
	void set( double x, double y );
	double x();
	double y();
protected:
	double M_x;
	double M_y;
	char  M_string[ACTSTRMAXSIZE];
};


class Score : public Action
{
public:
	Score();
	virtual const char * cstr();
	void update_string();
protected:
	char  M_string[ACTSTRMAXSIZE];
};


class SynchSee: public Action
{
public:
	SynchSee();
	virtual const char * cstr();
	void update_string();
protected:
	char  M_string[ACTSTRMAXSIZE];
};


class Actuator
{
public:
	Actuator();
	~Actuator();
	std::list<Action *> & actions();
	void clear();

	void kick( double power, double direction = 0 );
	void dash( double power, double direction = 0 );
	void turn( double dir );
	void turnneck( double dir );
	void say( std::string msg );
	void say( const char * msg );
	void catchh();
	void changeview( Sensor::ViewWidth w, Sensor::ViewQuality q );
	void attentionto( int unum, bool opp );
	void move( double x, double y );
	void score();
	void synchsee();

protected:
	std::list<Action *> M_requests;
	Kick 		M_kick;
	Dash 		M_dash;
	Turn 		M_turn;
	TurnNeck	M_turnneck;
	Say			M_say;
	Catch	 	M_catch;
	ChangeView	M_changeview;
	AttentionTo	M_attentionto;
	Move	 	M_move;
	Score	 	M_score;
	SynchSee	M_synchsee;
};


#endif