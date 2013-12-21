#ifndef COMMANDTIMER_H
#define COMMANDTIMER_H

#include "PECommand.h"

class CommandTimer
{
	PECommand* command;
public:
	CommandTimer(PECommand*);
	virtual void tick();
};

#endif