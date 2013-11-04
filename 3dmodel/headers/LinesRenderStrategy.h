#ifndef LINESRENDERSTRATEGY_H
#define	LINESRENDERSTRATEGY_H
#include "GLRenderStrategy.h"

#include <vector>

using namespace std;

class LinesRenderStrategy : public GLRenderStrategy {
public:
    LinesRenderStrategy(double r, double g, double b);
    virtual void renderLines(vector<Point*>*, void*);
    virtual void renderPolygon(vector<Point*>*);
    virtual void preObject();
    virtual void postObject();
    LinesRenderStrategy(const LinesRenderStrategy& orig);
    virtual ~LinesRenderStrategy();
protected:
    double r,g,b;               //RGB color

};

#endif	/* LINESRENDERSTRATEGY_H */

