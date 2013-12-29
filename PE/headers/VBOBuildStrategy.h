#ifndef VBOBUILDSTRATEGY_H
#define VBOBUILDSTRATEGY_H

#include "Mesh.h"
#include "MeshBuildStrategy.h"
#include "Point.h"

#include <vector>

class VBOBuildStrategy : MeshBuildStrategy
{
public:
	virtual Mesh* getMesh(std::vector<std::vector<Point*>*>);
};

#endif