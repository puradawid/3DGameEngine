#ifndef SCENE_H
#define SCENE_H

#include "RenderClues.h"
#include "Camera.h"
#include "SceneIterator.h"

#include <stdlib.h>

class Scene
{
	SceneNode* root;
	Camera* mainCamera;

public:
	Scene();
	void render(RenderClues*);
	void update(UpdateClues*);
	void setRoot(SceneNode*);
	SceneNode* getRoot();
	SceneIterator* getIterator();
	void setCamera(Camera* mainCamera) {if (mainCamera != NULL) this->mainCamera = mainCamera; }
	Camera* getCurrentCamera() { return mainCamera; }
};

#endif
