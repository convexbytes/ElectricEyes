/*
 *        FILE: sensor.cpp
 *  Created on: July, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

namespace Sensor
{

double FLAG_COORD[][2]
 = {{0, 39},
	{-10, 39},
	{-20, 39},
	{-30, 39},
	{-40, 39},
	{-50, 39},
	{10, 39},
	{20, 39},
	{30, 39},
	{40, 39},
	{50, 39},
	{0, 0},
	{0, 34},
	{0, -34},
	{-52.5, 7},
	{-52.5, -7},
	{52.5, 7},
	{52.5, -7},
	{-57.5, 0},
	{-57.5, 10},
	{-57.5, 20},
	{-57.5, 30},
	{-52.5, 34},
	{-57.5, -10},
	{-57.5, -20},
	{-57.5, -30},
	{-52.5, -34},
	{-36, 20},
	{-36, 0},
	{-36, -20},
	{36, 20},
	{36, 0},
	{36, -20},
	{57.5, 0},
	{57.5, 10},
	{57.5, 20},
	{57.5, 30},
	{52.5, 34},
	{57.5, -10},
	{57.5, -20},
	{57.5, -30},
	{52.5, -34},
	{0, -39},
	{-10, -39},
	{-20, -39},
	{-30, -39},
	{-40, -39},
	{-50, -39},
	{10, -39},
	{20, -39},
	{30, -39},
	{40, -39},
	{50, -39},
	{-52.5, 0},
	{52.5, 0},
	{NDEF_NUM, NDEF_NUM },
	{NDEF_NUM, NDEF_NUM }
	};


Hear::Hear()
{
	message = NDEF_STR;
	unum = NDEF_NUM;
	dir = NDEF_NUM;
	goals = NDEF_NUM;
	cards = NDEF_NUM;
}

RefereeEvent
from_PM_to_RE( Playmode pm )
{
	switch( pm )
	{
		case PM_NULL: return PMH_NULL; 
		case PM_BEFORE_KICK_OFF: return PMH_BEFORE_KICK_OFF; 
		case PM_TIME_OVER: return PMH_TIME_OVER; 
		case PM_PLAY_ON: return PMH_PLAY_ON; 
		case PM_KICK_OFF_L: return PMH_KICK_OFF_L; 
		case PM_KICK_OFF_R: return PMH_KICK_OFF_R; 
		case PM_KICK_IN_L: return PMH_KICK_IN_L; 
		case PM_KICK_IN_R: return PMH_KICK_IN_R; 
		case PM_FREE_KICK_L: return PMH_FREE_KICK_L; 
		case PM_FREE_KICK_R: return PMH_FREE_KICK_R; 
		case PM_CORNER_KICK_L: return PMH_CORNER_KICK_L; 
		case PM_CORNER_KICK_R: return PMH_CORNER_KICK_R; 
		case PM_GOAL_KICK_L: return PMH_GOAL_KICK_L; 
		case PM_GOAL_KICK_R: return PMH_GOAL_KICK_R; 
		case PM_GOAL_L: return PMH_GOAL_L; 
		case PM_GOAL_R: return PMH_GOAL_R; 
		case PM_DROP_BALL: return PMH_DROP_BALL; 
		case PM_OFFSIDE_L: return PMH_OFFSIDE_L; 
		case PM_OFFSIDE_R: return PMH_OFFSIDE_R; 
		case PM_PENALTY_KICK_L: return PMH_PENALTY_KICK_L; 
		case PM_PENALTY_KICK_R: return PMH_PENALTY_KICK_R; 
		case PM_FIRST_HALF_OVER: return PMH_FIRST_HALF_OVER; 
		case PM_PAUSE: return PMH_PAUSE; 
		case PM_HUMAN_JUDGE: return PMH_HUMAN_JUDGE; 
		case PM_FOUL_CHARGE_L: return PMH_FOUL_CHARGE_L; 
		case PM_FOUL_CHARGE_R: return PMH_FOUL_CHARGE_R; 
		case PM_FOUL_PUSH_L: return PMH_FOUL_PUSH_L; 
		case PM_FOUL_PUSH_R: return PMH_FOUL_PUSH_R; 
		case PM_FOUL_MULTIPLE_ATTACK_L: return PMH_FOUL_MULTIPLE_ATTACK_L; 
		case PM_FOUL_MULTIPLE_ATTACK_R: return PMH_FOUL_MULTIPLE_ATTACK_R; 
		case PM_FOUL_BALLOUT_L: return PMH_FOUL_BALLOUT_L; 
		case PM_FOUL_BALLOUT_R: return PMH_FOUL_BALLOUT_R; 
		case PM_BACK_PASS_L: return PMH_BACK_PASS_L; 
		case PM_BACK_PASS_R: return PMH_BACK_PASS_R; 
		case PM_FREE_KICK_FAULT_L: return PMH_FREE_KICK_FAULT_L; 
		case PM_FREE_KICK_FAULT_R: return PMH_FREE_KICK_FAULT_R; 
		case PM_CATCH_FAULT_L: return PMH_CATCH_FAULT_L; 
		case PM_CATCH_FAULT_R: return PMH_CATCH_FAULT_R; 
		case PM_INDIRECT_FREE_KICK_L: return PMH_INDIRECT_FREE_KICK_L; 
		case PM_INDIRECT_FREE_KICK_R: return PMH_INDIRECT_FREE_KICK_R; 
		case PM_PENALTY_SETUP_L: return PMH_PENALTY_SETUP_L; 
		case PM_PENALTY_SETUP_R: return PMH_PENALTY_SETUP_R; 
		case PM_PENALTY_READY_L: return PMH_PENALTY_READY_L; 
		case PM_PENALTY_READY_R: return PMH_PENALTY_READY_R; 
		case PM_PENALTY_TAKEN_L: return PMH_PENALTY_TAKEN_L; 
		case PM_PENALTY_TAKEN_R: return PMH_PENALTY_TAKEN_R; 
		case PM_PENALTY_MISS_L: return PMH_PENALTY_MISS_L; 
		case PM_PENALTY_MISS_R: return PMH_PENALTY_MISS_R; 
		case PM_PENALTY_SCORE_L: return PMH_PENALTY_SCORE_L; 
		case PM_PENALTY_SCORE_R: return PMH_PENALTY_SCORE_R; 
		default: return PMH_NULL;
	}
}


double
Flag::x()
{
	if( (int)id >= 0 && (int)id <= FLAG_UNKOWN )
		return FLAG_COORD[ this->id ][0];
	else
		return NDEF_NUM;
}

double 
Flag::y()
{
	if( (int)id >= 0 && (int)id <= FLAG_UNKOWN )
		return FLAG_COORD[ this->id ][1];
	else
		return NDEF_NUM;
}


} // namespace Sensor