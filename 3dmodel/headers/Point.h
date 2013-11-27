#ifndef POINT_H
#define	POINT_H

struct Point3D
{
	double x,y,z;
	struct Normal {
		double x,y,z;
	} normal;
	struct Texture
	{
		double x,y,z;
	} texture;

	Point3D(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
}typedef Point;


#endif	/* POINT_H */

