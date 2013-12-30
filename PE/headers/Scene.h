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
	void setRoot(SceneNode*);
	SceneNode* getRoot();
	SceneIterator* getIterator();
};

#endif
