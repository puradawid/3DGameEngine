#ifndef SIMPLEPOINT_H
#define SIMPLEPOINT_H
#ifdef _MSC_VER
#include <Windows.h>
#endif
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

	SimplePoint operator+(SimplePoint p)
	{
		SimplePoint result;
		result.x = this->x + p.x;
		result.y = this->y + p.y;
		result.z = this->z + p.z;
		return result;
	}
} typedef SimplePoint;

#endif
