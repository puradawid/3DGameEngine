#ifndef SIMPLEPOINT_H
#define SIMPLEPOINT_H

#ifdef _MSC_VER
	#include <Windows.h>
#endif

#include <Gl/gl.h>
#include <math.h>

#define M_PI 3.14

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

	SimplePoint rotate(SimplePoint p)
	{
		SimplePoint r(*this);
		double rad_x = p.x * (180/M_PI);
		double rad_y = p.y * (180/M_PI);
		double rad_z = p.z * (180/M_PI);

		//rotate z
		r.x = x * cos(rad_z) + y * sin(rad_z);
		r.y = -x * sin(rad_z) + y * cos(rad_z);

		//rotate x
		r.y = y * cos(rad_x) + z * sin(rad_x);
		r.z = -y * sin(rad_x) + z * cos(rad_x);

		//rorate y
		r.x = x * cos(rad_y) - z * sin(rad_y);
		r.z = x * sin(rad_y) + z * cos(rad_y);

		return r; 

	}

	SimplePoint translate(SimplePoint p)
	{
		SimplePoint r(*this);
		
		r = r + p;
		
		return r;
	}

	SimplePoint scale(SimplePoint p)
	{
		SimplePoint r(*this);
		
		r.x = p.x * r.x;
		r.y = p.y * r.y;
		r.z = p.z * r.z;

		return r;
	}
} typedef SimplePoint;

#endif
