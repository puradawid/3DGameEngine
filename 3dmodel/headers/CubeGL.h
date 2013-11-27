#ifndef CUBEGL_H
#define	CUBEGL_H

#include <vector>
#include "Cube.h"
#include "GLRenderStrategy.h"

using namespace std;

class CubeGL : public Cube {
public:
    CubeGL(vector<Point>);
    CubeGL(Point**);
    CubeGL(Point p, double width);
    CubeGL(const CubeGL& orig);
    virtual void render();              //rendering object on scene
    void setStrategy(GLRenderStrategy *strategy) {this->strategy = strategy;}
    virtual ~CubeGL();
protected:
    GLRenderStrategy *strategy; //describes rendering strategy
private:
    vector< std::pair<int,int> > *lines;
    void generatePairs();
};

#endif	/* CUBEGL_H */

