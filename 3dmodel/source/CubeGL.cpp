#include "../headers/CubeGL.h"
#include "../headers/GLRenderStrategy.h"
#include <iostream>

using namespace std;

CubeGL::CubeGL(Point** points) : Cube(points) {
    generatePairs();
}

CubeGL::CubeGL(const CubeGL& orig) : Cube(orig) {
    generatePairs();
}

CubeGL::CubeGL(Point p, double width) : Cube(p, width)
{
    generatePairs();
}

pair<int, int> generatePair(int x, int y)
{
    return pair<int, int>(x,y);
}

void CubeGL::generatePairs()
{
    //hardcoded for cubes - standard of numbering is required
    lines = new vector<pair<int,int> >(12);
    (*(this->lines))[0] = generatePair(0,1);
    (*(this->lines))[1] = generatePair(1,2);
    (*(this->lines))[2] = generatePair(2,3);
    (*(this->lines))[3] = generatePair(3,0);
    (*(this->lines))[4] = generatePair(4,5);
    (*(this->lines))[5] = generatePair(5,6);
    (*(this->lines))[6] = generatePair(6,7);
    (*(this->lines))[7] = generatePair(7,4);
    (*(this->lines))[8] = generatePair(3,7);
    (*(this->lines))[9] = generatePair(2,6);
    (*(this->lines))[10] = generatePair(1,5);
    (*(this->lines))[11] = generatePair(0,4);
}

/* 
 * Rendering cube is based on passing a polygons to strategy
 * this method provides a simple wrapping for other elements
 */
void CubeGL::render()
{
    for(int i = 0; i < polygons.size(); i++)
        this->strategy->renderPolygon(&polygons[i]);
}

CubeGL::~CubeGL() {
    for(int i = 0; i < 8; i++)
        delete points[i];
    delete &points;
}

