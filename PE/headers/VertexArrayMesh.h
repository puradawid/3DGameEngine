#ifndef VERTEXARRAYMESH_H
#define VERTEXARRAYMESH_H

class VertexArrayMesh
{
	GLint id;
public:
	virtual void render(RenderClues*);
};

#endif