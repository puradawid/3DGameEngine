#ifndef GLRENDERSTRATEGY_H
#define	GLRENDERSTRATEGY_H

#include "Point.h"
#include <vector>

using namespace std;

class GLRenderStrategy {
public:
    GLRenderStrategy();
    GLRenderStrategy(const GLRenderStrategy& orig);
    virtual void preObject() {};
    virtual void postObject() {};
    virtual void renderLines(vector<Point*>*, void*) {};
    virtual void renderPolygon(vector<Point*>*) {};
    virtual ~GLRenderStrategy();
private:

};

#endif	/* GLRENDERSTRATEGY_H */

