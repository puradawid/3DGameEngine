#ifndef SIMPLEPOINT_H
#define SIMPLEPOINT_H

struct SimplePoint
{
	GLdouble x,y,z;

	struct SimplePoint(GLdouble x, GLdouble y, GLdouble z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
} typedef SimplePoint;

#endif