#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "SceneNode.h"
#include "Mesh.h"

class StaticObject : public SceneNode
{
	Mesh* mesh;
public:
	StaticObject(Mesh*);
	StaticObject();

	virtual void render(RenderClues*);
	virtual void update(UpdateClues*);
};

#endif