#include "Logger.h"


//static member declarations
std::string Logger::m_logDirPath;

std::ofstream Logger::m_logFile;

const unsigned int M_MAX_TIME_STRING_LENGTH = 100;


std::string Logger::getTime()
{
        const time_t time = std::time(nullptr);
        char timeString[M_MAX_TIME_STRING_LENGTH];
        //convert unix time stamp to standard time format
        std::strftime(timeString, sizeof(timeString), "%c", std::localtime(&time));
        return std::string(timeString);
    }

    std::string Logger::getFileSafeTime()
    {
        const time_t time = std::time(nullptr);
        char timeString[M_MAX_TIME_STRING_LENGTH];
        //convert unix time stamp to month-day-year_hour-minute-second format
        std::strftime(timeString, sizeof(timeString), "%m-%d-%Y_%H-%M-%S", std::localtime(&time));
        return std::string(timeString);
    }

    Logger::Logger(std::string logDirPath)
    {
        m_logDirPath = logDirPath;

        std::string filename = std::string(logDirPath + "logfile_" + getFileSafeTime() + ".txt");
        m_logFile.open(filename.c_str(), std::fstream::out);
    }


	void Logger::close()
	{
		m_logFile.close();
	}

    /* Writes given data to end of log file, accompanied with the time of the function's call
    *
    */
    void Logger::log(std::string logData)
    {
        std::string newLine = getTime() + ": " + logData;
		if (newLine.back() != '\n')
			newLine.append("\n");
		m_logFile << newLine;
		m_logFile.flush();
    }

	void Logger::logError(std::string logData)
	{
		std::string newLine =  ": ERROR: " + logData;
		log(newLine);
	}

	void Logger::logSDLError(std::string logData)
	{
		std::string newLine =  logData + ": " + SDL_GetError();
		logError(newLine);
	}
