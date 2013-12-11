#ifndef FIGURE3D_H
#define	FIGURE3D_H

#include<vector>
#include<GL/gl.h>

#include"Point.h"
#include"../headers/GLRenderStrategy.h"

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
    struct Pos rotation; // rotation element of screen
    GLRenderStrategy* rs;
public:
    Figure3D();
    Figure3D(const Figure3D& orig);					//copy figure
    void addPolygon(Point** points, int size);		//adding another polygon (copy)
    void cleanPolygons();							//clear all polygons
    void moveFigure(GLdouble x, GLdouble y, GLdouble z);	//move object by vector
    void rotateFigure(GLdouble x, GLdouble y, GLdouble z); //rotates concrete figure
    virtual void setRenderStrategy(GLRenderStrategy* rs);
    virtual void render();						//render figure
    virtual void preRender() {};
    virtual void postRender() {};
    std::vector<std::vector<Point*> > getPolygons();//getting polygons array
    struct Pos pos() { return pos_; }
    virtual ~Figure3D();
private:

};

#endif	/* FIGURE3D_H */

