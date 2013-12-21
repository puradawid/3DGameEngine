#ifndef MESHBUILDSTRATEGY_H
#define MESHBUILDSTRATEGY_H

class MeshBuildStrategy
{
public:
	virtual Mesh* getMesh(std::vector<std::vector<Point*>*>);
};

#endif