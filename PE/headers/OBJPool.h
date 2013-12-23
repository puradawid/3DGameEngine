#ifndef OBJPOOL_H
#define OBJPOOL_H

#include <vector>
#include <string>
#include <utility>

#include "Point.h"
#include "Mesh.h"
#include "MeshBuildStrategy.h"

//#define OBJPoolMeshes std::vector<std::pair<std::string, std::vector<std::vector<Point>*>*> >

class OBJPool
{
private:
	std::vector<std::pair<std::string, std::vector<std::vector<Point>*>*> > meshes;
public:
	Mesh* getMesh(MeshBuildStrategy*, std::string); //strategy and resource path
};

#endif
