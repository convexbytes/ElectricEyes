#ifndef _TYPES_
#define _TYPES_

#include <iostream>

#ifndef NDEF_NUM
#define NDEF_NUM -666
#endif

#ifndef NDEF_STR 
#define NDEF_STR "NDEF"
#endif

#include <list>
#include <string>

namespace ClientParser
{


enum MessageType
{
	MT_INVALID_MESSAGE = -1,
	MT_INIT,
	MT_SERVER_PARAM,
	MT_PLAYER_PARAM,
	MT_PLAYER_TYPE,
	MT_SEE,
	MT_SENSE_BODY, /* 5 */
	MT_HEAR,
	MT_ERROR,
	MT_SCORE,
	MT_WARNING,
	MT_OK, /* 10 */
	MT_CHANGE_PLAYER_TYPE
};

enum Playmode
{
	PM_NULL = -1,
    PM_BEFORE_KICK_OFF,
	PM_TIME_OVER,
	PM_PLAY_ON,
	PM_KICK_OFF_L,
	PM_KICK_OFF_R,
	PM_KICK_IN_L,
	PM_KICK_IN_R,
	PM_FREE_KICK_L,
	PM_FREE_KICK_R,
	PM_CORNER_KICK_L,
	PM_CORNER_KICK_R,
	PM_GOAL_KICK_L,
	PM_GOAL_KICK_R,
	PM_GOAL_L,
	PM_GOAL_R,
	PM_DROP_BALL,
	PM_OFFSIDE_L,
	PM_OFFSIDE_R,
	PM_PENALTY_KICK_L,
	PM_PENALTY_KICK_R,
	PM_FIRST_HALF_OVER,
	PM_PAUSE,
	PM_HUMAN_JUDGE,
	PM_FOUL_CHARGE_L,
	PM_FOUL_CHARGE_R,
	PM_FOUL_PUSH_L,
	PM_FOUL_PUSH_R,
	PM_FOUL_MULTIPLE_ATTACK_L,
	PM_FOUL_MULTIPLE_ATTACK_R,
	PM_FOUL_BALLOUT_L,
	PM_FOUL_BALLOUT_R,
	PM_BACK_PASS_L,
	PM_BACK_PASS_R,
	PM_FREE_KICK_FAULT_L,
	PM_FREE_KICK_FAULT_R,
	PM_CATCH_FAULT_L,
	PM_CATCH_FAULT_R,
	PM_INDIRECT_FREE_KICK_L,
	PM_INDIRECT_FREE_KICK_R,
	PM_PENALTY_SETUP_L,
	PM_PENALTY_SETUP_R,
	PM_PENALTY_READY_L,
	PM_PENALTY_READY_R,
	PM_PENALTY_TAKEN_L,
	PM_PENALTY_TAKEN_R,
	PM_PENALTY_MISS_L,
	PM_PENALTY_MISS_R,
	PM_PENALTY_SCORE_L,
	PM_PENALTY_SCORE_R
};

enum PlaymodeHearable
{
	PMH_NULL = -1,

