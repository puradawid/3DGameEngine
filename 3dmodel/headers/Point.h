#ifndef POINT_H
#define	POINT_H

class Point {
    double _x;
    double _y;
    double _z;
public:
    Point();
    Point(double x, double y, double z);
    
    double x();
    double y();
    double z();
    
    void x(double x);
    void y(double y);
    void z(double z);
    
    Point(const Point& orig);
    virtual ~Point();
private:

};

#endif	/* POINT_H */

