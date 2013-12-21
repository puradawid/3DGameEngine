#ifndef OBJPOOL_H
#define OBJPOOL_H

#define OBJPoolMeshes std::vector<std::pair<string, std::vector<std::vector<Point>*>*> >

class OBJPool
{
	OBJPoolMeshes meshes;
public:
	getMesh(MeshBuildStrategy*, string); //strategy and resource path
};

#endif