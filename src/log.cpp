 /*
 *        FILE: log.cpp
 *  Created on: April 27, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

namespace Log
{
	FILE * 		_stream;
	Level  _level;
	pthread_mutex_t _mutex;
	std::string _signature;
}

void Log::init()
{
	pthread_mutex_init( &Log::_mutex, NULL );
}

void Log::term()
{
	pthread_mutex_destroy( &Log::_mutex );
}

void Log::set_level( Level level )
{
	Log::_level = level;
}

void Log::set_stream( FILE * stream )
{
	Log::_stream = stream;
}

void Log::set_signature( std::string sign )
{
	_signature = sign;
}

void Log::out  ( Level level, const char * fmt, ... )
{
	if( level < Log::_level || Log::_stream == NULL ) 
		return;

	time_t  t = 0;
	char date_time[32];
	time( &t );
	va_list arglist;
	va_start 	( arglist, fmt );
	pthread_mutex_lock( &Log::_mutex );
		struct tm * timeinfo = localtime (&t);
		strftime( date_time, 32, "%Y-%m-%d %T %Z" , timeinfo );
		
		fprintf 	( Log::_stream, "%s ", date_time );
		fprintf 	( Log::_stream, "%s ", Log::level_text(level));
		fprintf 	( Log::_stream, "%s: ", Log::_signature.c_str() );
		vfprintf 	( Log::_stream, fmt, arglist );
		fflush		( Log::_stream );
	pthread_mutex_unlock( &Log::_mutex );
	va_end 		( arglist );
}

const char * 
Log::level_text( Level level )
{
	static const char * LEVELS[] = { "[Debug]", "[Info]", 
		"[Warning]", "[Error]", "[Fatal]" };

	return LEVELS[level];
}
