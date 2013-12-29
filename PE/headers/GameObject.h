#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "RenderClues.h"
#include "Mesh.h"
#include "SceneNode.h"

class GameObject : public SceneNode
{
	Mesh* mesh;
public:
	virtual void render(RenderClues*);
};

#endif