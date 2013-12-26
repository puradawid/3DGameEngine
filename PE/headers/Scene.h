#ifndef SCENE_H
#define SCENE_H

#include "RenderClues.h"
#include "Camera.h"
#include "SceneIterator.h"

class Scene
{
	SceneNode* root;
	Camera* mainCamera;
public:
	Scene();
	void render(RenderClues*);
	void update(UpdateClues*);
	SceneNode* getRoot();
	SceneIterator* getIterator();
};

#endif
