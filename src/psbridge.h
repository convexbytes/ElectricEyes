/*
 *        FILE: psbridge.cpp
 *  Created on: July, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

#ifndef PS_BRIDGE_H
#define PS_BRIDGE_H

class PSBridge : public ClientParser::Driver
{
public:
    PSBridge();
    ~PSBridge();
    void set_sensorhandler( Sensor::Handler * sensorhandler );

    virtual	void error ( const yy::RcssParser::location_type & l,
                         const std::string  &m );
    virtual	void h_init 		( ClientParser::Init 			const &  init );
    virtual	void h_server_param ( ClientParser::ServerParam 	const &  serverparam );
    virtual	void h_player_param ( ClientParser::PlayerParam 	const &  playerparam );
    virtual	void h_player_type 	( ClientParser::PlayerType 		const &  playertype );
    virtual	void h_see 			( ClientParser::See 			const &  see );
    virtual	void h_sense_body 	( ClientParser::SenseBody 		const &  sensebody );
    virtual	void h_hear 		( ClientParser::Hear 			const &  hear );
    virtual	void h_error 		( ClientParser::Error 			const &  error );
    virtual	void h_score 		( ClientParser::Score 			const &  score );
    virtual	void h_warning 		( ClientParser::Warning 		const &  warning );
    virtual	void h_ok 			( ClientParser::Ok 				const &  ok );
    virtual	void h_chg_player_type 	( ClientParser::ChgPlayerType 	const &  chg_pt );

    static Sensor::Playmode cast_playmode( ClientParser::Playmode );
    static Sensor::Side cast_side( ClientParser::Side s );
    static Sensor::FlagId cast_flagid( ClientParser::FlagId fid );
    static Sensor::LineId cast_lineid( ClientParser::LineId lid );
    static Sensor::ViewQuality cast_viewquality( ClientParser::ViewQuality vq );
    static Sensor::ViewWidth cast_viewwidth( ClientParser::ViewWidth vw );
    static Sensor::FoulCard cast_foulcard( ClientParser::FoulCard fc );
    static Sensor::Sender cast_sender( ClientParser::Sender sender );
    static Sensor::RefereeEvent cast_refereeevent( ClientParser::PlaymodeHearable pmh );
    static Sensor::ErrorType cast_errortype( ClientParser::ErrorType errt );
    static Sensor::WarningType cast_warningtype( ClientParser::WarningType wrnt );

    ClientParser::MessageType parse( std::string s );
    ClientParser::MessageType parse( const char * s );
private:
    void set_time( int time );

    Sensor::Handler * M_sensorhandler;
    int M_time;
    ClientParser::Parser *M_parser;
    ClientParser::MessageType M_msg_type;
};

namespace Sensor
{

}

#endif