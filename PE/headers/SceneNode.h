#ifndef SCENENODE_H
#define SCENENODE_H

#include <vector>

#include "ObjectId.h"
#include "UpdateClues.h"
#include "RenderClues.h"
#include "SimplePoint.h"
#include "RenderStrategy.h"
#include "BoundingBox.h"

class SceneNode
{
	static int counter;
	friend class CollisionDetector;
	SimplePoint rotation, translation, scale;
	SimplePoint absoluteTransform, absoluteRotation, absoluteScale;
	TransformationType last;
	SimplePoint last_transform;
	ObjectId id;
protected:
	RenderStrategy* rs;
	BoundingBox* bb;
	SimplePoint getTranslation() { return translation; }
	SimplePoint getRotation() { return rotation; }
	SimplePoint getScale() { return scale; }
	SimplePoint getAbsoluteTranslation() { return absoluteTransform; }
	SimplePoint getAbsoluteRotation() { return absoluteRotation; }
	SimplePoint getAbsoluteScale() { return absoluteScale; }
	void transform();
	void revertTransform();
public:
	ObjectId addNode(SceneNode*);
	void removeNode(ObjectId);
	void setRenderStrategy(RenderStrategy*);
	void move(SimplePoint vector);
	void rotate(SimplePoint vector);
	SceneNode();
	SceneNode(BoundingBox*);
	std::vector<SceneNode*> childs;
	virtual void render(RenderClues*);
	virtual void update(UpdateClues*);
};

#endif
