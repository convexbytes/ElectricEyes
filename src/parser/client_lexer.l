%{

/************************************************************/
/*	Author:			Gilberto Monroy Aguilar					*/
/*	Creation date: 	Monday 09-Dec-2013						*/
/*	Purpose: 		Lexical definition	and				 	*/
/*					lexer configuration						*/
/*															*/
/************************************************************/

/* Avoid double backslash comments on this file 				*/
/* because it may cause problems with bison or flex  			*/


/* This code is made for version 2.5.35. 						*/
/* However, if you want to compile it using prior versions,  	*/
/* keep in mind the next bug: 									*/

/* Work around an incompatibility in flex (at least versions 	*/
/* 2.5.31 through 2.5.33): it generates code that does			*/
/* not conform to C89. See Debian bug 333231					*/
/* <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.	*/
/*# undef yywrap												*/
/*# define yywrap() 1											*/


#include <cstdio>
#include "client_parser.tab.hh"
#include "client_parser_driver.h"

static yy::location loc;		/* The location of the current token */

%}

%option noyywrap 
%option batch 

%option nounput
%option noinput 

%{


%}

%%

%{

%}

\"[^\"\n\r]*\" 	{  
	char * str = yytext+1; /* Remove the first quotes */
	char * second_quote_pos = strchr( str, '\"' ); /* Find the second quotes*/
	*second_quote_pos = '\0'; /* Remove the second quotes*/
	return yy::RcssParser::make_STRING(str, loc); 
	}
'[^'\n\r]*' {  
	char * str = yytext+1; /* Remove the first single quote */
	char * second_quote_pos = strchr( str, '\'' ); /* Find the second quote*/
	*second_quote_pos = '\0'; /* Remove the second quote*/
	return yy::RcssParser::make_STRING(str, loc); 
	}
[ \t\n\r]+  			{  loc.step (); /* skip white characters */ }
"(" 					{  return yy::RcssParser::make_LP(loc); }
")"						{  return yy::RcssParser::make_RP(loc); }
[-+]?[0-9]+(\.[0-9]+)?(e[-+]?[0-9]+)? {  double n = strtod( yytext, NULL );
							return yy::RcssParser::make_NUMBER(n, loc); }
"l"						{  return yy::RcssParser::make_LEFT(loc); }
"r"						{  return yy::RcssParser::make_RIGHT(loc); }
"init" 					{  return yy::RcssParser::make_INIT(loc); }
"server_param" 			{  return yy::RcssParser::make_SERVER_PARAM(loc); }
"player_param" 			{  return yy::RcssParser::make_PLAYER_PARAM(loc); }
"player_type" 			{  return yy::RcssParser::make_PLAYER_TYPE(loc); }
"sense_body" 			{  return yy::RcssParser::make_BODY(loc); }
"see" 					{  return yy::RcssParser::make_SEE(loc); }
"hear" 					{  return yy::RcssParser::make_HEAR(loc); }
"error" 				{  return yy::RcssParser::make_ERROR(loc); } 
"score" 				{  return yy::RcssParser::make_SCORE(loc); }
"warning"				{  return yy::RcssParser::make_WARNING(loc); }
"ok"					{ return yy::RcssParser::make_OK(loc); }
"change_player_type"	{ return yy::RcssParser::make_CHANGE_PLAYER_TYPE(loc); }

