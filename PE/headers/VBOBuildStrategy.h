#ifndef VBOBUILDSTRATEGY_H
#define VBOBUILDSTRATEGY_H

class VBOBuildStrategy : MeshBuildStrategy
{
public:
	virtual Mesh* getMesh(std::vector<std::vector<Point*>*>);
};

#endif