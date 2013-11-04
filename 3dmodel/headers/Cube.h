#include "Point.h"
#ifndef CUBE_H
#define	CUBE_H

#include <stdio.h>
#include <vector>

#include "Figure3D.h"

using namespace std;
/*
 * Cube is defined by 8 things - 8 vertex. This cube CANT draw himself in opengl
 * but certainly it can model himself on model as it is.
 */
class Cube : public Figure3D {
protected:
    vector<Point*> points;
public:
    Cube();
    Cube(Point **points);
    Cube(Point x, double witdth);
    Cube(const Cube& orig);
    void createPolygons();
    virtual ~Cube();
private:

};

#endif	/* CUBE_H */