	PMH_BEFORE_KICK_OFF,
	PMH_TIME_OVER,
	PMH_PLAY_ON,
	PMH_KICK_OFF_L,
	PMH_KICK_OFF_R,
	PMH_KICK_IN_L,
	PMH_KICK_IN_R,
	PMH_FREE_KICK_L,
	PMH_FREE_KICK_R,
	PMH_CORNER_KICK_L,
	PMH_CORNER_KICK_R,
	PMH_GOAL_KICK_L,
	PMH_GOAL_KICK_R,
	PMH_GOAL_L,
	PMH_GOAL_R,
	PMH_DROP_BALL,
	PMH_OFFSIDE_L,
	PMH_OFFSIDE_R,
	PMH_PENALTY_KICK_L,
	PMH_PENALTY_KICK_R,
	PMH_FIRST_HALF_OVER,
	PMH_PAUSE,
	PMH_HUMAN_JUDGE,
	PMH_FOUL_CHARGE_L,
	PMH_FOUL_CHARGE_R,
	PMH_FOUL_PUSH_L,
	PMH_FOUL_PUSH_R,
	PMH_FOUL_MULTIPLE_ATTACK_L,
	PMH_FOUL_MULTIPLE_ATTACK_R,
	PMH_FOUL_BALLOUT_L,
	PMH_FOUL_BALLOUT_R,
	PMH_BACK_PASS_L,
	PMH_BACK_PASS_R,
	PMH_FREE_KICK_FAULT_L,
	PMH_FREE_KICK_FAULT_R,
	PMH_CATCH_FAULT_L,
	PMH_CATCH_FAULT_R,
	PMH_INDIRECT_FREE_KICK_L,
	PMH_INDIRECT_FREE_KICK_R,
	PMH_PENALTY_SETUP_L,
	PMH_PENALTY_SETUP_R,
	PMH_PENALTY_READY_L,
	PMH_PENALTY_READY_R,
	PMH_PENALTY_TAKEN_L,
	PMH_PENALTY_TAKEN_R,
	PMH_PENALTY_MISS_L,
	PMH_PENALTY_MISS_R,
	PMH_PENALTY_SCORE_L,
	PMH_PENALTY_SCORE_R,

	PMH_FOUL_L,
	PMH_FOUL_R,
	PMH_GOALIE_CATCH_BALL_L,
	PMH_GOALIE_CATCH_BALL_R,
	PMH_PENALTY_ONFIELD_L,
	PMH_PENALTY_ONFIELD_R,
	PMH_PENALTY_FOUL_R,
	PMH_PENALTY_FOUL_L,
	PMH_PENALTY_WINNER_L,
	PMH_PENALTY_WINNER_R,
	PMH_PENALTY_DRAW,
	PMH_YELLOW_CARD_L,
	PMH_YELLOW_CARD_R,
	PMH_RED_CARD_R,
	PMH_RED_CARD_L,
	PMH_HALF_TIME,
	PMH_TIME_UP
};

enum Side
{
	SIDE_NONE = -1,
	SIDE_LEFT,
	SIDE_RIGHT
};

enum FlagId
{
	FLAG_FTL50,
	FLAG_FTL40,
	FLAG_FTL30,
	FLAG_FTL20,
	FLAG_FTL10,
	FLAG_FT0,
	FLAG_FTR10,
	FLAG_FTR20,
	FLAG_FTR30,
	FLAG_FTR40,
	FLAG_FTR50,
	FLAG_FRT30,
	FLAG_FRT20,
	FLAG_FRT10,
	FLAG_FR0,
	FLAG_FRB10,
	FLAG_FRB20,
	FLAG_FRB30,
	FLAG_FBR10,
	FLAG_FBR20,
	FLAG_FBR30,
	FLAG_FBR40,
	FLAG_FBR50,
	FLAG_FB0,
	FLAG_FBL10,
	FLAG_FBL20,
	FLAG_FBL30,
	FLAG_FBL40,
	FLAG_FBL50,
	FLAG_FLB30,
	FLAG_FLB20,
	FLAG_FLB10,
	FLAG_FL0,
	FLAG_FLT10,
	FLAG_FLT20,
	FLAG_FLT30,
	FLAG_FLT,
	FLAG_FCT,
	FLAG_FRT,
	FLAG_FGRT,
	FLAG_GR,
	FLAG_FGRB,
	FLAG_FRB,
	FLAG_FCB,
	FLAG_FLB,
	FLAG_FGLB,
	FLAG_GL,
	FLAG_FGLT,
	FLAG_FPLT,
	FLAG_FPRT,
	FLAG_FPRC,
	FLAG_FPRB,
	FLAG_FPLB,
	FLAG_FPLC,
	FLAG_FC,
	FLAG_MAYUS,
	GOAL_MAYUS
};

enum LineId
{
	LINE_TOP,
	LINE_BOTTOM,
	LINE_LEFT,
	LINE_RIGHT
};

enum ViewQuality
{
	VIEW_QUALITY_LOW,
	VIEW_QUALITY_HIGH
};

enum ViewWidth
{
	VIEW_WIDTH_NARROW,
	VIEW_WIDTH_NORMAL,
	VIEW_WIDTH_WIDE
};

enum FoulCard
{
	FOUL_CARD_NONE,
	FOUL_CARD_YELLOW,
	FOUL_CARD_RED
};

enum Collision
{
	COLLISION_NONE,
	COLLISION_BALL,
	COLLISION_PLAYER,
	COLLISION_POST
};

enum Sender
{
	SENDER_OUR,
	SENDER_OPP,
	SENDER_REFEREE,
	SENDER_SELF,
	SENDER_OFFLINE_COACH,
	SENDER_ONLINE_COACH_L,
	SENDER_ONLINE_COACH_R
};

enum ErrorType
{
	ET_CONNECTION_FAILED,
	ET_ILLEGAL_COMMAND_FORM,
	ET_ILLEGAL_TEAMNAME,
	ET_ILLEGAL_TEAMNAME_OR_TOO_LONG_TEAMNAME,
	ET_NO_MORE_TEAM,
	ET_NO_MORE_PLAYER_OR_GOALIE_OR_ILLEGAL_CLIENT_VERSION,
	ET_SOCKET_OPEN_FAILED,
	ET_ILLEGAL_CLIENT_VERSION,
	ET_NO_SUCH_TEAM_OR_PLAYER,
	ET_CANNOT_RECONNECT_WHILE_PLAYON
};

enum WarningType
{
	W_MSG_NOT_NULL_TERMINATED,
	W_NO_TEAM_FOUND,
	W_NO_SUCH_PLAYER,
	W_CANNOT_SUB_WHILE_PLAYON,
	W_NO_SUBS_LEFT,
	W_MAX_OF_THAT_TYPE_OF_FIELD,
	W_CANNOT_CHANGE_GOALIE,
	W_COMPRESSION_UNSUPPORTED
};

inline
bool
is_defined( double value )
{
	return value != NDEF_NUM;
}


inline
bool
is_defined( std::string const & s )
{
	return s.compare( NDEF_STR ) == 0;
}


inline
PlaymodeHearable
from_PM_to_PMH( Playmode pm )
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


class Init
{
public:
	Init()
		{
			reset();
		}
	Side 	 side;
	double	 unum;
	Playmode playmode;

