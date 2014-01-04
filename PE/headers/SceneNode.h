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
	SimplePoint rotation, translation, scale;
	SimplePoint absoluteTransform;
	ObjectId id;
protected:
	RenderStrategy* rs;
	std::vector<SceneNode*> childs;
	SimplePoint getTranslation() { return translation; }
	SimplePoint getRotation() { return rotation; }
	SimplePoint getScale() { return scale; }
	void transform();
	void revertTransform();
public:
	ObjectId addNode(SceneNode*);
	void removeNode(ObjectId);
	void setRenderStrategy(RenderStrategy*);
	void move(SimplePoint vector);
	SceneNode();

	virtual void render(RenderClues*);
	virtual void update(UpdateClues*);
};

#endif
