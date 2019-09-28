#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <ctime>
#include "filesystem.h"

#include <SDL2/SDL.h>


#include <iostream>

//TODO: exception handling

typedef std::string str;

class Logger
{
private:
    static std::string m_logDirPath;

    static std::ofstream m_logFile;

    static const unsigned int M_MAX_TIME_STRING_LENGTH = 100;

	/* Returns the current date and time as a string
	*/
    static std::string getTime();

    /* Returns a the current date and time in a format safe to use for filenames
    */
    static std::string getFileSafeTime();

public:
    Logger(std::string logDirPath);

	/* Closes the log file. Use when program is finished running
	* 
	*/
	static void close();

    /* Writes given data to end of log file, accompanied with the time of the function's call
    *
    */
    static void log(std::string logData);

	/* Writes given data to end of log file, accompanied with the time of the function's call and the suffix for an error message
	*
	*/
	static void logError(std::string logData);

	/* Writes given data to end of log file, accompanied with the time of the function's call, the suffix for an error message, and lead by SDL error output
	*
	*/
	static void logSDLError(std::string logData);

};


#endif
