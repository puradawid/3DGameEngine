#include "../headers/CollisionDetector.h"

#include "../headers/SimplePoint.h"

using namespace std;

CollisionDetector::CollisionDetector(){

}

void CollisionDetector::addObserver(CollisionObserver* observer){
	observers.push_back(observer);
}

void CollisionDetector::dismissObserver(CollisionObserver* observer){
	for (int i = 0; i < observers.size(); i++){
		if (observers[i] == observer){
			observers.erase(observers.begin() + i);
		}
	}
}

void CollisionDetector::addCollisionable(SceneNode* collisionable){
	collisionables.push_back(collisionable);
}

void CollisionDetector::dismissCollisionable(SceneNode* collisionable){
	for (int i = 0; i < collisionables.size(); i++){
		if (collisionables[i] == collisionable){
			collisionables.erase(collisionables.begin() + i);
		}
	}
}

void CollisionDetector::notifyObservers(Collision* collision){
	for (int j = 0; j < observers.size(); j++){
		observers[j]->collisionDetected(collision);
	}
}

void CollisionDetector::notifyDetector(SceneNode* reason, TransformationType type, SimplePoint transformation)
{
	for(int i = 0; i < collisionables.size(); i++)
	{
		if(collisionables[i] != reason)
		{
			if(reason->bb->collision(collisionables[i]->bb))
			{
				std::vector<SceneNode*> elements(1);
				elements[0] = collisionables[i];
				notifyObservers(new Collision(reason, elements, transformation, type));
			}
		}
	}
}