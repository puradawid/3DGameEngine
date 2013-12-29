#include "../headers/Scene.h"
#include "../headers/SceneIterator.h"
#include "../headers/SceneNode.h"

#include <stdlib.h>

Scene::Scene()
{
	root = new SceneNode();
}

void Scene::render(RenderClues* rc)
{
	root->render(rc);
}

void Scene::update(UpdateClues* uc)
{
	//update scene(driven by animation or something like that)
}

SceneIterator* getIterator()
{
	return NULL;
}

SceneNode* Scene::getRoot()
{
	return root;
}