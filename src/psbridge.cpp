/*
 *        FILE: psbridge.cpp
 *  Created on: July, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

ClientParser::MessageType 
PSBridge::parse ( const char * msg )
{	
	using namespace ClientParser;

	/* Scan the string with flex and save the state to delete when finished */
	YY_BUFFER_STATE bs = yy_scan_string( msg );
	yy_switch_to_buffer( bs );

	/* Parse the string */
	M_parser->parse();

	/* Delete the buffer */
	yy_delete_buffer( bs );

	/* The message type has been set at this point by the overriden virtual methods */
	return M_msg_type;
}

ClientParser::MessageType 
PSBridge::parse ( std::string  msg )
{
	return this->parse( msg.c_str() );
}


PSBridge::PSBridge ()
{
	/* Allocate the parser */
	M_time 	   = -1;
	M_parser   = 0;
	M_parser   = new ClientParser::Parser( *this );
	M_msg_type = ClientParser::MT_INVALID_MESSAGE;
	if( M_parser == NULL )
	{
		std::cerr << "SimpleDriver: parser could not be allocated" << std::endl;
		_exit(-1);
	}
}

PSBridge::~PSBridge ()
{
	if( M_parser )
		delete M_parser;
	M_parser = 0;
}


void
PSBridge::set_sensorhandler( Sensor::Handler * sensorhandler )
{
	M_sensorhandler = sensorhandler;
}


void 
PSBridge::error ( const yy::RcssParser::location_type & l,
			const std::string  &m )
{
	M_msg_type = ClientParser::MT_INVALID_MESSAGE;
}

void 
PSBridge::h_init( ClientParser::Init const &  p_init )
{
	using namespace Sensor;
	Sensor::Init init;
	init.side     = cast_side( p_init.side );
	init.unum     = (int)p_init.unum;
	init.playmode = cast_playmode( p_init.playmode );
	
	M_msg_type = ClientParser::MT_INIT;
	M_sensorhandler->on_init( init );

}

