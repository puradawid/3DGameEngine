#ifndef MATERIALRENDERSTRATEGY_H
#define	MATERIALRENDERSTRATEGY_H
#include "LinesRenderStrategy.h"
#include "Material.h"

class MaterialRenderStrategy : public LinesRenderStrategy {
public:
    MaterialRenderStrategy(double, double, double);
    MaterialRenderStrategy(const MaterialRenderStrategy& orig);
    virtual void preObject();
    virtual void postObject();
    virtual void renderPolygon(vector<Point*>*);
    virtual ~MaterialRenderStrategy();
protected:
    Material *material;

};

#endif	/* MATERIALRENDERSTRATEGY_H */

