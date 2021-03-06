#include "../headers/Figure3D.h"
#include "../headers/Point.h"

#include <stdio.h>


using namespace std;

Figure3D::Figure3D() {
}

Figure3D::Figure3D(const Figure3D& orig) {
}

Figure3D::~Figure3D() {
}

void Figure3D::setRenderStrategy(GLRenderStrategy *rs)
{
	this->rs = rs;
}

void Figure3D::render()
{
	unsigned int polygons_size = polygons.size();
	for(unsigned int i = 0; i < polygons_size; i++)
		this->rs->renderPolygon(&polygons[i]);
}

void Figure3D::addPolygon(Point** points, int size)
{
    if(size < 0 || points == 0x00) return;
    vector<Point*> *new_points = new vector<Point*>(size);
    for(int i=0; i < size; i++)
        (*new_points)[i] = new Point(*(points[i]));
    polygons.push_back((*new_points));
}

void Figure3D::cleanPolygons()
{
    polygons.clear();
}

void Figure3D::moveFigure(double x, double y, double z)
{
	pos_.x += x;
	pos_.y += y;
	pos_.z += z;
}

void Figure3D::rotateFigure(GLdouble x, GLdouble y, GLdouble z)
{
	rotation.x += x;
	rotation.y += y;
	rotation.z += z;
}