void 
PSBridge::h_server_param( ClientParser::ServerParam const &  p_sparam )
{
	Sensor::ServerParam sparam;
	sparam.audio_cut_dist                 = p_sparam.audio_cut_dist;
	sparam.auto_mode                      = p_sparam.auto_mode;
	sparam.back_dash_rate                 = p_sparam.back_dash_rate;
	sparam.back_passes                    = p_sparam.back_passes;
	sparam.ball_accel_max                 = p_sparam.ball_accel_max;
	sparam.ball_decay                     = p_sparam.ball_decay;
	sparam.ball_rand                      = p_sparam.ball_rand;
	sparam.ball_size                      = p_sparam.ball_size;
	sparam.ball_speed_max                 = p_sparam.ball_speed_max;
	sparam.ball_stuck_area                = p_sparam.ball_stuck_area;
	sparam.ball_weight                    = p_sparam.ball_weight;
	sparam.catch_ban_cycle                = p_sparam.catch_ban_cycle;
	sparam.catch_probability              = p_sparam.catch_probability;
	sparam.catchable_area_l               = p_sparam.catchable_area_l;
	sparam.catchable_area_w               = p_sparam.catchable_area_w;
	sparam.ckick_margin                   = p_sparam.ckick_margin;
	sparam.clang_advice_win               = p_sparam.clang_advice_win;
	sparam.clang_define_win               = p_sparam.clang_define_win;
	sparam.clang_del_win                  = p_sparam.clang_del_win;
	sparam.clang_info_win                 = p_sparam.clang_info_win;
	sparam.clang_mess_delay               = p_sparam.clang_mess_delay;
	sparam.clang_mess_per_cycle           = p_sparam.clang_mess_per_cycle;
	sparam.clang_meta_win                 = p_sparam.clang_meta_win;
	sparam.clang_rule_win                 = p_sparam.clang_rule_win;
	sparam.clang_win_size                 = p_sparam.clang_win_size;
	sparam.coach                          = p_sparam.coach;
	sparam.coach_port                     = p_sparam.coach_port;
	sparam.coach_w_referee                = p_sparam.coach_w_referee;
	sparam.connect_wait                   = p_sparam.connect_wait;
	sparam.control_radius                 = p_sparam.control_radius;
	sparam.dash_angle_step                = p_sparam.dash_angle_step;
	sparam.dash_power_rate                = p_sparam.dash_power_rate;
	sparam.drop_ball_time                 = p_sparam.drop_ball_time;
	sparam.effort_dec                     = p_sparam.effort_dec;
	sparam.effort_dec_thr                 = p_sparam.effort_dec_thr;
	sparam.effort_inc                     = p_sparam.effort_inc;
	sparam.effort_inc_thr                 = p_sparam.effort_inc_thr;
	sparam.effort_init                    = p_sparam.effort_init;
	sparam.effort_min                     = p_sparam.effort_min;
	sparam.extra_half_time                = p_sparam.extra_half_time;
	sparam.extra_stamina                  = p_sparam.extra_stamina;
	sparam.forbid_kick_off_offside        = p_sparam.forbid_kick_off_offside;
	sparam.foul_cycles                    = p_sparam.foul_cycles;
	sparam.foul_detect_probability        = p_sparam.foul_detect_probability;
	sparam.foul_exponent                  = p_sparam.foul_exponent;
	sparam.free_kick_faults               = p_sparam.free_kick_faults;
	sparam.freeform_send_period           = p_sparam.freeform_send_period;
	sparam.freeform_wait_period           = p_sparam.freeform_wait_period;
	sparam.fullstate_l                    = p_sparam.fullstate_l;
	sparam.fullstate_r                    = p_sparam.fullstate_r;
	sparam.game_log_compression           = p_sparam.game_log_compression;
	sparam.game_log_dated                 = p_sparam.game_log_dated;
	sparam.game_log_dir                   = p_sparam.game_log_dir;
	sparam.game_log_fixed                 = p_sparam.game_log_fixed;
	sparam.game_log_fixed_name            = p_sparam.game_log_fixed_name;
	sparam.game_log_version               = p_sparam.game_log_version;
	sparam.game_logging                   = p_sparam.game_logging;
	sparam.game_over_wait                 = p_sparam.game_over_wait;
	sparam.goal_width                     = p_sparam.goal_width;
	sparam.goalie_max_moves               = p_sparam.goalie_max_moves;
	sparam.golden_goal                    = p_sparam.golden_goal;
	sparam.half_time                      = p_sparam.half_time;
	sparam.hear_decay                     = p_sparam.hear_decay;
	sparam.hear_inc                       = p_sparam.hear_inc;
	sparam.hear_max                       = p_sparam.hear_max;
	sparam.inertia_moment                 = p_sparam.inertia_moment;
	sparam.keepaway                       = p_sparam.keepaway;
	sparam.keepaway_length                = p_sparam.keepaway_length;
	sparam.keepaway_log_dated             = p_sparam.keepaway_log_dated;
	sparam.keepaway_log_dir               = p_sparam.keepaway_log_dir;
	sparam.keepaway_log_fixed             = p_sparam.keepaway_log_fixed;
	sparam.keepaway_log_fixed_name        = p_sparam.keepaway_log_fixed_name;
	sparam.keepaway_logging               = p_sparam.keepaway_logging;
	sparam.keepaway_start                 = p_sparam.keepaway_start;
	sparam.keepaway_width                 = p_sparam.keepaway_width;
	sparam.kick_off_wait                  = p_sparam.kick_off_wait;
	sparam.kick_power_rate                = p_sparam.kick_power_rate;
	sparam.kick_rand                      = p_sparam.kick_rand;
	sparam.kick_rand_factor_l             = p_sparam.kick_rand_factor_l;
	sparam.kick_rand_factor_r             = p_sparam.kick_rand_factor_r;
	sparam.kickable_margin                = p_sparam.kickable_margin;
	sparam.landmark_file                  = p_sparam.landmark_file;
	sparam.log_date_format                = p_sparam.log_date_format;
	sparam.log_times                      = p_sparam.log_times;
	sparam.max_back_tackle_power          = p_sparam.max_back_tackle_power;
	sparam.max_dash_angle                 = p_sparam.max_dash_angle;
	sparam.max_dash_power                 = p_sparam.max_dash_power;
	sparam.max_goal_kicks                 = p_sparam.max_goal_kicks;
sparam.max_tackle_power               = p_sparam.max_tackle_power;
	sparam.maxmoment                      = p_sparam.maxmoment;
	sparam.maxneckang                     = p_sparam.maxneckang;
	sparam.maxneckmoment                  = p_sparam.maxneckmoment;
	sparam.maxpower                       = p_sparam.maxpower;
	sparam.min_dash_angle                 = p_sparam.min_dash_angle;
	sparam.min_dash_power                 = p_sparam.min_dash_power;
	sparam.minmoment                      = p_sparam.minmoment;
	sparam.minneckang                     = p_sparam.minneckang;
	sparam.minneckmoment                  = p_sparam.minneckmoment;
	sparam.minpower                       = p_sparam.minpower;
	sparam.nr_extra_halfs                 = p_sparam.nr_extra_halfs;
	sparam.nr_normal_halfs                = p_sparam.nr_normal_halfs;
	sparam.offside_active_area_size       = p_sparam.offside_active_area_size;
	sparam.offside_kick_margin            = p_sparam.offside_kick_margin;
	sparam.olcoach_port                   = p_sparam.olcoach_port;
	sparam.old_coach_hear                 = p_sparam.old_coach_hear;
	sparam.pen_allow_mult_kicks           = p_sparam.pen_allow_mult_kicks;
	sparam.pen_before_setup_wait          = p_sparam.pen_before_setup_wait;
	sparam.pen_coach_moves_players        = p_sparam.pen_coach_moves_players;
	sparam.pen_dist_x                     = p_sparam.pen_dist_x;
	sparam.pen_max_extra_kicks            = p_sparam.pen_max_extra_kicks;
	sparam.pen_max_goalie_dist_x          = p_sparam.pen_max_goalie_dist_x;
	sparam.pen_nr_kicks                   = p_sparam.pen_nr_kicks;
	sparam.pen_random_winner              = p_sparam.pen_random_winner;
	sparam.pen_ready_wait                 = p_sparam.pen_ready_wait;
	sparam.pen_setup_wait                 = p_sparam.pen_setup_wait;
	sparam.pen_taken_wait                 = p_sparam.pen_taken_wait;
	sparam.penalty_shoot_outs             = p_sparam.penalty_shoot_outs;
	sparam.player_accel_max               = p_sparam.player_accel_max;
	sparam.player_decay                   = p_sparam.player_decay;
	sparam.player_rand                    = p_sparam.player_rand;
	sparam.player_size                    = p_sparam.player_size;
	sparam.player_speed_max               = p_sparam.player_speed_max;
	sparam.player_speed_max_min           = p_sparam.player_speed_max_min;
	sparam.player_weight                  = p_sparam.player_weight;
	sparam.point_to_ban                   = p_sparam.point_to_ban;
	sparam.point_to_duration              = p_sparam.point_to_duration;
	sparam.port                           = p_sparam.port;
	sparam.prand_factor_l                 = p_sparam.prand_factor_l;
	sparam.prand_factor_r                 = p_sparam.prand_factor_r;
	sparam.profile                        = p_sparam.profile;
	sparam.proper_goal_kicks              = p_sparam.proper_goal_kicks;
	sparam.quantize_step                  = p_sparam.quantize_step;
	sparam.quantize_step_l                = p_sparam.quantize_step_l;
	sparam.record_messages                = p_sparam.record_messages;
	sparam.recover_dec                    = p_sparam.recover_dec;
	sparam.recover_dec_thr                = p_sparam.recover_dec_thr;
	sparam.recover_init                   = p_sparam.recover_init;
	sparam.recover_min                    = p_sparam.recover_min;
	sparam.recv_step                      = p_sparam.recv_step;
	sparam.red_card_probability           = p_sparam.red_card_probability;
	sparam.say_coach_cnt_max              = p_sparam.say_coach_cnt_max;
	sparam.say_coach_msg_size             = p_sparam.say_coach_msg_size;
	sparam.say_msg_size                   = p_sparam.say_msg_size;
	sparam.send_comms                     = p_sparam.send_comms;
	sparam.send_step                      = p_sparam.send_step;
	sparam.send_vi_step                   = p_sparam.send_vi_step;
	sparam.sense_body_step                = p_sparam.sense_body_step;
	sparam.side_dash_rate                 = p_sparam.side_dash_rate;
	sparam.simulator_step                 = p_sparam.simulator_step;
	sparam.slow_down_factor               = p_sparam.slow_down_factor;
	sparam.slowness_on_top_for_left_team  = p_sparam.slowness_on_top_for_left_team;
	sparam.slowness_on_top_for_right_team = p_sparam.slowness_on_top_for_right_team;
	sparam.stamina_capacity               = p_sparam.stamina_capacity;
	sparam.stamina_inc_max                = p_sparam.stamina_inc_max;
	sparam.stamina_max                    = p_sparam.stamina_max;
	sparam.start_goal_l                   = p_sparam.start_goal_l;
	sparam.start_goal_r                   = p_sparam.start_goal_r;
	sparam.stopped_ball_vel               = p_sparam.stopped_ball_vel;
	sparam.synch_micro_sleep              = p_sparam.synch_micro_sleep;
	sparam.synch_mode                     = p_sparam.synch_mode;
	sparam.synch_offset                   = p_sparam.synch_offset;
	sparam.synch_see_offset               = p_sparam.synch_see_offset;
	sparam.tackle_back_dist               = p_sparam.tackle_back_dist;
	sparam.tackle_cycles                  = p_sparam.tackle_cycles;
	sparam.tackle_dist                    = p_sparam.tackle_dist;
	sparam.tackle_exponent                = p_sparam.tackle_exponent;
	sparam.tackle_power_rate              = p_sparam.tackle_power_rate;
	sparam.tackle_rand_factor             = p_sparam.tackle_rand_factor;
	sparam.tackle_width                   = p_sparam.tackle_width;
	sparam.team_actuator_noise            = p_sparam.team_actuator_noise;
	sparam.team_l_start                   = p_sparam.team_l_start;
	sparam.team_r_start                   = p_sparam.team_r_start;
	sparam.text_log_compression           = p_sparam.text_log_compression;
	sparam.text_log_dated                 = p_sparam.text_log_dated;
	sparam.text_log_dir                   = p_sparam.text_log_dir;
	sparam.text_log_fixed                 = p_sparam.text_log_fixed;
	sparam.text_log_fixed_name            = p_sparam.text_log_fixed_name;
	sparam.text_logging                   = p_sparam.text_logging;
	sparam.use_offside                    = p_sparam.use_offside;
	sparam.verbose                        = p_sparam.verbose;
	sparam.visible_angle                  = p_sparam.visible_angle;
	sparam.visible_distance               = p_sparam.visible_distance;
	sparam.wind_ang                       = p_sparam.wind_ang;
	sparam.wind_dir                       = p_sparam.wind_dir;
	sparam.wind_force                     = p_sparam.wind_force;
	sparam.wind_none                      = p_sparam.wind_none;
	sparam.wind_rand                      = p_sparam.wind_rand;
	sparam.wind_random                    = p_sparam.wind_random;

	M_msg_type = ClientParser::MT_SERVER_PARAM;
	M_sensorhandler->on_serverparam(sparam);
}