	void 	reset()
			{
				side = (Side)(-1);
				unum = NDEF_NUM;
				playmode = (Playmode)(-1);
			}
};

class ServerParam
{
public:
	ServerParam()
		{

		}
	double audio_cut_dist;
	double auto_mode;
	double back_dash_rate;
	double back_passes;
	double ball_accel_max;
	double ball_decay;
	double ball_rand;
	double ball_size;
	double ball_speed_max;
	double ball_stuck_area;
	double ball_weight;
	double catch_ban_cycle;
	double catch_probability;
	double catchable_area_l;
	double catchable_area_w;
	double ckick_margin;
	double clang_advice_win;
	double clang_define_win;
	double clang_del_win;
	double clang_info_win;
	double clang_mess_delay;
	double clang_mess_per_cycle;
	double clang_meta_win;
	double clang_rule_win;
	double clang_win_size;
	double coach;
	double coach_port;
	double coach_w_referee;
	double connect_wait;
	double control_radius;
	double dash_angle_step;
	double dash_power_rate;
	double drop_ball_time;
	double effort_dec;
	double effort_dec_thr;
	double effort_inc;
	double effort_inc_thr;
	double effort_init;
	double effort_min;
	double extra_half_time;
	double extra_stamina;
	double forbid_kick_off_offside;
	double foul_cycles;
	double foul_detect_probability;
	double foul_exponent;
	double free_kick_faults;
	double freeform_send_period;
	double freeform_wait_period;
	double fullstate_l;
	double fullstate_r;
	double game_log_compression;
	double game_log_dated;
	std::string game_log_dir;
	double game_log_fixed;
	std::string game_log_fixed_name;
	double game_log_version;
	double game_logging;
	double game_over_wait;
	double goal_width;
	double goalie_max_moves;
	double golden_goal;
	double half_time;
	double hear_decay;
	double hear_inc;
	double hear_max;
	double inertia_moment;
	double keepaway;
	double keepaway_length;
	double keepaway_log_dated;
	std::string keepaway_log_dir;
	double keepaway_log_fixed;
	std::string keepaway_log_fixed_name;
	double keepaway_logging;
	double keepaway_start;
	double keepaway_width;
	double kick_off_wait;
	double kick_power_rate;
	double kick_rand;
	double kick_rand_factor_l;
	double kick_rand_factor_r;
	double kickable_margin;
	std::string landmark_file;
	std::string log_date_format;
	double log_times;
	double max_back_tackle_power;
	double max_dash_angle;
	double max_dash_power;
	double max_goal_kicks;
	double max_tackle_power;
	double maxmoment;
	double maxneckang;
	double maxneckmoment;
	double maxpower;
	double min_dash_angle;
	double min_dash_power;
	double minmoment;
	double minneckang;
	double minneckmoment;
	double minpower;
	double nr_extra_halfs;
	double nr_normal_halfs;
	double offside_active_area_size;
	double offside_kick_margin;
	double olcoach_port;
	double old_coach_hear;
	double pen_allow_mult_kicks;
	double pen_before_setup_wait;
	double pen_coach_moves_players;
	double pen_dist_x;
	double pen_max_extra_kicks;
	double pen_max_goalie_dist_x;
	double pen_nr_kicks;
	double pen_random_winner;
	double pen_ready_wait;
	double pen_setup_wait;
	double pen_taken_wait;
	double penalty_shoot_outs;
	double player_accel_max;
	double player_decay;
	double player_rand;
	double player_size;
	double player_speed_max;
	double player_speed_max_min;
	double player_weight;
	double point_to_ban;
	double point_to_duration;
	double port;
	double prand_factor_l;
	double prand_factor_r;
	double profile;
	double proper_goal_kicks;
	double quantize_step;
	double quantize_step_l;
	double record_messages;
	double recover_dec;
	double recover_dec_thr;
	double recover_init;
	double recover_min;
	double recv_step;
	double red_card_probability;
	double say_coach_cnt_max;
	double say_coach_msg_size;
	double say_msg_size;
	double send_comms;
	double send_step;
	double send_vi_step;
	double sense_body_step;
	double side_dash_rate;
	double simulator_step;
	double slow_down_factor;
	double slowness_on_top_for_left_team;
	double slowness_on_top_for_right_team;
	double stamina_capacity;
	double stamina_inc_max;
	double stamina_max;
	double start_goal_l;
	double start_goal_r;
	double stopped_ball_vel;
	double synch_micro_sleep;
	double synch_mode;
	double synch_offset;
	double synch_see_offset;
	double tackle_back_dist;
	double tackle_cycles;
	double tackle_dist;
	double tackle_exponent;
	double tackle_power_rate;
	double tackle_rand_factor;
	double tackle_width;
	double team_actuator_noise;
	std::string team_l_start;
	std::string team_r_start;
	double text_log_compression;
	double text_log_dated;
	std::string text_log_dir;
	double text_log_fixed;
	std::string text_log_fixed_name;
	double text_logging;
	double use_offside;
	double verbose;
	double visible_angle;
	double visible_distance;
	double wind_ang;
	double wind_dir;
	double wind_force;
	double wind_none;
	double wind_rand;
	double wind_random;

