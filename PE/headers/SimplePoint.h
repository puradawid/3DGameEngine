#ifndef SIMPLEPOINT_H
#define SIMPLEPOINT_H

#include <Gl/gl.h>

struct SimplePoint
{
	GLdouble x,y,z;

	SimplePoint(GLdouble x, GLdouble y, GLdouble z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	SimplePoint()
	{
		this->x = 0.0;
		this->y = 0.0;
		this->z = 0.0;
	}
} typedef SimplePoint;

#endif
