#ifndef MESHBUILDSTRATEGY_H
#define MESHBUILDSTRATEGY_H

#include "Mesh.h"
#include "Point.h"

#include <vector>

class MeshBuildStrategy
{
public:
	virtual Mesh* getMesh(std::vector<std::vector<Point>*>*) = 0;
};

#endif