/** \file 
 * \brief Thread-safe shared logging functionality
 */
 /*
 *        File: log.h
 *  Created on: April 27, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

#ifndef LOG_H_
#define LOG_H_

namespace Log
{

	enum Level
	{
		DEBUG = 0,
		INFO = 1,
		WARNING = 2,
		ERROR = 3,
		FATAL = 4
	};

	extern FILE * 			_stream;
	extern Level 			_level;
	extern pthread_mutex_t _mutex;
	extern std::string 		_signature;

	void  	init		();

	void 	term		();

	void	set_stream	( FILE * f );

	void 	set_level 	( Level level );

	void 	set_signature( std::string sign );

	void 	out 		( Level level, const char * fmt, ... );
	

	const char * level_text ( Level level );

}


#endif /* LOG_H_ */


