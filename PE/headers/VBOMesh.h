#ifndef VBOMESH_H
#define VBOMESH_H
#ifdef _MSC_VER
#include <Windows.h>
#endif
#include <GL\gl.h>

#include "RenderClues.h"

class VBOMesh
{
	GLint id;
public:
	virtual void render(RenderClues*);
};

#endif