"audio_cut_dist"	  	{ return yy::RcssParser::make_AUDIO_CUT_DIST(loc); }
"auto_mode"	  			{ return yy::RcssParser::make_AUTO_MODE(loc); }
"back_dash_rate"	  	{ return yy::RcssParser::make_BACK_DASH_RATE(loc); }
"back_passes"	  		{ return yy::RcssParser::make_BACK_PASSES(loc); }
"ball_accel_max"	  	{ return yy::RcssParser::make_BALL_ACCEL_MAX(loc); }
"ball_decay"  			{ return yy::RcssParser::make_BALL_DECAY(loc); }
"ball_rand"	  			{ return yy::RcssParser::make_BALL_RAND(loc); }
"ball_size"	  			{ return yy::RcssParser::make_BALL_SIZE(loc); }
"ball_speed_max"	  	{ return yy::RcssParser::make_BALL_SPEED_MAX(loc); }
"ball_stuck_area"	  	{ return yy::RcssParser::make_BALL_STUCK_AREA(loc); }
"ball_weight"	  		{ return yy::RcssParser::make_BALL_WEIGHT(loc); }
"catch_ban_cycle"  		{ return yy::RcssParser::make_CATCH_BAN_CYCLE(loc); }
"catch_probability"  	{ return yy::RcssParser::make_CATCH_PROBABILITY(loc); }
"catchable_area_l"  	{ return yy::RcssParser::make_CATCHABLE_AREA_L(loc); }
"catchable_area_w"  	{ return yy::RcssParser::make_CATCHABLE_AREA_W(loc); }
"ckick_margin"  		{ return yy::RcssParser::make_CKICK_MARGIN(loc); }
"clang_advice_win"  	{ return yy::RcssParser::make_CLANG_ADVICE_WIN(loc); }
"clang_define_win"  	{ return yy::RcssParser::make_CLANG_DEFINE_WIN(loc); }
"clang_del_win"  		{ return yy::RcssParser::make_CLANG_DEL_WIN(loc); }
"clang_info_win"  		{ return yy::RcssParser::make_CLANG_INFO_WIN(loc); }
"clang_mess_delay"  	{ return yy::RcssParser::make_CLANG_MESS_DELAY(loc); }
"clang_mess_per_cycle"  { return yy::RcssParser::make_CLANG_MESS_PER_CYCLE(loc); }
"clang_meta_win"  		{ return yy::RcssParser::make_CLANG_META_WIN(loc); }
"clang_rule_win"  		{ return yy::RcssParser::make_CLANG_RULE_WIN(loc); }
"clang_win_size"  		{ return yy::RcssParser::make_CLANG_WIN_SIZE(loc); }
"coach"  				{ return yy::RcssParser::make_COACH(loc); }
"coach_port"  			{ return yy::RcssParser::make_COACH_PORT(loc); }
"coach_w_referee"  		{ return yy::RcssParser::make_COACH_W_REFEREE(loc); }
"connect_wait"  		{ return yy::RcssParser::make_CONNECT_WAIT(loc); }
"control_radius"  		{ return yy::RcssParser::make_CONTROL_RADIUS(loc); }
"dash_angle_step"  		{ return yy::RcssParser::make_DASH_ANGLE_STEP(loc); }
"dash_power_rate"  		{ return yy::RcssParser::make_DASH_POWER_RATE(loc); }
"drop_ball_time"  		{ return yy::RcssParser::make_DROP_BALL_TIME(loc); }
"effort_dec"  			{ return yy::RcssParser::make_EFFORT_DEC(loc); }
"effort_dec_thr"  		{ return yy::RcssParser::make_EFFORT_DEC_THR(loc); }
"effort_inc"  			{ return yy::RcssParser::make_EFFORT_INC(loc); }
"effort_inc_thr"  		{ return yy::RcssParser::make_EFFORT_INC_THR(loc); }
"effort_init"  			{ return yy::RcssParser::make_EFFORT_INIT(loc); }
"effort_min"  			{ return yy::RcssParser::make_EFFORT_MIN(loc); }
"extra_half_time"  		{ return yy::RcssParser::make_EXTRA_HALF_TIME(loc); }
"extra_stamina"  		{ return yy::RcssParser::make_EXTRA_STAMINA(loc); }
"forbid_kick_off_offside"  { return yy::RcssParser::make_FORBID_KICK_OFF_OFFSIDE(loc); }
"foul_cycles"  			{ return yy::RcssParser::make_FOUL_CYCLES(loc); }
"foul_detect_probability"  { return yy::RcssParser::make_FOUL_DETECT_PROBABILITY(loc); }
"foul_exponent"  		{ return yy::RcssParser::make_FOUL_EXPONENT(loc); }
"free_kick_faults"  	{ return yy::RcssParser::make_FREE_KICK_FAULTS(loc); }
"freeform_send_period"  { return yy::RcssParser::make_FREEFORM_SEND_PERIOD(loc); }
"freeform_wait_period"  { return yy::RcssParser::make_FREEFORM_WAIT_PERIOD(loc); }
"fullstate_l"  			{ return yy::RcssParser::make_FULLSTATE_L(loc); }
"fullstate_r"  			{ return yy::RcssParser::make_FULLSTATE_R(loc); }
"game_log_compression"  { return yy::RcssParser::make_GAME_LOG_COMPRESSION(loc); }
"game_log_dated"  		{ return yy::RcssParser::make_GAME_LOG_DATED(loc); }
"game_log_dir"  		{ return yy::RcssParser::make_GAME_LOG_DIR(loc); }
"game_log_fixed"  		{ return yy::RcssParser::make_GAME_LOG_FIXED(loc); }
"game_log_fixed_name"  	{ return yy::RcssParser::make_GAME_LOG_FIXED_NAME(loc); }
"game_log_version"  	{ return yy::RcssParser::make_GAME_LOG_VERSION(loc); }
"game_logging"  		{ return yy::RcssParser::make_GAME_LOGGING(loc); }
"game_over_wait"  		{ return yy::RcssParser::make_GAME_OVER_WAIT(loc); }
"goal_width"  			{ return yy::RcssParser::make_GOAL_WIDTH(loc); }
"goalie_max_moves"  	{ return yy::RcssParser::make_GOALIE_MAX_MOVES(loc); }
"golden_goal"  			{ return yy::RcssParser::make_GOLDEN_GOAL(loc); }
"half_time"  			{ return yy::RcssParser::make_HALF_TIME(loc); }
"hear_decay"  			{ return yy::RcssParser::make_HEAR_DECAY(loc); }
"hear_inc"  			{ return yy::RcssParser::make_HEAR_INC(loc); }
"hear_max"  			{ return yy::RcssParser::make_HEAR_MAX(loc); }
"inertia_moment"  		{ return yy::RcssParser::make_INERTIA_MOMENT(loc); }
"keepaway"  			{ return yy::RcssParser::make_KEEPAWAY(loc); }
"keepaway_length"  		{ return yy::RcssParser::make_KEEPAWAY_LENGTH(loc); }
"keepaway_log_dated"  	{ return yy::RcssParser::make_KEEPAWAY_LOG_DATED(loc); }
"keepaway_log_dir"  	{ return yy::RcssParser::make_KEEPAWAY_LOG_DIR(loc); }
"keepaway_log_fixed"  	{ return yy::RcssParser::make_KEEPAWAY_LOG_FIXED(loc); }
"keepaway_log_fixed_name"  { return yy::RcssParser::make_KEEPAWAY_LOG_FIXED_NAME(loc); }
"keepaway_logging"  	{ return yy::RcssParser::make_KEEPAWAY_LOGGING(loc); }
"keepaway_start"  		{ return yy::RcssParser::make_KEEPAWAY_START(loc); }
"keepaway_width"  		{ return yy::RcssParser::make_KEEPAWAY_WIDTH(loc); }
"kick_off_wait"  		{ return yy::RcssParser::make_KICK_OFF_WAIT(loc); }
"kick_power_rate"  		{ return yy::RcssParser::make_KICK_POWER_RATE(loc); }
"kick_rand"  			{ return yy::RcssParser::make_KICK_RAND(loc); }
"kick_rand_factor_l"  	{ return yy::RcssParser::make_KICK_RAND_FACTOR_L(loc); }
"kick_rand_factor_r"  	{ return yy::RcssParser::make_KICK_RAND_FACTOR_R(loc); }
"kickable_margin"  		{ return yy::RcssParser::make_KICKABLE_MARGIN(loc); }
"landmark_file"  		{ return yy::RcssParser::make_LANDMARK_FILE(loc); }
"log_date_format"  		{ return yy::RcssParser::make_LOG_DATE_FORMAT(loc); }
"log_times"  			{ return yy::RcssParser::make_LOG_TIMES(loc); }
"max_back_tackle_power" { return yy::RcssParser::make_MAX_BACK_TACKLE_POWER(loc); }
"max_dash_angle"  		{ return yy::RcssParser::make_MAX_DASH_ANGLE(loc); }
"max_dash_power"  		{ return yy::RcssParser::make_MAX_DASH_POWER(loc); }
"max_goal_kicks"  		{ return yy::RcssParser::make_MAX_GOAL_KICKS(loc); }
"max_tackle_power"  	{ return yy::RcssParser::make_MAX_TACKLE_POWER(loc); }
"maxmoment"  			{ return yy::RcssParser::make_MAXMOMENT(loc); }
"maxneckang"  			{ return yy::RcssParser::make_MAXNECKANG(loc); }
"maxneckmoment"  		{ return yy::RcssParser::make_MAXNECKMOMENT(loc); }
"maxpower"  			{ return yy::RcssParser::make_MAXPOWER(loc); }
"min_dash_angle"  		{ return yy::RcssParser::make_MIN_DASH_ANGLE(loc); }
"min_dash_power"  		{ return yy::RcssParser::make_MIN_DASH_POWER(loc); }
"minmoment"  			{ return yy::RcssParser::make_MINMOMENT(loc); }
"minneckang"  			{ return yy::RcssParser::make_MINNECKANG(loc); }
"minneckmoment"  		{ return yy::RcssParser::make_MINNECKMOMENT(loc); }
"minpower"  			{ return yy::RcssParser::make_MINPOWER(loc); }
"nr_extra_halfs"  		{ return yy::RcssParser::make_NR_EXTRA_HALFS(loc); }
"nr_normal_halfs"  		{ return yy::RcssParser::make_NR_NORMAL_HALFS(loc); }
"offside_active_area_size"  { return yy::RcssParser::make_OFFSIDE_ACTIVE_AREA_SIZE(loc); }
"offside_kick_margin"  	{ return yy::RcssParser::make_OFFSIDE_KICK_MARGIN(loc); }
"olcoach_port"  		{ return yy::RcssParser::make_OLCOACH_PORT(loc); }
"old_coach_hear"  		{ return yy::RcssParser::make_OLD_COACH_HEAR(loc); }
"pen_allow_mult_kicks"  { return yy::RcssParser::make_PEN_ALLOW_MULT_KICKS(loc); }
"pen_before_setup_wait"  { return yy::RcssParser::make_PEN_BEFORE_SETUP_WAIT(loc); }
"pen_coach_moves_players"  { return yy::RcssParser::make_PEN_COACH_MOVES_PLAYERS(loc); }
"pen_dist_x"  			{ return yy::RcssParser::make_PEN_DIST_X(loc); }
"pen_max_extra_kicks"  	{ return yy::RcssParser::make_PEN_MAX_EXTRA_KICKS(loc); }
"pen_max_goalie_dist_x" { return yy::RcssParser::make_PEN_MAX_GOALIE_DIST_X(loc); }
"pen_nr_kicks"  		{ return yy::RcssParser::make_PEN_NR_KICKS(loc); }
"pen_random_winner"  	{ return yy::RcssParser::make_PEN_RANDOM_WINNER(loc); }
"pen_ready_wait"  		{ return yy::RcssParser::make_PEN_READY_WAIT(loc); }
"pen_setup_wait"  		{ return yy::RcssParser::make_PEN_SETUP_WAIT(loc); }
"pen_taken_wait"  		{ return yy::RcssParser::make_PEN_TAKEN_WAIT(loc); }
"penalty_shoot_outs"  	{ return yy::RcssParser::make_PENALTY_SHOOT_OUTS(loc); }
"player_accel_max"  	{ return yy::RcssParser::make_PLAYER_ACCEL_MAX(loc); }
"player_decay"  		{ return yy::RcssParser::make_PLAYER_DECAY(loc); }
"player_rand"  			{ return yy::RcssParser::make_PLAYER_RAND(loc); }
"player_size"  			{ return yy::RcssParser::make_PLAYER_SIZE(loc); }
"player_speed_max"  	{ return yy::RcssParser::make_PLAYER_SPEED_MAX(loc); }
"player_speed_max_min"  { return yy::RcssParser::make_PLAYER_SPEED_MAX_MIN(loc); }
"player_weight"  		{ return yy::RcssParser::make_PLAYER_WEIGHT(loc); }
"point_to_ban"  		{ return yy::RcssParser::make_POINT_TO_BAN(loc); }
"point_to_duration"  	{ return yy::RcssParser::make_POINT_TO_DURATION(loc); }
"port"  				{ return yy::RcssParser::make_PORT(loc); }
"prand_factor_l"  		{ return yy::RcssParser::make_PRAND_FACTOR_L(loc); }
"prand_factor_r"  		{ return yy::RcssParser::make_PRAND_FACTOR_R(loc); }
"profile"  				{ return yy::RcssParser::make_PROFILE(loc); }
"proper_goal_kicks"  	{ return yy::RcssParser::make_PROPER_GOAL_KICKS(loc); }
"quantize_step"  		{ return yy::RcssParser::make_QUANTIZE_STEP(loc); }
"quantize_step_l"  		{ return yy::RcssParser::make_QUANTIZE_STEP_L(loc); }
"record_messages"  		{ return yy::RcssParser::make_RECORD_MESSAGES(loc); }
"recover_dec"  			{ return yy::RcssParser::make_RECOVER_DEC(loc); }
"recover_dec_thr"  		{ return yy::RcssParser::make_RECOVER_DEC_THR(loc); }
"recover_init"  		{ return yy::RcssParser::make_RECOVER_INIT(loc); }
"recover_min"  			{ return yy::RcssParser::make_RECOVER_MIN(loc); }
"recv_step"  			{ return yy::RcssParser::make_RECV_STEP(loc); }
"red_card_probability"  { return yy::RcssParser::make_RED_CARD_PROBABILITY(loc); }
"say_coach_cnt_max"  	{ return yy::RcssParser::make_SAY_COACH_CNT_MAX(loc); }
"say_coach_msg_size"  	{ return yy::RcssParser::make_SAY_COACH_MSG_SIZE(loc); }
"say_msg_size"  		{ return yy::RcssParser::make_SAY_MSG_SIZE(loc); }
"send_comms"  			{ return yy::RcssParser::make_SEND_COMMS(loc); }
"send_step"  			{ return yy::RcssParser::make_SEND_STEP(loc); }
"send_vi_step"  		{ return yy::RcssParser::make_SEND_VI_STEP(loc); }
"sense_body_step"  		{ return yy::RcssParser::make_SENSE_BODY_STEP(loc); }
"side_dash_rate"  		{ return yy::RcssParser::make_SIDE_DASH_RATE(loc); }
"simulator_step"  		{ return yy::RcssParser::make_SIMULATOR_STEP(loc); }
"slow_down_factor"  	{ return yy::RcssParser::make_SLOW_DOWN_FACTOR(loc); }
"slowness_on_top_for_left_team"  { return yy::RcssParser::make_SLOWNESS_ON_TOP_FOR_LEFT_TEAM(loc); }
"slowness_on_top_for_right_team"  { return yy::RcssParser::make_SLOWNESS_ON_TOP_FOR_RIGHT_TEAM(loc); }
"stamina_capacity"  	{ return yy::RcssParser::make_STAMINA_CAPACITY(loc); }
"stamina_inc_max"  		{ return yy::RcssParser::make_STAMINA_INC_MAX(loc); }
"stamina_max"  			{ return yy::RcssParser::make_STAMINA_MAX(loc); }
"start_goal_l"  		{ return yy::RcssParser::make_START_GOAL_L(loc); }
"start_goal_r"  		{ return yy::RcssParser::make_START_GOAL_R(loc); }
"stopped_ball_vel"  	{ return yy::RcssParser::make_STOPPED_BALL_VEL(loc); }
"synch_micro_sleep"  	{ return yy::RcssParser::make_SYNCH_MICRO_SLEEP(loc); }
"synch_mode"  			{ return yy::RcssParser::make_SYNCH_MODE(loc); }
"synch_offset"  		{ return yy::RcssParser::make_SYNCH_OFFSET(loc); }
"synch_see_offset"  	{ return yy::RcssParser::make_SYNCH_SEE_OFFSET(loc); }
"tackle_back_dist"  	{ return yy::RcssParser::make_TACKLE_BACK_DIST(loc); }
"tackle_cycles"  		{ return yy::RcssParser::make_TACKLE_CYCLES(loc); }
"tackle_dist"  			{ return yy::RcssParser::make_TACKLE_DIST(loc); }
"tackle_exponent"  		{ return yy::RcssParser::make_TACKLE_EXPONENT(loc); }
"tackle_power_rate"  	{ return yy::RcssParser::make_TACKLE_POWER_RATE(loc); }
"tackle_rand_factor"  	{ return yy::RcssParser::make_TACKLE_RAND_FACTOR(loc); }
"tackle_width"  		{ return yy::RcssParser::make_TACKLE_WIDTH(loc); }
"team_actuator_noise"  	{ return yy::RcssParser::make_TEAM_ACTUATOR_NOISE(loc); }
"team_l_start"  		{ return yy::RcssParser::make_TEAM_L_START(loc); }
"team_r_start"  		{ return yy::RcssParser::make_TEAM_R_START(loc); }
"text_log_compression"  { return yy::RcssParser::make_TEXT_LOG_COMPRESSION(loc); }
"text_log_dated"  		{ return yy::RcssParser::make_TEXT_LOG_DATED(loc); }
"text_log_dir"  		{ return yy::RcssParser::make_TEXT_LOG_DIR(loc); }
"text_log_fixed"  		{ return yy::RcssParser::make_TEXT_LOG_FIXED(loc); }
"text_log_fixed_name"  	{ return yy::RcssParser::make_TEXT_LOG_FIXED_NAME(loc); }
"text_logging"  		{ return yy::RcssParser::make_TEXT_LOGGING(loc); }
"use_offside"  			{ return yy::RcssParser::make_USE_OFFSIDE(loc); }
"verbose"  				{ return yy::RcssParser::make_VERBOSE(loc); }
"visible_angle"  		{ return yy::RcssParser::make_VISIBLE_ANGLE(loc); }
"visible_distance"  	{ return yy::RcssParser::make_VISIBLE_DISTANCE(loc); }
"wind_ang"  			{ return yy::RcssParser::make_WIND_ANG(loc); }
"wind_dir"  			{ return yy::RcssParser::make_WIND_DIR(loc); }
"wind_force"  			{ return yy::RcssParser::make_WIND_FORCE(loc); }
"wind_none"  			{ return yy::RcssParser::make_WIND_NONE(loc); }
"wind_rand"  			{ return yy::RcssParser::make_WIND_RAND(loc); }
"wind_random"  			{ return yy::RcssParser::make_WIND_RANDOM(loc); }

