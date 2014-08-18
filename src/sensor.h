 /*
 *        FILE: sensor.h
 *  Created on: July, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

#ifndef SENSOR_H
#define SENSOR_H 

#ifndef NDEF_NUM
#define NDEF_NUM -666
#endif

#ifndef NDEF_STR
#define NDEF_STR "NDEF"
#endif

namespace Sensor
{


enum Playmode
{
	PM_NULL = -1,
    PM_BEFORE_KICK_OFF = 0,
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

enum RefereeEvent
{
	PMH_NULL = -1,
	PMH_BEFORE_KICK_OFF = 0,
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
	// Do not change the order
	FLAG_FB0 = 0,
	FLAG_FBL10,
	FLAG_FBL20,
	FLAG_FBL30,
	FLAG_FBL40,
	FLAG_FBL50,
	FLAG_FBR10,
	FLAG_FBR20,
	FLAG_FBR30,
	FLAG_FBR40,
	FLAG_FBR50,
	FLAG_FC,
	FLAG_FCB,
	FLAG_FCT,
	FLAG_FGLB,
	FLAG_FGLT,
	FLAG_FGRB,
	FLAG_FGRT,
	FLAG_FL0,
	FLAG_FLB10,
	FLAG_FLB20,
	FLAG_FLB30,
	FLAG_FLB,
	FLAG_FLT10,
	FLAG_FLT20,
	FLAG_FLT30,
	FLAG_FLT,
	FLAG_FPLB,
	FLAG_FPLC,
	FLAG_FPLT,
	FLAG_FPRB,
	FLAG_FPRC,
	FLAG_FPRT,
	FLAG_FR0,
	FLAG_FRB10,
	FLAG_FRB20,
	FLAG_FRB30,
	FLAG_FRB,
	FLAG_FRT10,
	FLAG_FRT20,
	FLAG_FRT30,
	FLAG_FRT,
	FLAG_FT0,
	FLAG_FTL10,
	FLAG_FTL20,
	FLAG_FTL30,
	FLAG_FTL40,
	FLAG_FTL50,
	FLAG_FTR10,
	FLAG_FTR20,
	FLAG_FTR30,
	FLAG_FTR40,
	FLAG_FTR50,
	FLAG_GL,
	FLAG_GR,
	GOAL_UNKOWN,
	FLAG_UNKOWN
};

extern
double FLAG_COORD[][2];



enum LineId
{
	LINE_TOP,
	LINE_BOTTOM,
	LINE_LEFT,
	LINE_RIGHT
};

enum ViewQuality
{
	VIEWQUALITY_LOW,
	VIEWQUALITY_HIGH
};

enum ViewWidth
{
	VIEWWIDTH_NARROW,
	VIEWWIDTH_NORMAL,
	VIEWWIDTH_WIDE
};

enum FoulCard
{
	FOULCARD_NONE,
	FOULCARD_YELLOW,
	FOULCARD_RED
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
	E_CONNECTION_FAILED,
	E_ILLEGAL_COMMAND_FORM,
	E_ILLEGAL_TEAMNAME,
	E_ILLEGAL_TEAMNAME_OR_TOO_LONG_TEAMNAME,
	E_NO_MORE_TEAM,
	E_NO_MORE_PLAYER_OR_GOALIE_OR_ILLEGAL_CLIENT_VERSION,
	E_SOCKET_OPEN_FAILED,
	E_ILLEGAL_CLIENT_VERSION,
	E_NO_SUCH_TEAM_OR_PLAYER,
	E_CANNOT_RECONNECT_WHILE_PLAYON
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

enum OkType
{
	OK_UNKOWN
};

class Init
{
public:
	Side 	 side;
	int	 	unum;
	Playmode playmode;
};

class ServerParam
{
public:
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
};

class PlayerParam
{
public:
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
	int  	pt_max;
	double  random_seed;
	double  stamina_inc_max_delta_factor;
	double  subs_max;
};

class PlayerType
{
public:
	int  id;
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
};






























class RelativePosition
{
public:
	double dist;
	double dir;
};

class BackwardView
{
public:
	bool behind;
};

class RelativeVelocity
{
public:
	double dist_chg;
	double dir_chg;
};

class Flag 
	: public RelativePosition
	, public BackwardView
{
public:
	FlagId id;

	double x();
	double y();
};

class Line 
	: public RelativePosition
{
public:
	LineId id;
};

class Player 
	: public RelativePosition
	, public RelativeVelocity
	, public BackwardView
{
public:
	std::string team;
	bool 	goalie;
	int 	unum;
	Side 	side;
	bool 	tackle;
	bool 	kick;
	double 	pointdir;
	double 	bodydir;
	double 	headdir;
};

class Ball
	: public RelativePosition
	, public RelativeVelocity
	, public BackwardView
{
public:
};

class See
{
public:
	int 				time;
	std::vector<Player> players;
	std::vector<Flag> 	flags;
	std::vector<Line> 	lines;
	Ball 				ball;

	bool 				ball_visible;
};

class Body
{
public:
	int    		time;
	ViewQuality viewmode_quality;
    ViewWidth   viewmode_width;
    double 		stamina_stamina;
    double 		stamina_effort;
    double 		stamina_capacity;
    double   	speed_amount;
    double   	speed_direction;
    double     	headangle;
    int    		kick_count;
    int    		dash_count;
    int    		turn_count;
    int    		say_count;
    int    		turnneck_count;
    int    		catch_count;
    int    		move_count;
    int    		changeview_count;
    int    		arm_movable;
    int    		arm_expires;
    double     	arm_target_dist;
    double     	arm_target_dir;
    int    		arm_count; 
    Side 		focus_target_side;
    int     	focus_target_number;
    int    		focus_count;
    int    		tackle_expires;
    int    		tackle_count;
    std::vector<Collision> collisions;
    int    		foul_charged;
    FoulCard 	foul_card;
};

class Hear
{
public:
	Hear();
	int 			time;
	Sender 			sender;
	std::string 	message;
	RefereeEvent 	playmode;
	int 			unum;
	double 			dir;
	int 			goals;
	int 			cards;
};

class Error
{
public:
	ErrorType type;
};

class Score
{
public:
	int ours;
	int theirs;
};


class Warning
{
public:
	WarningType type;
};

class Ok
{
public:
	OkType type;
};

class ChgPlayerType
{
public:
	int 	unum;
	int 	type;
};


class Handler
{
public:
	virtual void on_init( Init const & init ) = 0;
	virtual void on_timechange( int time ) = 0;
	virtual void on_body( Body const & bodysense ) = 0;
	virtual void on_see( See const & see ) = 0;
	virtual void on_hear( Hear const & hear ) = 0;
	virtual void on_ok( Ok const & ok ) = 0;
	virtual void on_changeplayertype( ChgPlayerType const & chpt ) = 0;
	virtual void on_serverparam( ServerParam const & sp ) = 0;
	virtual void on_playerparam( PlayerParam const & pp ) = 0;
	virtual void on_playertype( PlayerType const & pt ) = 0;
	virtual void on_error( Error const & err ) = 0;
	virtual void on_warning( Warning const & warn ) = 0;
	virtual void on_score( Score const & score ) = 0;
};


inline
bool
defined( double value )
{
	return value != (double)NDEF_NUM;
}

inline 
bool
defined( int value  )
{
	return value != (int)NDEF_NUM;
}

inline
bool
defined( std::string const & s )
{
	return s.compare( NDEF_STR ) == 0;
}

RefereeEvent from_PM_to_RE( Playmode pm );

} // Namespace Sensor

#endif
