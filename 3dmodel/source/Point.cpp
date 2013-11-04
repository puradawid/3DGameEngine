#include "../headers/Point.h"

Point::Point() {
    this->_x = 0.0;
    this->_y = 0.0;
    this->_z = 0.0;
}

Point::Point(const Point& orig) {
    this->_x = orig._x;
    this->_y = orig._y;
    this->_z = orig._z;
}

Point::Point(double x, double y, double z)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

double Point::x() { return _x; }
void Point::x(double x) { this->_x = x; }
double Point::y() { return _y; }
void Point::y(double y) { this->_y = y; }
double Point::z() { return _z; }
void Point::z(double z) { this->_z = z; }

Point::~Point() {
}