"before_kick_off" { return yy::RcssParser::make_BEFORE_KICK_OFF( loc ); }
"time_over" { return yy::RcssParser::make_TIME_OVER( loc ); }
"play_on" { return yy::RcssParser::make_PLAY_ON( loc ); }
"kick_off_l" { return yy::RcssParser::make_KICK_OFF_L( loc ); }
"kick_off_r" { return yy::RcssParser::make_KICK_OFF_R( loc ); }
"kick_in_l" { return yy::RcssParser::make_KICK_IN_L( loc ); }
"kick_in_r" { return yy::RcssParser::make_KICK_IN_R( loc ); }
"free_kick_l" { return yy::RcssParser::make_FREE_KICK_L( loc ); }
"free_kick_r" { return yy::RcssParser::make_FREE_KICK_R( loc ); }
"corner_kick_l" { return yy::RcssParser::make_CORNER_KICK_L( loc ); }
"corner_kick_r" { return yy::RcssParser::make_CORNER_KICK_R( loc ); }
"goal_kick_l" { return yy::RcssParser::make_GOAL_KICK_L( loc ); }
"goal_kick_r" { return yy::RcssParser::make_GOAL_KICK_R( loc ); }
"goal_l" { return yy::RcssParser::make_GOAL_L( loc ); }
"goal_r" { return yy::RcssParser::make_GOAL_R( loc ); }
"drop_ball" { return yy::RcssParser::make_DROP_BALL( loc ); }
"offside_l" { return yy::RcssParser::make_OFFSIDE_L( loc ); }
"offside_r" { return yy::RcssParser::make_OFFSIDE_R( loc ); }
"penalty_kick_l" { return yy::RcssParser::make_PENALTY_KICK_L( loc ); }
"penalty_kick_r" { return yy::RcssParser::make_PENALTY_KICK_R( loc ); }
"first_half_over" { return yy::RcssParser::make_FIRST_HALF_OVER( loc ); }
"pause" { return yy::RcssParser::make_PAUSE( loc ); }
"human_judge" { return yy::RcssParser::make_HUMAN_JUDGE( loc ); }
"foul_charge_l" { return yy::RcssParser::make_FOUL_CHARGE_L( loc ); }
"foul_charge_r" { return yy::RcssParser::make_FOUL_CHARGE_R( loc ); }
"foul_push_l" { return yy::RcssParser::make_FOUL_PUSH_L( loc ); }
"foul_push_r" { return yy::RcssParser::make_FOUL_PUSH_R( loc ); }
"foul_multiple_attack_l" { return yy::RcssParser::make_FOUL_MULTIPLE_ATTACK_L( loc ); }
"foul_multiple_attack_r" { return yy::RcssParser::make_FOUL_MULTIPLE_ATTACK_R( loc ); }
"foul_ballout_l" { return yy::RcssParser::make_FOUL_BALLOUT_L( loc ); }
"foul_ballout_r" { return yy::RcssParser::make_FOUL_BALLOUT_R( loc ); }
"back_pass_l" { return yy::RcssParser::make_BACK_PASS_L( loc ); }
"back_pass_r" { return yy::RcssParser::make_BACK_PASS_R( loc ); }
"free_kick_fault_l" { return yy::RcssParser::make_FREE_KICK_FAULT_L( loc ); }
"free_kick_fault_r" { return yy::RcssParser::make_FREE_KICK_FAULT_R( loc ); }
"catch_fault_l" { return yy::RcssParser::make_CATCH_FAULT_L( loc ); }
"catch_fault_r" { return yy::RcssParser::make_CATCH_FAULT_R( loc ); }
"indirect_free_kick_l" { return yy::RcssParser::make_INDIRECT_FREE_KICK_L( loc ); }
"indirect_free_kick_r" { return yy::RcssParser::make_INDIRECT_FREE_KICK_R( loc ); }
"penalty_setup_l" { return yy::RcssParser::make_PENALTY_SETUP_L( loc ); }
"penalty_setup_r" { return yy::RcssParser::make_PENALTY_SETUP_R( loc ); }
"penalty_ready_l" { return yy::RcssParser::make_PENALTY_READY_L( loc ); }
"penalty_ready_r" { return yy::RcssParser::make_PENALTY_READY_R( loc ); }
"penalty_taken_l" { return yy::RcssParser::make_PENALTY_TAKEN_L( loc ); }
"penalty_taken_r" { return yy::RcssParser::make_PENALTY_TAKEN_R( loc ); }
"penalty_miss_l" { return yy::RcssParser::make_PENALTY_MISS_L( loc ); }
"penalty_miss_r" { return yy::RcssParser::make_PENALTY_MISS_R( loc ); }
"penalty_score_l" { return yy::RcssParser::make_PENALTY_SCORE_L( loc ); }
"penalty_score_r" { return yy::RcssParser::make_PENALTY_SCORE_R( loc ); }



