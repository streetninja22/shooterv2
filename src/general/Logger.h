#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <ctime>
#include "filesystem.h"


#include <iostream>

//TODO: documentation comments, exception handling

class Logger
{
private:
    static std::string m_logDirPath;

    std::ofstream m_logFile;

    static const unsigned int M_MAX_TIME_STRING_LENGTH = 100;


    std::string getTime();

    std::string getFileSafeTime();

public:
    Logger(std::string logDirPath);


    /* Writes given data to end of log file, accompanied with the time of the function's call
    *
    */
    void log(std::string logData);

};


#endif
