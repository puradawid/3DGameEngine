#ifndef MESH_H
#define MESH_H

#include "RenderClues.h"

class Mesh
{
public:
	virtual void render(RenderClues*) {}; //print mesh on scene
	virtual ~Mesh() {};
};

#endif
