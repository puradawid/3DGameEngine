#ifndef FIGURE3D_H
#define	FIGURE3D_H

#include<vector>


#include"Point.h"

class Figure3D {
protected:
    std::vector<std::vector<Point*> > polygons;
public:
    Figure3D();
    Figure3D(const Figure3D& orig);             //copy figure
    void addPolygon(Point** points, int size);   //adding another polygon (copy)
    void cleanPolygons();                       //clear all polygons
    virtual ~Figure3D();
private:

};

#endif	/* FIGURE3D_H */

