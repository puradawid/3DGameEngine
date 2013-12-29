#include "../headers/VertexArrayMesh.h"


#include <GL/gl.h>

VertexArrayMesh::VertexArrayMesh()
	: Mesh()
{
}

void VertexArrayMesh::render(RenderClues* rc)
{
	int count_polys = mesh->size();
	for(int i = 0; i < count_polys; i++)
	{
		int count_vertexes = (*mesh)[i]->size();
		for(int j = 0; j < count_vertexes; j++)
		{
			Point p = (*(*mesh)[i])[j];
			glNormal3f(p.normal.x, p.normal.y, p.normal.z);
			glVertex3f(p.x, p.y, p.z);
		}
	}
}

void VertexArrayMesh::setMesh(std::vector<std::vector<Point>*>* mesh)
{
	this->mesh = mesh;
}