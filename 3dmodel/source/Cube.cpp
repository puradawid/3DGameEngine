#include <vector>
#include <iostream>

#include "../headers/Cube.h"
#include "../headers/Point.h"


using namespace std;

Cube::Cube() {
}

Cube::Cube(const Cube& orig) {
}

Cube::Cube(Point** points)
{
    this->points = vector<Point*>(8);
    for(int i=0; i < 8; i++)
        this->points[i] = points[i];
}

void printDebug(vector<Point*> &points)
{
    cout << "Point";
    for(int i=0; i < points.size(); i++)
        cout << points[0]->x << points[i]->y << points[i]->z << endl;
}

Cube::Cube(Point x, double width)
        : Figure3D()
{
    this->points = vector<Point*>(8);
    this->points[0] = new Point(x);
    this->points[1] = (Point*)new Point(x.x + width, x.y, x.z);
    this->points[2] = (Point*)new Point(x.x + width, x.y + width, x.z);
    this->points[3] = (Point*)new Point(x.x, x.y + width, x.z);
    this->points[4] = (Point*)new Point(x.x, x.y, x.z - width);
    this->points[5] = (Point*)new Point(x.x + width, x.y, x.z - width);
    this->points[6] = (Point*)new Point(x.x + width, x.y + width, x.z - width);
    this->points[7] = (Point*)new Point(x.x, x.y + width, x.z - width);
    //printDebug(points); //debug purpose
    createPolygons();
}

void addNormal(Point** point_list, int size, double x, double y, double z)
{
	for(int i = 0; i < size; i++)
	{
		point_list[i]->normal.x = x;
		point_list[i]->normal.y = y;
		point_list[i]->normal.z = z;
	}
}

Point** generateArray(int size)
{
	return new Point*[size];
}

void addElement(Point** array, int pos, Point* point)
{
	Point *p = new Point(0,0,0);
	*p = *point;
	array[pos] = p;
}

void Cube::createPolygons()
{

	//Point* A[4] = {points[0], points[1], points[2], points[3]};
	Point** A = generateArray(4);
	addElement(A, 0, points[0]);addElement(A, 1, points[1]);
	addElement(A, 2, points[2]);addElement(A, 3, points[3]);
	addNormal(A, 4, 0, 0, 1); //changed from 100
    //Point* B[4] = {points[4], points[5], points[6], points[7]};
	Point** B = generateArray(4);
	addElement(B, 0, points[4]);addElement(B, 1, points[5]);
	addElement(B, 2, points[6]);addElement(B, 3, points[7]);
	addNormal(B, 4, 0, 0, -1);
    //Point* C[4] = {points[0], points[1], points[5], points[4]};
	Point** C = generateArray(4);
	addElement(C, 0, points[0]);addElement(C, 1, points[1]);
	addElement(C, 2, points[5]);addElement(C, 3, points[4]);
	addNormal(C, 4, 0, -1, 0);
    //Point* D[4] = {points[3], points[2], points[6], points[7]};
    Point** D = generateArray(4);
    addElement(D, 0, points[3]);addElement(D, 1, points[2]);
    addElement(D, 2, points[6]);addElement(D, 3, points[7]);
    addNormal(D, 4, 0, 1, 0);
    //Point* E[4] = {points[3], points[7], points[4], points[0]};
    Point** E = generateArray(4);
    addElement(E, 0, points[3]);addElement(E, 1, points[7]);
    addElement(E, 2, points[4]);addElement(E, 3, points[0]);
    addNormal(E, 4, -1, 0, 0);
    //Point* F[4] = {points[2], points[6], points[5], points[1]};
    Point** F = generateArray(4);
    addElement(F, 0, points[2]);addElement(F, 1, points[6]);
    addElement(F, 2, points[5]);addElement(F, 3, points[1]);
    addNormal(F, 4, 1, 0, 0);

    //eclipse marking this as a unexpected thing and a bug. Maybe we can to watch this more closer?
    addPolygon(A, 4);
    addPolygon(B, 4);
    addPolygon(C, 4);
    addPolygon(D, 4);
    addPolygon(E, 4);
    addPolygon(F, 4);
}

Cube::~Cube() {
    for(int i=0; i < 8; i++)
        delete points[i];
    delete &points;
}