	void 	reset()
			{

			}
};

class PlayerParam
{
public:
	PlayerParam()
		{
			reset();
		}
	double  allow_mult_default_type;
	double  catchable_area_l_stretch_max;
	double  catchable_area_l_stretch_min;
	double  dash_power_rate_delta_max;
	double  dash_power_rate_delta_min;
	double  effort_max_delta_factor;
	double  effort_min_delta_factor;
	double  extra_stamina_delta_max;
	double  extra_stamina_delta_min;
	double  foul_detect_probability_delta_factor;
	double  inertia_moment_delta_factor;
	double  kick_power_rate_delta_max;
	double  kick_power_rate_delta_min;
	double  kick_rand_delta_factor;
	double  kickable_margin_delta_max;
	double  kickable_margin_delta_min;
	double  new_dash_power_rate_delta_max;
	double  new_dash_power_rate_delta_min;
	double  new_stamina_inc_max_delta_factor;
	double  player_decay_delta_max;
	double  player_decay_delta_min;
	double  player_size_delta_factor;
	double  player_speed_max_delta_max;
	double  player_speed_max_delta_min;
	double  player_types;
	double  pt_max;
	double  random_seed;
	double  stamina_inc_max_delta_factor;
	double  subs_max;

	void 	reset()
			{

			}

};

class PlayerType
{
public:
	PlayerType()
		{
			reset();
		}
	double  id;
	double  player_speed_max;
	double  stamina_inc_max;
	double  player_decay;
	double  inertia_moment;
	double  dash_power_rate;
	double  player_size;
	double  kickable_margin;
	double  kick_rand;
	double  extra_stamina;
	double  effort_max;
	double  effort_min;
	double  kick_power_rate;
	double  foul_detect_probability;
	double  catchable_area_l_stretch;