"allow_mult_default_type"  { return yy::RcssParser::make_ALLOW_MULT_DEFAULT_TYPE(loc); }
"catchable_area_l_stretch_max"  { return yy::RcssParser::make_CATCHABLE_AREA_L_STRETCH_MAX(loc); }
"catchable_area_l_stretch_min"  { return yy::RcssParser::make_CATCHABLE_AREA_L_STRETCH_MIN(loc); }
"dash_power_rate_delta_max"  { return yy::RcssParser::make_DASH_POWER_RATE_DELTA_MAX(loc); }
"dash_power_rate_delta_min"  { return yy::RcssParser::make_DASH_POWER_RATE_DELTA_MIN(loc); }
"effort_max_delta_factor"  { return yy::RcssParser::make_EFFORT_MAX_DELTA_FACTOR(loc); }
"effort_min_delta_factor"  { return yy::RcssParser::make_EFFORT_MIN_DELTA_FACTOR(loc); }
"extra_stamina_delta_max"  { return yy::RcssParser::make_EXTRA_STAMINA_DELTA_MAX(loc); }
"extra_stamina_delta_min"  { return yy::RcssParser::make_EXTRA_STAMINA_DELTA_MIN(loc); }
"foul_detect_probability_delta_factor"  { return yy::RcssParser::make_FOUL_DETECT_PROBABILITY_DELTA_FACTOR(loc); }
"inertia_moment_delta_factor"  { return yy::RcssParser::make_INERTIA_MOMENT_DELTA_FACTOR(loc); }
"kick_power_rate_delta_max"  { return yy::RcssParser::make_KICK_POWER_RATE_DELTA_MAX(loc); }
"kick_power_rate_delta_min"  { return yy::RcssParser::make_KICK_POWER_RATE_DELTA_MIN(loc); }
"kick_rand_delta_factor"  { return yy::RcssParser::make_KICK_RAND_DELTA_FACTOR(loc); }
"kickable_margin_delta_max"  { return yy::RcssParser::make_KICKABLE_MARGIN_DELTA_MAX(loc); }
"kickable_margin_delta_min"  { return yy::RcssParser::make_KICKABLE_MARGIN_DELTA_MIN(loc); }
"new_dash_power_rate_delta_max"  { return yy::RcssParser::make_NEW_DASH_POWER_RATE_DELTA_MAX(loc); }
"new_dash_power_rate_delta_min"  { return yy::RcssParser::make_NEW_DASH_POWER_RATE_DELTA_MIN(loc); }
"new_stamina_inc_max_delta_factor"  { return yy::RcssParser::make_NEW_STAMINA_INC_MAX_DELTA_FACTOR(loc); }
"player_decay_delta_max"  { return yy::RcssParser::make_PLAYER_DECAY_DELTA_MAX(loc); }
"player_decay_delta_min"  { return yy::RcssParser::make_PLAYER_DECAY_DELTA_MIN(loc); }
"player_size_delta_factor"  { return yy::RcssParser::make_PLAYER_SIZE_DELTA_FACTOR(loc); }
"player_speed_max_delta_max"  { return yy::RcssParser::make_PLAYER_SPEED_MAX_DELTA_MAX(loc); }
"player_speed_max_delta_min"  { return yy::RcssParser::make_PLAYER_SPEED_MAX_DELTA_MIN(loc); }
"player_types"  { return yy::RcssParser::make_PLAYER_TYPES(loc); }
"pt_max"  { return yy::RcssParser::make_PT_MAX(loc); }
"random_seed"  { return yy::RcssParser::make_RANDOM_SEED(loc); }
"stamina_inc_max_delta_factor"  { return yy::RcssParser::make_STAMINA_INC_MAX_DELTA_FACTOR(loc); }
"subs_max"  { return yy::RcssParser::make_SUBS_MAX(loc); }

