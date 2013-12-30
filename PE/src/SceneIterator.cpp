#include "../headers/SceneIterator.h"

bool SceneIterator::hasNext(){
	return true;
}

SceneNode* SceneIterator::next(){
	return new SceneNode();
}
