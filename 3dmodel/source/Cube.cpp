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
        cout << points[0]->x() << points[i]->y() << points[i]->z() << endl;
}

Cube::Cube(Point x, double width)
        : Figure3D()
{
    this->points = vector<Point*>(8);
    this->points[0] = new Point(x);
    this->points[1] = (Point*)new Point(x.x() + width, x.y(), x.z());
    this->points[2] = (Point*)new Point(x.x() + width, x.y() + width, x.z());
    this->points[3] = (Point*)new Point(x.x(), x.y() + width, x.z());
    this->points[4] = (Point*)new Point(x.x(), x.y(), x.z() + width);
    this->points[5] = (Point*)new Point(x.x() + width, x.y(), x.z() + width);
    this->points[6] = (Point*)new Point(x.x() + width, x.y() + width, x.z() + width);
    this->points[7] = (Point*)new Point(x.x(), x.y() + width, x.z() + width);
    //printDebug(points); //debug purpose
    createPolygons();
}


void Cube::createPolygons()
{
    Point* A[4] = {points[0], points[1], points[2], points[3]};
    Point* B[4] = {points[4], points[5], points[6], points[7]};
    Point* C[4] = {points[0], points[1], points[5], points[4]};
    Point* D[4] = {points[3], points[2], points[6], points[7]};
    Point* E[4] = {points[3], points[7], points[4], points[0]};
    Point* F[4] = {points[2], points[6], points[5], points[1]};
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

