#ifndef TIMER_H
#define TIMER_H

#include <GL/gl.h>

class Timer
{
	GLint interval;
	GLint ticks;
public:
	virtual void tick();
};

#endif