"id"  { return yy::RcssParser::make_ID(loc); }
"effort_max"  { return yy::RcssParser::make_EFFORT_MAX(loc); }
"catchable_area_l_stretch"  { return yy::RcssParser::make_CATCHABLE_AREA_L_STRETCH(loc); }

"(f t l 50)" { return yy::RcssParser::make_FTL50( loc ); }
"(f t l 40)" { return yy::RcssParser::make_FTL40( loc ); }
"(f t l 30)" { return yy::RcssParser::make_FTL30( loc ); }
"(f t l 20)" { return yy::RcssParser::make_FTL20( loc ); }
"(f t l 10)" { return yy::RcssParser::make_FTL10( loc ); }
"(f t 0)" { return yy::RcssParser::make_FT0( loc ); }
"(f t r 10)" { return yy::RcssParser::make_FTR10( loc ); }
"(f t r 20)" { return yy::RcssParser::make_FTR20( loc ); }
"(f t r 30)" { return yy::RcssParser::make_FTR30( loc ); }
"(f t r 40)" { return yy::RcssParser::make_FTR40( loc ); }
"(f t r 50)" { return yy::RcssParser::make_FTR50( loc ); }
"(f r t 30)" { return yy::RcssParser::make_FRT30( loc ); }
"(f r t 20)" { return yy::RcssParser::make_FRT20( loc ); }
"(f r t 10)" { return yy::RcssParser::make_FRT10( loc ); }
"(f r 0)" { return yy::RcssParser::make_FR0( loc ); }
"(f r b 10)" { return yy::RcssParser::make_FRB10( loc ); }
"(f r b 20)" { return yy::RcssParser::make_FRB20( loc ); }
"(f r b 30)" { return yy::RcssParser::make_FRB30( loc ); }
"(f b r 10)" { return yy::RcssParser::make_FBR10( loc ); }
"(f b r 20)" { return yy::RcssParser::make_FBR20( loc ); }
"(f b r 30)" { return yy::RcssParser::make_FBR30( loc ); }
"(f b r 40)" { return yy::RcssParser::make_FBR40( loc ); }
"(f b r 50)" { return yy::RcssParser::make_FBR50( loc ); }
"(f b 0)" { return yy::RcssParser::make_FB0( loc ); }
"(f b l 10)" { return yy::RcssParser::make_FBL10( loc ); }
"(f b l 20)" { return yy::RcssParser::make_FBL20( loc ); }
"(f b l 30)" { return yy::RcssParser::make_FBL30( loc ); }
"(f b l 40)" { return yy::RcssParser::make_FBL40( loc ); }
"(f b l 50)" { return yy::RcssParser::make_FBL50( loc ); }
"(f l b 30)" { return yy::RcssParser::make_FLB30( loc ); }
"(f l b 20)" { return yy::RcssParser::make_FLB20( loc ); }
"(f l b 10)" { return yy::RcssParser::make_FLB10( loc ); }
"(f l 0)" { return yy::RcssParser::make_FL0( loc ); }
"(f l t 10)" { return yy::RcssParser::make_FLT10( loc ); }
"(f l t 20)" { return yy::RcssParser::make_FLT20( loc ); }
"(f l t 30)" { return yy::RcssParser::make_FLT30( loc ); }
"(f l t)" { return yy::RcssParser::make_FLT( loc ); }
"(f c t)" { return yy::RcssParser::make_FCT( loc ); }
"(f r t)" { return yy::RcssParser::make_FRT( loc ); }
"(f g r t)" { return yy::RcssParser::make_FGRT( loc ); }
"(g r)" { return yy::RcssParser::make_GR( loc ); }
"(f g r b)" { return yy::RcssParser::make_FGRB( loc ); }
"(f r b)" { return yy::RcssParser::make_FRB( loc ); }
"(f c b)" { return yy::RcssParser::make_FCB( loc ); }
"(f l b)" { return yy::RcssParser::make_FLB( loc ); }
"(f g l b)" { return yy::RcssParser::make_FGLB( loc ); }
"(g l)" { return yy::RcssParser::make_GL( loc ); }
"(f g l t)" { return yy::RcssParser::make_FGLT( loc ); }
"(f p l t)" { return yy::RcssParser::make_FPLT( loc ); }
"(f p r t)" { return yy::RcssParser::make_FPRT( loc ); }
"(f p r c)" { return yy::RcssParser::make_FPRC( loc ); }
"(f p r b)" { return yy::RcssParser::make_FPRB( loc ); }
"(f p l b)" { return yy::RcssParser::make_FPLB( loc ); }
"(f p l c)" { return yy::RcssParser::make_FPLC( loc ); }
"(f c)" { return yy::RcssParser::make_FC( loc ); }
"(F)" { return yy::RcssParser::make_FLAG_MAYUS( loc ); }
"(G)" { return yy::RcssParser::make_GOAL_MAYUS( loc ); }



