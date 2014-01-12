#ifndef MESH_H
#define MESH_H

#include "RenderClues.h"
#include "Point.h"

class Mesh
{
public:
	virtual void render(RenderClues*) {}; //print mesh on scene
	virtual ~Mesh() {};
	virtual Point getPoint(int index) {};
	virtual int getSize() {};
};

#endif
