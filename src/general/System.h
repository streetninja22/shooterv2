#ifndef SYSTEM_H
#define SYSTEM_H
#include "general/Logger.h"

class System
{
protected:
    Logger* m_logger;

public:
	System(Logger* logger) : m_logger(logger)
	{
	}

	virtual void update() = 0;

};


#endif