"(l t)" { return yy::RcssParser::make_LINE_TOP( loc); }
"(l b)" { return yy::RcssParser::make_LINE_BOTTOM( loc); }
"(l l)" { return yy::RcssParser::make_LINE_LEFT( loc); }
"(l r)" { return yy::RcssParser::make_LINE_RIGHT( loc); }

"(b)" { return yy::RcssParser::make_BALL_CLOSE( loc ); } 
"(B)" { return yy::RcssParser::make_BALL_FAR( loc ); } 

"p" { return yy::RcssParser::make_P(loc); }
"(P)" { return yy::RcssParser::make_P_FAR(loc); }

"goalie" { return yy::RcssParser::make_GOALIE(loc); }

"t" { return yy::RcssParser::make_T(loc); }
"k" { return yy::RcssParser::make_K(loc); }

"view_mode" { return yy::RcssParser::make_VIEW_MODE( loc ); } 
"stamina" { return yy::RcssParser::make_STAMINA( loc ); } 
"speed" { return yy::RcssParser::make_SPEED( loc ); } 
"head_angle" { return yy::RcssParser::make_HEAD_ANGLE( loc ); } 
"kick" { return yy::RcssParser::make_KICK( loc ); } 
"dash" { return yy::RcssParser::make_DASH( loc ); } 
"turn" { return yy::RcssParser::make_TURN( loc ); } 
"say" { return yy::RcssParser::make_SAY( loc ); } 
"turn_neck" { return yy::RcssParser::make_TURN_NECK( loc ); } 
"catch" { return yy::RcssParser::make_CATCH( loc ); } 
"move" { return yy::RcssParser::make_MOVE( loc ); } 
"change_view" { return yy::RcssParser::make_CHANGE_VIEW( loc ); } 
"arm" { return yy::RcssParser::make_ARM( loc ); } 
"focus" { return yy::RcssParser::make_FOCUS( loc ); } 
"tackle" { return yy::RcssParser::make_TACKLE( loc ); } 
"collision" { return yy::RcssParser::make_COLLISION( loc ); } 
"foul" { return yy::RcssParser::make_FOUL( loc ); } 
"high" { return yy::RcssParser::make_HIGH( loc ); } 
"low" { return yy::RcssParser::make_LOW( loc ); } 
"narrow" { return yy::RcssParser::make_NARROW( loc ); } 
"normal" { return yy::RcssParser::make_NORMAL( loc ); } 
"WIDE" { return yy::RcssParser::make_WIDE( loc ); } 
"target" { return yy::RcssParser::make_TARGET( loc ); } 
"none" { return yy::RcssParser::make_NONE( loc ); } 
"movable" { return yy::RcssParser::make_MOVABLE( loc ); } 
"expires" { return yy::RcssParser::make_EXPIRES( loc ); } 
"count" { return yy::RcssParser::make_COUNT( loc ); } 
"ball" { return yy::RcssParser::make_BALL( loc ); } 
"player" { return yy::RcssParser::make_PLAYER( loc ); } 
"post" { return yy::RcssParser::make_POST( loc ); } 
"charged" { return yy::RcssParser::make_CHARGED( loc ); } 
"yellow" { return yy::RcssParser::make_YELLOW( loc ); } 
"red" { return yy::RcssParser::make_RED( loc ); } 
"card" { return yy::RcssParser::make_CARD( loc ); } 

