#ifndef COLLISIONOBSERVER_H
#define COLLISIONOBSERVER_H

#include "Collision.h"
/**
 * Abstract (or more than abstract - interface) of collision observer
 */
class CollisionObserver
{
public:
	virtual void collisionDetected(Collision*) = 0; ///override method if you want to detect collisions
};

#endif