void 
PSBridge::h_player_param( ClientParser::PlayerParam const & p_pparam )
{
	Sensor::PlayerParam pparam;
	pparam.allow_mult_default_type              = p_pparam.allow_mult_default_type;
	pparam.catchable_area_l_stretch_max         = p_pparam.catchable_area_l_stretch_max;
	pparam.catchable_area_l_stretch_min         = p_pparam.catchable_area_l_stretch_min;
	pparam.dash_power_rate_delta_max            = p_pparam.dash_power_rate_delta_max;
	pparam.dash_power_rate_delta_min            = p_pparam.dash_power_rate_delta_min;
	pparam.effort_max_delta_factor              = p_pparam.effort_max_delta_factor;
	pparam.effort_min_delta_factor              = p_pparam.effort_min_delta_factor;
	pparam.extra_stamina_delta_max              = p_pparam.extra_stamina_delta_max;
	pparam.extra_stamina_delta_min              = p_pparam.extra_stamina_delta_min;
	pparam.foul_detect_probability_delta_factor = p_pparam.foul_detect_probability_delta_factor;
	pparam.inertia_moment_delta_factor          = p_pparam.inertia_moment_delta_factor;
	pparam.kick_power_rate_delta_max            = p_pparam.kick_power_rate_delta_max;
	pparam.kick_power_rate_delta_min            = p_pparam.kick_power_rate_delta_min;
	pparam.kick_rand_delta_factor               = p_pparam.kick_rand_delta_factor;
	pparam.kickable_margin_delta_max            = p_pparam.kickable_margin_delta_max;
	pparam.kickable_margin_delta_min            = p_pparam.kickable_margin_delta_min;
	pparam.new_dash_power_rate_delta_max        = p_pparam.new_dash_power_rate_delta_max;
	pparam.new_dash_power_rate_delta_min        = p_pparam.new_dash_power_rate_delta_min;
	pparam.new_stamina_inc_max_delta_factor     = p_pparam.new_stamina_inc_max_delta_factor;
	pparam.player_decay_delta_max               = p_pparam.player_decay_delta_max;
	pparam.player_decay_delta_min               = p_pparam.player_decay_delta_min;
	pparam.player_size_delta_factor             = p_pparam.player_size_delta_factor;
	pparam.player_speed_max_delta_max           = p_pparam.player_speed_max_delta_max;
	pparam.player_speed_max_delta_min           = p_pparam.player_speed_max_delta_min;
	pparam.player_types                         = p_pparam.player_types;
	pparam.pt_max                               = p_pparam.pt_max;
	pparam.random_seed                          = p_pparam.random_seed;
	pparam.stamina_inc_max_delta_factor         = p_pparam.stamina_inc_max_delta_factor;
	pparam.subs_max                             = p_pparam.subs_max;

	M_msg_type = ClientParser::MT_PLAYER_PARAM;
	M_sensorhandler->on_playerparam(pparam);
}

