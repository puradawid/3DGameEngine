#include "../headers/CollisionDetector.h"

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

void CollisionDetector::notifyObservers(Collision* collision){
	for (int j = 0; j < observers.size(); j++){
		observers[j]->collisionDetected(collision);
	}
}