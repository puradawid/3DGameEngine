#ifndef VERTEXARRAYBUILDSTRATEGY_H
#define VERTEXARRAYBUILDSTRATEGY_H

#include "Mesh.h"
#include "Point.h"
#include "MeshBuildStrategy.h"

#include <vector>

class VertexArrayBuildStrategy : public MeshBuildStrategy
{
public:
	VertexArrayBuildStrategy();
	virtual Mesh* getMesh(std::vector<std::vector<Point>*>*);
};

#endif