	void 	reset()
			{

			}
};


class ObjectInfo
{
public:
	ObjectInfo():
		distance 		( NDEF_NUM ),
		direction 		( NDEF_NUM ),
		dist_change 	( NDEF_NUM ),
		dir_change 		( NDEF_NUM ),
		body_facing_dir ( NDEF_NUM ),
		head_facing_dir ( NDEF_NUM ),
		pointing_dir 	( NDEF_NUM ),
		tackle 			( false ),
		kick 			( false )
		{}

	double 	distance;
	double 	direction;
	double 	dist_change;
	double 	dir_change;
	double 	body_facing_dir;
	double 	head_facing_dir;
	double	pointing_dir;
	bool 	tackle;
	bool	kick;

	bool 	is_distance_def() 		{ return distance != NDEF_NUM; }
	bool 	is_direction_def() 		{ return direction != NDEF_NUM; }
	bool 	is_dist_change_def() 	{ return dist_change != NDEF_NUM; }
	bool 	is_dir_change_def() 	{ return dir_change != NDEF_NUM; }
	bool 	is_body_facing_dir_def() { return body_facing_dir!= NDEF_NUM; }
	bool 	is_head_facing_dir_def() { return head_facing_dir!= NDEF_NUM; }
	bool 	is_pointing_dir_def() 	{ return pointing_dir!= NDEF_NUM; }

	void 	setObjectInfo( ObjectInfo const & i )
			{
				*this = i;
			}

	/*std::ostream & operator<<(std::ostream & os )
	{

		os 	<< "(ObjectInfo "
			<< "(dis " << distance << ")"
			<< "(dir " << direction<< ")"
			<< "(dischg " << dist_change << ")"
			<< "(dirchg " << dir_change<< ")"
			<< "(bodydir " << body_facing_dir<< ")"
			<< "(headdir " << head_facing_dir<< ")"
			<< "(pdir " << pointing_dir<< ")"
			<< "(t " << tackle<< ")"
			<< "(k " << kick<< ")"
			<< ")";
		return os;
	}*/

};

class Flag:
		public ObjectInfo
{
public:

	FlagId id;

	/*std::ostream & operator<<(std::ostream & os )
	{
		os 	<< "(Flag "
			<< "(id " << id << ")"
			<< (ObjectInfo)(*this)
			<< ")";
	}*/
};

class Line:
		public ObjectInfo
{
public:
	LineId id;
};

class BallId
{
public:
	BallId():
		mayus_form( false )
		{}

	bool mayus_form;

