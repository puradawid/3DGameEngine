#ifndef SCENEITERATOR_H
#define SCENEITERATOR_H

#include <vector>

#include "SceneNode.h"

class SceneIterator
{
	SceneNode* current;
	std::vector<SceneNode*> path;
public:
	SceneNode* next();
	bool hasNext();
};

#endif