#ifndef OBJPOOL_H
#define OBJPOOL_H

#include <vector>
#include <string>
#include <utility>

#include "Point.h"
#include "Mesh.h"
#include "MeshBuildStrategy.h"

#define OBJMesh std::vector<std::vector<Point>*>*
#define OBJPoolMeshes std::vector<std::pair<std::string, OBJMesh> >

class OBJPool
{
private:
	OBJPoolMeshes meshes;
	OBJMesh parseOBJ(std::string);
public:
	Mesh* getMesh(MeshBuildStrategy*, std::string); //strategy and resource path
	virtual ~OBJPool();
};

#endif
