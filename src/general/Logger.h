#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <ctime>
#include "filesystem.h"


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


    /* Writes given data to end of log file, accompanied with the time of the function's call
    *
    */
    static void log(std::string logData);

};


#endif
