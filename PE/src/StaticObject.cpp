#include "../headers/StaticObject.h"

#include <stdlib.h>

//#include "../headers/Mesh.h"

StaticObject::StaticObject()
	: SceneNode()
{
	this->mesh = NULL;
}

StaticObject::StaticObject(Mesh* mesh)
	: SceneNode()
{
	this->mesh = mesh;
}

void StaticObject::render(RenderClues* rc)
{
	this->mesh->render(rc);
}

void StaticObject::update(UpdateClues* uc)
{
	
}