void 
PSBridge::h_player_type ( ClientParser::PlayerType const & p_ptype )
{
	Sensor::PlayerType ptype;
	ptype.id                       = (int)p_ptype.id;
	ptype.player_speed_max         = p_ptype.player_speed_max;
	ptype.stamina_inc_max          = p_ptype.stamina_inc_max;
	ptype.player_decay             = p_ptype.player_decay;
	ptype.inertia_moment           = p_ptype.inertia_moment;
	ptype.dash_power_rate          = p_ptype.dash_power_rate;
	ptype.player_size              = p_ptype.player_size;
	ptype.kickable_margin          = p_ptype.kickable_margin;
	ptype.kick_rand                = p_ptype.kick_rand;
	ptype.extra_stamina            = p_ptype.extra_stamina;
	ptype.effort_max               = p_ptype.effort_max;
	ptype.effort_min               = p_ptype.effort_min;
	ptype.kick_power_rate          = p_ptype.kick_power_rate;
	ptype.foul_detect_probability  = p_ptype.foul_detect_probability;
	ptype.catchable_area_l_stretch = p_ptype.catchable_area_l_stretch;

	M_msg_type = ClientParser::MT_PLAYER_TYPE;
	M_sensorhandler->on_playertype( ptype );
}

void 
PSBridge::h_see( ClientParser::See const & p_see )
{
	Sensor::See see;

	see.time = p_see.time;

	if( ClientParser::is_defined(see.time) )
		set_time( see.time );

	for( std::list<ClientParser::Player>::const_iterator i = p_see.players.begin(); 
		i != p_see.players.end(); ++i )
	{
		Sensor::Player player;
		player.team     = i->team_name;
		player.goalie   = i->goalie;
		player.behind   = i->mayus_form ? true : false;
		player.dist     = i->distance;
		player.dir      = i->direction;
		player.dist_chg = i->dist_change;
		player.dir_chg  = i->dir_change;
		player.bodydir  = i->body_facing_dir;
		player.headdir  = i->head_facing_dir;
		player.pointdir = i->pointing_dir;
		player.tackle   = i->tackle;
		player.kick     = i->kick;
		see.players.push_back( player );
	}

	for( std::list<ClientParser::Flag>::const_iterator i = p_see.flags.begin(); 
		i != p_see.flags.end(); ++i )
	{
		Sensor::Flag flag;
		flag.id   = cast_flagid( i->id );
		flag.dist = i->distance;
		flag.dir  = i->direction;
		//flag.dist_chg = i->dist_change;
		//flag.dir_chg = i->dir_change;
		flag.behind =  (i->id == ClientParser::FLAG_MAYUS || i->id == ClientParser::GOAL_MAYUS ) ?
					true : false;

		see.flags.push_back( flag );		
	}

	for (std::list<ClientParser::Line>::const_iterator i = p_see.lines.begin(); 
		i != p_see.lines.end(); ++i )
	{
		Sensor::Line line;
		line.id   = cast_lineid( i->id );
		line.dist = i->distance;
		line.dir  = i->direction;
	}

	if( ! p_see.balls.empty() )
	{
		see.ball.behind   = p_see.balls.begin()->mayus_form ? true: false;
		see.ball.dist     = p_see.balls.begin()->distance;
		see.ball.dir      = p_see.balls.begin()->direction;
		see.ball.dist_chg = p_see.balls.begin()->dist_change;
		see.ball.dir_chg   = p_see.balls.begin()->dir_change;
	}

	M_msg_type = ClientParser::MT_SEE;
	M_sensorhandler->on_see( see );
}

