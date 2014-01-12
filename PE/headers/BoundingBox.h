#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "SimplePoint.h"
#include "Mesh.h"

#include <utility>
#include <vector>

/**
 *	Class bounding box should be used only in collisions
**/

class BoundingBox
{
protected:
	SimplePoint rel_min, rel_max; //relative (form mesh)
	SimplePoint min, max;
	SimplePoint rotation_vector, translation_vector, scale_vector; //it is absolute translations
public:
	BoundingBox(Mesh*); //constructs mesh
	void generateFrom(Mesh*); //recalculate min and max points
	void rotate(SimplePoint);
	void scale(SimplePoint);
	void translate(SimplePoint);
	bool collision(BoundingBox*); //check if BouningBox seriously collisioned with other 
	void recalculate();
	void render();
	std::vector<SimplePoint> getAllPoints(SimplePoint min, SimplePoint max);
	std::pair<SimplePoint, SimplePoint> getVectorFromPoints(std::vector<SimplePoint>);
};

#endif