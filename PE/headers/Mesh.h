#ifndef MESH_H
#define MESH_H

#include "RenderClues.h"

class Mesh
{
public:
	virtual void render(RenderClues*);
	virtual ~Mesh();
};

#endif