"online_coach_left" { return yy::RcssParser::make_ONLINE_COACH_LEFT( loc ); } 
"online_coach_right" { return yy::RcssParser::make_ONLINE_COACH_RIGHT( loc ); } 
"opp" { return yy::RcssParser::make_OPP( loc ); } 
"our" { return yy::RcssParser::make_OUR( loc ); } 
"referee" { return yy::RcssParser::make_REFEREE( loc ); } 
"self" { return yy::RcssParser::make_SELF( loc ); } 

"connection_failed" { return yy::RcssParser::make_CONNECTION_FAILED( loc ); } 
"illegal_command_form" { return yy::RcssParser::make_ILLEGAL_COMMAND_FORM( loc ); } 
"illegal_teamname" { return yy::RcssParser::make_ILLEGAL_TEAMNAME( loc ); } 
"illegal_teamname_or_too_long_teamname" { return yy::RcssParser::make_ILLEGAL_TEAMNAME_OR_TOO_LONG_TEAMNAME( loc ); } 
"no_more_team" { return yy::RcssParser::make_NO_MORE_TEAM( loc ); } 
"no_more_player_or_goalie_or_illegal_client_version" { return yy::RcssParser::make_NO_MORE_PLAYER_OR_GOALIE_OR_ILLEGAL_CLIENT_VERSION( loc ); } 
"socket_open_failed" { return yy::RcssParser::make_SOCKET_OPEN_FAILED( loc ); } 
"illegal_client_version" { return yy::RcssParser::make_ILLEGAL_CLIENT_VERSION( loc ); } 
"no_such_team_or_player" { return yy::RcssParser::make_NO_SUCH_TEAM_OR_PLAYER( loc ); } 
"cannot_reconnect_while_playon" { return yy::RcssParser::make_CANNOT_RECONNECT_WHILE_PLAYON( loc ); } 

