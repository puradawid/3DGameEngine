#ifndef VERTEXARRAYMESH_H
#define VERTEXARRAYMESH_H

#include "Mesh.h"
#include "Point.h"

#include <GL/gl.h>
#include <vector>

class VertexArrayMesh : public Mesh
{
	friend class VertexArrayBuildStrategy;
	GLint id;
	std::vector<std::vector<Point>*>* mesh;
	void setMesh(std::vector<std::vector<Point>*>*);
public:
	virtual void render(RenderClues*); //rendering mesh
	VertexArrayMesh();
};

#endif