#ifndef COLLISIONDETECTOR_H
#define COLLISTIONDETECTOR_H

#include <vector>

#include "CollisionObserver.h"
#include "Collision.h"
#include "BoundingBox.h"
#include "SimplePoint.h"
#include "SceneNode.h"

class CollisionDetector
{
	friend class SceneNode;
	std::vector<CollisionObserver*> observers;
	std::vector<SceneNode*> collisionables;
	void notifyDetector(SceneNode*, TransformationType, SimplePoint);
public:
	CollisionDetector();
	void addObserver(CollisionObserver*);
	void dismissObserver(CollisionObserver*);
	void addCollisionable(SceneNode*);
	void dismissCollisionable(SceneNode*);
	void notifyObservers(Collision*);
};

#endif