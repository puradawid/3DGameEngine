#ifndef COLLISION_H
#define COLLISION_H

#include <vector>

#include "SimplePoint.h"
#include "SceneNode.h"

class Collision
{
	SceneNode* reason;
	std::vector<SceneNode*> objects;
	SimplePoint vector;
	TransformationType type;
public:
	SceneNode* getReason(){return reason;}
	std::vector<SceneNode*> getObjects() {return objects;};
	SimplePoint getVector() {return vector;}
	TransformationType getType() {return type;}
	Collision(SceneNode* reason, std::vector<SceneNode*> objects, SimplePoint vector, TransformationType type)
	{
		this->reason = reason;
		this->objects = objects;
		this->vector = vector;
		this->type = type;
	}
};

#endif
