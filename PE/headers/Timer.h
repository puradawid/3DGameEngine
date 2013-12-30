#ifndef TIMER_H
#define TIMER_H
#ifdef _MSC_VER
#include <Windows.h>
#endif
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