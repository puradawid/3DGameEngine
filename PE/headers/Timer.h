#ifndef TIMER_H
#define TIMER_H

#include <GL/gl.h>

class Timer
{
	friend class TimerClock;

	GLint interval;
	GLint ticks;
	GLint left;
public:
	Timer(int, int);
	virtual void tick() {};
};

#endif