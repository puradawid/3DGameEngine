#include "../headers/TimerClock.h"

TimerClock::TimerClock()
{
	//initialize TimerClock class
}

void TimerClock::addTimer(Timer* timer)
{
	timers.push_back(timer);
}

void TimerClock::dismissTimer(Timer* timer)
{
	int pos = -1;
	for(int i = 0; i < timers.size(); i++)
		if(timers[i] == timer) pos = i;
	timers.erase(timers.begin() + pos); //remove element from position pos
}

void TimerClock::inform(int ms_left)
{
	for(Timer* timer : timers)
	{
		timer->left -= ms_left;
		if(timer->left < 0)
		{	
			timer->tick();
			timer->left = timer->interval;
		}

	}
}