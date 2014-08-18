/************************************************************/
/*	Author:			Gilberto Monroy Aguilar					*/
/*	Creation date: 	Monday 09-Dec-2013						*/
/*	Purpose: 		Gives an interface to call the parser 	*/
/*					and retreive obtained values			*/
/*															*/
/************************************************************/


#ifndef RCSS_DRIVER
#define RCSS_DRIVER

#include <iostream>
#include <string>
#include <map>

#include "client_parser_types.h"
#include "client_parser.tab.hh"

/* Tell Flex the lexer’s prototype */
#define YY_DECL yy::RcssParser::symbol_type yylex ( ClientParser::Driver & driver )
/* And declare it for the parser to know. */
YY_DECL;

namespace ClientParser
{

typedef yy::RcssParser Parser;
	
class Driver
{
public:
				Driver	() {}
	virtual 	~Driver	() {}

	virtual		void		error ( const yy::RcssParser::location_type & l,
									const std::string  &m ) = 0;
	virtual		void		h_init 				( ClientParser::Init 			const &  ) = 0;
	virtual		void		h_server_param 		( ClientParser::ServerParam 	const &  ) = 0;
	virtual		void		h_player_param 		( ClientParser::PlayerParam 	const &  ) = 0;
	virtual		void		h_player_type 		( ClientParser::PlayerType 		const &  ) = 0;
	virtual		void		h_see 				( ClientParser::See 			const &  ) = 0;
	virtual		void		h_sense_body 		( ClientParser::SenseBody 		const &  ) = 0;
	virtual		void		h_hear 				( ClientParser::Hear 			const &  ) = 0;
	virtual		void		h_error 			( ClientParser::Error 			const &  ) = 0;
	virtual		void		h_score 			( ClientParser::Score 			const &  ) = 0;
	virtual		void 		h_warning 			( ClientParser::Warning 		const &  ) = 0;
	virtual		void 		h_ok 				( ClientParser::Ok 				const &  ) = 0;
	virtual		void 		h_chg_player_type 	( ClientParser::ChgPlayerType 	const &  ) = 0;
};


/* An example of how to use the driver */
/* Simply makes a copy of the data received and put it available for retrieval */
class ParsedData
{
public:
	virtual ~ParsedData() {}
	virtual ClientParser::MessageType 		  getMessageType() const = 0;
	virtual ClientParser::Init 			const & getInit() const = 0;
	virtual ClientParser::ServerParam 	const & getServerParam() const = 0;
	virtual ClientParser::PlayerParam 	const & getPlayerParam() const = 0;
	virtual ClientParser::PlayerType 	const & getPlayerType() const = 0;
	virtual ClientParser::See 			const & getSee() const = 0;
	virtual ClientParser::SenseBody 	const & getSenseBody() const = 0;
	virtual ClientParser::Hear 			const & getHear() const = 0;
	virtual ClientParser::Error 		const & getError() const = 0;
	virtual ClientParser::Score 		const & getScore() const = 0;
	virtual ClientParser::Warning 		const & getWarning() const = 0;
	virtual ClientParser::Ok 			const & getOk() const = 0;
	virtual ClientParser::ChgPlayerType const & getChgPlayerType() const = 0;
};

class SimpleDriver
	: public Driver,
	 public ParsedData
{

public:
	SimpleDriver();
	virtual ~SimpleDriver();
	
	ClientParser::MessageType parse ( const char * msg );
	ClientParser::MessageType parse ( std::string  msg );

public:
	virtual ClientParser::MessageType 		  getMessageType() const;
	virtual ClientParser::Init 			const & getInit() const;
	virtual ClientParser::ServerParam 	const & getServerParam() const;
	virtual ClientParser::PlayerParam 	const & getPlayerParam() const;
	virtual ClientParser::PlayerType 	const & getPlayerType() const;
	virtual ClientParser::See 			const & getSee() const;
	virtual ClientParser::SenseBody 	const & getSenseBody() const;
	virtual ClientParser::Hear 			const & getHear() const;
	virtual ClientParser::Error 		const & getError() const;
	virtual ClientParser::Score 		const & getScore() const;
	virtual ClientParser::Warning 		const & getWarning() const;
	virtual ClientParser::Ok 			const & getOk() const;
	virtual ClientParser::ChgPlayerType const & getChgPlayerType() const;



	virtual		void		error 				( const yy::RcssParser::location_type & l,
													const std::string  &m );

	virtual		void		h_init 				( ClientParser::Init 			const &  );
	virtual		void		h_server_param 		( ClientParser::ServerParam 	const &  );
	virtual		void		h_player_param 		( ClientParser::PlayerParam 	const &  );
	virtual		void		h_player_type 		( ClientParser::PlayerType 		const &  );
	virtual		void		h_see 				( ClientParser::See 			const &  );
	virtual		void		h_sense_body 		( ClientParser::SenseBody 		const &  );	
	virtual		void		h_hear 				( ClientParser::Hear 			const &  );
	virtual		void		h_error 			( ClientParser::Error 			const &  );
	virtual		void		h_score 			( ClientParser::Score 			const &  );
	virtual		void 		h_warning 			( ClientParser::Warning 		const &  );
	virtual		void 		h_ok 				( ClientParser::Ok 				const &  );
	virtual		void 		h_chg_player_type 	( ClientParser::ChgPlayerType 	const &  );



private:
	yy::RcssParser 					*_parser;

	ClientParser::MessageType 		 _msg_type;
	ClientParser::Init 			_init;
	ClientParser::ServerParam 	_server_param;
	ClientParser::PlayerParam 	_player_param;
	ClientParser::PlayerType 	_player_type;
	ClientParser::See 			_see;
	ClientParser::SenseBody 	_sense_body;
	ClientParser::Hear 			_hear;
	ClientParser::Error 		_error;
	ClientParser::Score 		_score;
	ClientParser::Warning 		_warning;
	ClientParser::Ok 			_ok;
	ClientParser::ChgPlayerType _chg_player_type;
};



// class EDriver
// {
// public:
	
// 	virtual void see( player, info );
// 	virtual void see( ball, info );
// 	virtual void see( line, info );
// 	virtual void see( flag, info );
// 	virtual void body( int time ) = 0;
// 	virtual void body_viewmode( quality, width );
// 	virtual void body_stamina( stamina, effort, capacity);
// 	virtual void body_speed( amount, direction );
// 	virtual void body_headang( headangle);
// 	virtual void body_kick( count );
// 	virtual void body_dash( count );
// 	virtual void body_turn( count );
// 	virtual void body_say( count );
// 	virtual void body_turnneck( count );
// 	virtual void body_catch( count );
// 	virtual void body_move( count );
// 	virtual void body_changeview( count );
// 	virtual void body_arm( movable, expires, target, count );
// 	virtual void body_focus( target, count );
// 	virtual void body_tackle( expires, count );
// 	virtual void body_collission( Collision collision ) = 0;
// 	virtual void body_collission( std::string unkown ) = 0;
// 	virtual void hear_referee( int time, Sender sender, int num1 ) = 0;
// 	virtual void hear_player( int time, Sender sender, double direction, std::string msg ) = 0;
// 	//virtual void hear_cl( int time, sender, std::string message );
// 	//virtual void hear_cr( int time, sender, std::string message );
// 	virtual void err( ErrorType err_type ) = 0;
// 	virtual void err( std::sting unkown ) = 0;
// 	virtual void scr( int ours, int theirs ) = 0;
// 	virtual void wrn( WarningType wrn_type ) = 0;
// 	virtual void wrn( std::string unkown ) = 0;
// 	virtual void ok( std::string unkown ) = 0;
// 	virtual void chpt( double unum, double type ) = 0;
// };


} /* END namespace ClientParser */

#endif
