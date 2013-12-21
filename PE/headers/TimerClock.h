#ifndef TIMERCLOCK_H
#define TIMERCLOCK_H

class TimerClock
{
	std::vector<Timer*> timers;
public:
	void addTimer(Timer*);
	void dismissTimer(Timer*);
};

#endif