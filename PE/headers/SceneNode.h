#ifndef SCENENODE_H
#define SCENENODE_H

#include "ObjectId.h"
#include "UpdateClues.h"

class SceneNode
{
public:
	ObjectId addNode(SceneNode*);
	void removeNode(ObjectId);
	virtual void render(RenderClues*);
	virtual void update(UpdateClues*);
};

#endif
