#ifndef TIMERCLOCK_H
#define TIMERCLOCK_H

#include <vector>

#include "Timer.h"
//#include "Game.h"

class TimerClock
{
	std::vector<Timer*> timers;
	friend void msTick();
	friend class Timer;
	friend class Game;
	void inform(int); //method to inform TimerClock what time is up already
	TimerClock();
public:
	void addTimer(Timer*);
	void dismissTimer(Timer*);
};

#endif
