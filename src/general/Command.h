#ifndef COMMAND_H
#define COMMAND_H

#include <functional>

class Command
{
public:
	virtual void execute() = 0;

	void operator();
};


#endif