	void 	setBallId( BallId const & b )
			{
				*this = b;
			}
};

class Ball:
		public BallId,
		public ObjectInfo
{
public:
};

class PlayerId
{
public:
	PlayerId():
		unum( NDEF_NUM ),
		team_name( NDEF_STR ),
		goalie( false ),
		mayus_form( false )
		{}

	int 			unum;
	std::string		team_name;
	bool			goalie;
	bool 			mayus_form;

	bool    is_unum_def() 		{ return unum != NDEF_NUM; }
	bool    is_team_name_def() 	{ return team_name.compare( NDEF_STR) != 0; }


	void  	setPlayerId( PlayerId const & pl_id )
			{
				*this = pl_id;
			}
};


class Player:
		public PlayerId,
		public ObjectInfo
{
public:
};


class See
{
public:
	See():
		time( NDEF_NUM )
		{}

	int 				time;

	std::list<Player> players;
	std::list<Flag> 	flags;
	std::list<Line> 	lines;
	std::list<Ball> 	balls;


	void 	reset()
			{
				time = NDEF_NUM;
				players.clear();
				flags.clear();
				lines.clear();
				balls.clear();
			}

};

class SenseBody
{
public:
	int    			time;

	ViewQuality 	view_mode_quality;
    ViewWidth   	view_mode_width;

    double 			stamina_stamina;
    double 			stamina_effort;
    double 			stamina_capacity;

    double   		speed_amount;
    double   		speed_direction;

    double     		head_angle;

    unsigned int    kick_count;
    unsigned int    dash_count;
    unsigned int    turn_count;
    unsigned int    say_count;
    unsigned int    turn_neck_count;
    unsigned int    catch_count;
    unsigned int    move_count;
    unsigned int    change_view_count;

    unsigned int    arm_movable_cycles;
    unsigned int    arm_expires_cycles;
    double     		arm_target_distance;
    double     		arm_target_direction;
    unsigned int    arm_count;   /* pointToCount */


    Side 			focus_target;
    int     		focus_target_number;
    unsigned int    focus_count;

    unsigned int    tackle_expires_cycles;
    unsigned int    tackle_count;

    std::list<Collision> collisions;

    unsigned int    foul_charged_cycles;
    FoulCard 		foul_card; //se recibe en forma de cadena


    void 		reset()
    			{

    				collisions.clear();
    			}
};

class Hear
{
public:
	Hear()
		{ reset(); }

	int 			time;
	Sender 			sender;
	std::string 	message;
	PlaymodeHearable playmode;
	int 			unum;
	double 			direction;
	int 			goals;
	int 			cards;

	void 		reset()
				{
					time 		= NDEF_NUM;
					sender 		= (Sender)(-1);
					message 	= NDEF_STR;
					unum 		= NDEF_NUM;
					direction 	= NDEF_NUM;
					goals 		= NDEF_NUM;
					cards 		= NDEF_NUM;
				}
};

class Error
{
public:
	Error():
		type 		( (ErrorType)(-1) ),
		unkown_error( NDEF_STR )
		{}

	ErrorType 	type;
	std::string unkown_error;

	void 		reset()
				{
					type 		 = (ErrorType)(-1);
					unkown_error = NDEF_STR;
				}
};

class Score
{
public:
	Score():
		ours 	( NDEF_NUM ),
		theirs 	( NDEF_NUM )
		{}
	int 		ours;
	int 		theirs;
	void 		reset()
				{
					ours = theirs = NDEF_NUM;
				}
};


class Warning
{
public:
	Warning():
		type( (WarningType)(-1) ),
		unkown_warning( NDEF_STR )
		{}

	WarningType type;
	std::string unkown_warning;

	void 		reset()
				{
					type = (WarningType)(-1);
					unkown_warning = NDEF_STR;
				}
};

class Ok
{
public:
	std::string ok_msg;
	void 		reset()
				{
					ok_msg = NDEF_STR;
				}
};

class ChgPlayerType
{
public:
	int 	unum;
	int 	type;
	void 		reset()
				{

				}
};

} /* END namespace ClientParser */

#endif
