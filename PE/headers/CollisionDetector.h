#ifndef COLLISIONDETECTOR_H
#define COLLISTIONDETECTOR_H

#include <vector>

#include "CollisionObserver.h"
#include "Collision.h"

class CollisionDetector
{
	std::vector<CollisionObserver*> observers;
public:
	CollisionDetector();
	void addObserver(CollisionObserver*);
	void dismissObserver(CollisionObserver*);
	void notifyObservers(Collision*);
};

#endif