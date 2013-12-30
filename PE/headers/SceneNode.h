#ifndef SCENENODE_H
#define SCENENODE_H

#include <vector>

#include "ObjectId.h"
#include "UpdateClues.h"
#include "RenderClues.h"
#include "SimplePoint.h"
#include "RenderStrategy.h"
class SceneNode
{
	static int counter;
	std::vector<SceneNode*> childs;
	SimplePoint rotation, translation, scale;
	ObjectId id;
protected:
	RenderStrategy* rs;
public:
	ObjectId addNode(SceneNode*);
	void removeNode(ObjectId);
	void setRenderStrategy(RenderStrategy*);

	virtual void render(RenderClues*);
	virtual void update(UpdateClues*);
};

#endif
