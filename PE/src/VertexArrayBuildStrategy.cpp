#include "../headers/VertexArrayBuildStrategy.h"

#include "../headers/VertexArrayMesh.h"

//because this will kill me
#define VABS VertexArrayBuildStrategy

VABS::VABS()
{

}

Mesh* VertexArrayBuildStrategy::getMesh(std::vector<std::vector<Point>*>* mesh)
{
	VertexArrayMesh* m = new VertexArrayMesh();
	m->setMesh(mesh);
	return dynamic_cast<Mesh*>(m);
}