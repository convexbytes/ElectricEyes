/************************************************************/
/*	Author:			Gilberto Monroy Aguilar					*/
/*	Creation date: 	Monday 09-Dec-2013						*/
/*	Purpose: 		Implements the basic driver which   	*/
/*					serves as usage sample					*/
/*															*/
/************************************************************/


#include <cstdio>
#include "client_parser_driver.h"
#include "client_lexer.h"
#include "location.hh"

using namespace ClientParser;

/* This may be the more important method of the example */
/* (that's why I put it even before constructor) */
/* Parses a char * string. Usually, flex creates a parser that reads for the standard input,  */
/* so we need to create a temporal buffer and tell flex to use that buffer (instead of stdin) */

MessageType 
SimpleDriver::parse ( const char * msg )
{

	/* Scan the string with flex and save the state to delete when finished */
	YY_BUFFER_STATE bs = yy_scan_string( msg );
	yy_switch_to_buffer( bs );

	/* Parse the string */
	_parser->parse();

	/* Delete the buffer */
	yy_delete_buffer( bs );

	/* The message type has been set at this point by the overriden virtual methods */
	return _msg_type;
}

MessageType 
SimpleDriver::parse ( std::string  msg )
{
	return this->parse( msg.c_str() );
}


SimpleDriver::SimpleDriver ()
{
	/* Allocate the parser */
	_parser   = NULL;
	_parser   = new yy::RcssParser( *this );
	_msg_type = MT_INVALID_MESSAGE;
	if( _parser == NULL )
	{
		std::cerr << "SimpleDriver: parser could not be allocated" << std::endl;
		exit(-1);
	}
}

SimpleDriver::~SimpleDriver ()
{
	if( _parser )
		delete _parser;
	_parser = 0;
}


void		
SimpleDriver::error ( const yy::RcssParser::location_type & l,
					const std::string  &m )
{
	_msg_type = MT_INVALID_MESSAGE;
}


void
SimpleDriver::h_init ( Init const & init )
{
	_init = init;
	_msg_type = MT_INIT;
}

void 
SimpleDriver::h_server_param ( ServerParam const & sp )
{
	_server_param = sp;
	_msg_type = MT_SERVER_PARAM;
}

void 
SimpleDriver::h_player_param ( PlayerParam const & pp )
{
	_player_param = pp;
	_msg_type = MT_PLAYER_PARAM;
}

void 
SimpleDriver::h_player_type ( PlayerType const & pt )
{
	_player_type = pt;
	_msg_type = MT_PLAYER_TYPE;
}

void 
SimpleDriver::h_see ( See const & see )
{
	_see = see;
	_msg_type = MT_SEE;
}

void 
SimpleDriver::h_sense_body ( SenseBody const & sb )
{
	_sense_body = sb;
	_msg_type = MT_SENSE_BODY;
}

void 
SimpleDriver::h_hear ( Hear const & hear  )
{
	_hear = hear;
	_msg_type = MT_HEAR;
}

void 
SimpleDriver::h_error ( Error const & e )
{
	_error = e;
	_msg_type = MT_ERROR;
}

void		
SimpleDriver::h_score ( Score const & sc  )
{
	_score = sc;
	_msg_type = MT_SCORE;
}

void 		
SimpleDriver::h_warning ( Warning const & w )
{
	_warning = w;
	_msg_type = MT_WARNING;
}

void 		
SimpleDriver::h_ok ( Ok const & ok )
{
	_ok = ok;
	_msg_type = MT_OK;
}

void 		
SimpleDriver::h_chg_player_type ( ChgPlayerType const & cpt )
{
	_chg_player_type = cpt;
	_msg_type = MT_CHANGE_PLAYER_TYPE;
}


ClientParser::MessageType 
SimpleDriver::getMessageType() const
{
	return _msg_type;
}

ClientParser::Init 			const & 
SimpleDriver::getInit() const
{
	return _init;
}

ClientParser::ServerParam 	const & 
SimpleDriver::getServerParam() const
{
	return _server_param;
}

ClientParser::PlayerParam 	const & 
SimpleDriver::getPlayerParam() const
{
	return _player_param;
}

ClientParser::PlayerType 	const & 
SimpleDriver::getPlayerType() const
{
	return _player_type;
}

ClientParser::See 			const & 
SimpleDriver::getSee() const
{
	return _see;
}

ClientParser::SenseBody 	const & 
SimpleDriver::getSenseBody() const
{
	return _sense_body;
}

ClientParser::Hear 			const & 
SimpleDriver::getHear() const
{
	return _hear;
}

ClientParser::Error 		const & 
SimpleDriver::getError() const
{
	return _error;
}

ClientParser::Score 		const & 
SimpleDriver::getScore() const
{
	return _score;
}

ClientParser::Warning 		const & 
SimpleDriver::getWarning() const
{
	return _warning;
}

ClientParser::Ok 			const & 
SimpleDriver::getOk() const
{
	return _ok;
}

ClientParser::ChgPlayerType const & 
SimpleDriver::getChgPlayerType() const
{
	return _chg_player_type;
}


/*
int main(int argc, char const *argv[])
{
	const char * msg = "(see 238 ((f c) 47.5 2.3e+3) ((f c t) 57.4 -13) ((f r t) 105.6 3) ((f g r b) 100.5 26) ((g r) 100.5 22) ((f g r t) 100.5 18) ((f p r c) 83.9 22) ((f p r t) 85.6 8) ((f p l c) 11.7 29 0 0.5) ((f t 0) 60.3 -17) ((f t r 10) 68.7 -12) ((f t r 20) 77.5 -8) ((f t r 30) 86.5 -5) ((f t r 40) 95.6 -2) ((f t r 50) 104.6 0) ((f t l 10) 53 -24) ((f r 0) 105.6 22) ((f r t 10) 105.6 16) ((f r t 20) 106.7 11) ((f r t 30) 108.9 6) ((f r b 10) 105.6 27) ((b) 33.1 0) ((p \"PokTaPok\" 2) 27.1 -25 -0 0.1 130 130) ((p \"PokTaPok\" 3) 20.1 4 -0 0.3 15 15) ((p \"PokTaPok\") 33.1 -7) ((p \"PokTaPok\" 7) 33.1 15 -0 0.2 -63 -63) ((p \"PokTaPok\") 44.7 8) ((p) 90 21) ((p \"HELIOS2012\") 49.4 21) ((p) 54.6 20) ((p) 54.6 3) ((p \"HELIOS2012\") 36.6 26) ((p \"HELIOS2012\") 40.4 11) ((p \"HELIOS2012\") 33.1 0 -178 k) ((p \"HELIOS2012\") 27.1 21) ((l t) 90.9 21))";
	SimpleDriver driver;
	if( driver.parse( msg ) == MT_INVALID_MESSAGE )
		printf( "Invalid message\n." );
	else 
		printf( "Message Ok\n." );
	return 0;
}
*/
