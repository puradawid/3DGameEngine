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
} typedef SimplePoint;

#endif
