#ifndef OBJBUILDER_H

#define OBJBUILDER_H

#include <vector>
#include <GL/gl.h>

#include "../headers/Point.h"

class OBJBuilder
{
public:
	struct SimplePoint
		{
			GLdouble x,y,z;

			SimplePoint(GLdouble x, GLdouble y, GLdouble z)
			{
				this->z = z;
				this->x = x;
				this->y = y;
			}
		} typedef SimplePoint;
	struct IndexedPoint
	{
		GLint v,n,t;
		IndexedPoint(GLint v, GLint t, GLint n)
		{
			this->v = v;
			this->t = t;
			this->n = n;
		}

		IndexedPoint()
		{
			this->v = 0;
			this->t = 0;
			this->n = 0;
		}
	} typedef IndexedPoint;
	struct Triangle
	{
		IndexedPoint a, b, c;

		Triangle(IndexedPoint a, IndexedPoint b, IndexedPoint c)
		{
			this->a = a;
			this->b = b;
			this->c = c;
		}
	} typedef Triangles;

protected:
	std::vector<std::vector<Point>* > meshes;
	std::vector<SimplePoint> normals;
	std::vector<SimplePoint> vertexes;
	std::vector<SimplePoint> textures;
	std::vector<Triangle> triangles;
public:
	OBJBuilder(char*);	//retrieve object
	std::vector<std::vector<Point>*>* build();			//construct new instance of object
};

#endif