void 
PSBridge::h_sense_body( ClientParser::SenseBody const & p_body )
{
	Sensor::Body body;

	body.time                = p_body.time;

	if( ClientParser::is_defined(body.time) )
		set_time( body.time );

	body.viewmode_quality    = cast_viewquality( p_body.view_mode_quality );
	body.viewmode_width      = cast_viewwidth( p_body.view_mode_width );
	body.stamina_stamina     = p_body.stamina_stamina;
	body.stamina_effort      = p_body.stamina_effort;
	body.stamina_capacity    = p_body.stamina_capacity;
	body.speed_amount        = p_body.speed_amount;
	body.speed_direction     = p_body.speed_direction;
	body.headangle           = p_body.head_angle;
	body.kick_count          = p_body.kick_count;
	body.dash_count          = p_body.dash_count;
	body.turn_count          = p_body.turn_count;
	body.say_count           = p_body.say_count;
	body.turnneck_count      = p_body.turn_neck_count;
	body.catch_count         = p_body.catch_count;
	body.move_count          = p_body.move_count;
	body.changeview_count    = p_body.change_view_count;
	body.arm_movable         = p_body.arm_movable_cycles;
	body.arm_expires         = p_body.arm_expires_cycles;
	body.arm_target_dist     = p_body.arm_target_distance;
	body.arm_target_dir      = p_body.arm_target_direction;
	body.arm_count           = p_body.arm_count; 
	body.focus_target_side   = cast_side( p_body.focus_target );
	body.focus_target_number = p_body.focus_target_number;
	body.focus_count         = p_body.focus_count;
	body.tackle_expires      = p_body.tackle_expires_cycles;
	body.tackle_count        = p_body.tackle_count;
	body.foul_charged        = p_body.foul_charged_cycles;
	body.foul_card           = cast_foulcard( p_body.foul_card );
    // todo body.collisions..    

	M_msg_type = ClientParser::MT_SENSE_BODY;
	M_sensorhandler->on_body( body );
}

