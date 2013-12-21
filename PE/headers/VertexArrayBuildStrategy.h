#ifndef VERTEXARRAYBUILDSTRATEGY_H
#define VERTEXARRAYBUILDSTRATEGY_H

class VertexArrayBuildStrategy : MeshBuildStrategy
{
public:
	virtual Mesh* getMesh(std::vector<std::vector<Point*>*>);
};

#endif