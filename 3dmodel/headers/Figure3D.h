#ifndef FIGURE3D_H
#define	FIGURE3D_H

#include<vector>


#include"Point.h"

struct Pos
{
    	double x;
    	double y;
    	double z;
    	Pos()
		{
    		x = 0;
    		y = 0;
    		z = 0;
		}
};

class Figure3D {
protected:
    std::vector<std::vector<Point*> > polygons;
    struct Pos pos_; //position of element on screen
public:
    Figure3D();
    Figure3D(const Figure3D& orig);					//copy figure
    void addPolygon(Point** points, int size);		//adding another polygon (copy)
    void cleanPolygons();							//clear all polygons
    void moveFigure(double x, double y, double z);	//move object by vector
    virtual void render() {};						//render figure
    struct Pos pos() { return pos_; }
    virtual ~Figure3D();
private:

};

#endif	/* FIGURE3D_H */

