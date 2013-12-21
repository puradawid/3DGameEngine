#ifndef VBOMESH_H
#define VBOMESH_H

class VBOMesh
{
	GLint id;
public:
	virtual void render(RenderClues*);
};

#endif