void 
PSBridge::h_hear( ClientParser::Hear const & p_hear )
{
	Sensor::Hear hear;

	hear.time     = p_hear.time;

	if( ClientParser::is_defined(hear.time) )
		set_time( hear.time );

	hear.sender   = cast_sender( p_hear.sender );
	hear.message  = p_hear.message;
	hear.playmode = cast_refereeevent( p_hear.playmode );
	hear.unum     = p_hear.unum;
	hear.dir      = p_hear.direction;
	hear.goals    = p_hear.goals;
	hear.cards    = p_hear.cards;

	M_msg_type = ClientParser::MT_HEAR;
	M_sensorhandler->on_hear( hear );
}

void 
PSBridge::h_error( ClientParser::Error const & p_err )
{
	Sensor::Error error ;
	error.type = cast_errortype( p_err.type );

	M_msg_type = ClientParser::MT_ERROR;
	M_sensorhandler->on_error( error );
}

void 
PSBridge::h_score( ClientParser::Score const & p_score )
{
	Sensor::Score score;
	score.ours   = p_score.ours;
	score.theirs = p_score.theirs;
	M_msg_type = ClientParser::MT_SCORE;
	M_sensorhandler->on_score( score );
}

void  
PSBridge::h_warning( ClientParser::Warning const & p_wrn )
{
	Sensor::Warning warning;
	warning.type = cast_warningtype( p_wrn.type );
	M_msg_type = ClientParser::MT_WARNING;
	M_sensorhandler->on_warning( warning );
}

