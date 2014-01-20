#ifndef ENEMYOBJECT_H
#define ENEMYOBJECT_H

#include ".\headers\SceneNode.h"
#include ".\headers\Mesh.h"
#include ".\headers\StaticObject.h"

class EnemyObject : public StaticObject{

public:
	EnemyObject::EnemyObject(Mesh* mesh)
		: StaticObject(mesh)
	{

	}

	virtual void nextMove();
};

#endif