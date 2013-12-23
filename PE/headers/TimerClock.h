#ifndef TIMERCLOCK_H
#define TIMERCLOCK_H

#include "Timer.h"

class TimerClock
{
	std::vector<Timer*> timers;
public:
	void addTimer(Timer*);
	void dismissTimer(Timer*);
};

#endif