void  
PSBridge::h_ok( ClientParser::Ok const & p_ok )
{
	Sensor::Ok ok;
	ok.type = Sensor::OK_UNKOWN;
	M_msg_type = ClientParser::MT_OK;
	M_sensorhandler->on_ok( ok );
}

void  
PSBridge::h_chg_player_type( ClientParser::ChgPlayerType const &  p_chg_pt )
{
	Sensor::ChgPlayerType chg_pt;
	chg_pt.unum = p_chg_pt.unum;
	chg_pt.type = p_chg_pt.type;
	M_msg_type = ClientParser::MT_CHANGE_PLAYER_TYPE;
	M_sensorhandler->on_changeplayertype( chg_pt );
}

Sensor::Playmode 
PSBridge::cast_playmode( ClientParser::Playmode playmode )
{
	return (Sensor::Playmode)playmode;
}

Sensor::Side 
PSBridge::cast_side( ClientParser::Side s )
{
 	return s == ClientParser::SIDE_LEFT ? Sensor::SIDE_LEFT : Sensor::SIDE_RIGHT;
}

Sensor::FlagId 
PSBridge::cast_flagid( ClientParser::FlagId fid )
{
	return (Sensor::FlagId)fid;
}

Sensor::LineId 
PSBridge::cast_lineid( ClientParser::LineId lid )
{
	return (Sensor::LineId)lid;
}


Sensor::ViewQuality 
PSBridge::cast_viewquality( ClientParser::ViewQuality vq )
{
	return (Sensor::ViewQuality)vq;
}

Sensor::ViewWidth 
PSBridge::cast_viewwidth( ClientParser::ViewWidth vw )
{
	return (Sensor::ViewWidth)vw;
}

Sensor::FoulCard 
PSBridge::cast_foulcard( ClientParser::FoulCard fc )
{
	return (Sensor::FoulCard)fc;
}


Sensor::Sender 
PSBridge::cast_sender( ClientParser::Sender sender )
{
	return (Sensor::Sender)sender;
}

Sensor::RefereeEvent 
PSBridge::cast_refereeevent( ClientParser::PlaymodeHearable pmh ) 
{
	return (Sensor::RefereeEvent)pmh;
}

Sensor::ErrorType 
PSBridge::cast_errortype( ClientParser::ErrorType errt )

{
	return (Sensor::ErrorType)errt;
}

Sensor::WarningType 
PSBridge::cast_warningtype( ClientParser::WarningType wrnt )
{
	return (Sensor::WarningType)wrnt;
}

void 
PSBridge::set_time( int time )
{
	if( M_time != time )
	{	
		M_time = time;
		M_sensorhandler->on_timechange( M_time );
	}
}