#ifndef VBOMESH_H
#define VBOMESH_H

#include <GL\gl.h>

#include "RenderClues.h"

class VBOMesh
{
	GLint id;
public:
	virtual void render(RenderClues*);
};

#endif