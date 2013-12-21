#ifndef SCENE_H
#define SCENE_H

#include "RenderClues.h"
#include "SceneIterator.h"

class Scene
{
	SceneNode* root;
	Camera* mainCamera;
public:
	void render(RenderClues*);
	void update(UpdateClues*);
	SceneIterator* getIterator();
};

#endif