"no_team_found" { return yy::RcssParser::make_NO_TEAM_FOUND( loc ); }
"no_such_player" { return yy::RcssParser::make_NO_SUCH_PLAYER( loc ); }
"cannot_sub_while_playon" { return yy::RcssParser::make_CANNOT_SUB_WHILE_PLAYON( loc ); }
"no_subs_left" { return yy::RcssParser::make_NO_SUBS_LEFT( loc ); }
"max_of_that_type_of_field" { return yy::RcssParser::make_MAX_OF_THAT_TYPE_OF_FIELD( loc ); }
"cannot_change_goalie" { return yy::RcssParser::make_CANNOT_CHANGE_GOALIE( loc ); }
"compression_unsupported" { return yy::RcssParser::make_COMPRESSION_UNSUPPORTED( loc ); }
"message_not_null_terminated" { return yy::RcssParser::make_MESSAGE_NOT_NULL_TERMINATED( loc ); }

"goal_l_"[0-9]+ { unsigned x = (unsigned int) strtol(yytext+7, NULL, 10); return yy::RcssParser::make_GOAL_L_NUMBER( x, loc ); }
"goal_r_"[0-9]+ { unsigned x = (unsigned int) strtol(yytext+7, NULL, 10); return yy::RcssParser::make_GOAL_R_NUMBER( x, loc ); }
"time_up" { return yy::RcssParser::make_TIME_UP( loc ); }
"goalie_catch_ball_l" { return yy::RcssParser::make_GOALIE_CATCH_BALL_L( loc );}
"goalie_catch_ball_r" { return yy::RcssParser::make_GOALIE_CATCH_BALL_R( loc );  }
"penalty_onfield_l" { return yy::RcssParser::make_PENALTY_ONFIELD_L( loc ); }
"penalty_onfield_r" { return yy::RcssParser::make_PENALTY_ONFIELD_R( loc ); }
"penalty_foul_r" { return yy::RcssParser::make_PENALTY_FOUL_R( loc ); }
"penalty_foul_l" { return yy::RcssParser::make_PENALTY_FOUL_L( loc ); }
"penalty_winner_l" { return yy::RcssParser::make_PENALTY_WINNER_L( loc ); }
"penalty_winner_r" { return yy::RcssParser::make_PENALTY_WINNER_R( loc ); }
"penalty_draw" { return yy::RcssParser::make_PENALTY_DRAW( loc ); }
"yellow_card_l_"[0-9] { unsigned x = (unsigned int) strtol(yytext+14, NULL, 10); return yy::RcssParser::make_YELLOW_CARD_L_NUMBER( x, loc ); }
"yellow_card_r_"[0-9] { unsigned x = (unsigned int) strtol(yytext+14, NULL, 10); return yy::RcssParser::make_YELLOW_CARD_R_NUMBER( x, loc ); }
"red_card_r_"[0-9] { unsigned x = (unsigned int) strtol(yytext+11, NULL, 10); return yy::RcssParser::make_RED_CARD_L_NUMBER( x, loc ); }
"red_card_l_"[0-9] { unsigned x = (unsigned int) strtol(yytext+11, NULL, 10); return yy::RcssParser::make_RED_CARD_R_NUMBER( x, loc ); }


[a-zA-Z_]+[a-zA-Z0-9_]* {  return yy::RcssParser::make_IDENTIFIER(yytext, loc); }
[0-9]+[a-zA-Z0-9_]* 	{  return yy::RcssParser::make_UNKOWN(loc); }
.						{ }
<<EOF>>    				{return yy::RcssParser::make_END(loc);}

%%
