#include "../headers/StaticObject.h"

#include <stdlib.h>

//#include "../headers/Mesh.h"

StaticObject::StaticObject()
	: SceneNode()
{
	this->mesh = NULL;
	this->rs = NULL;
}

StaticObject::StaticObject(Mesh* mesh)
	: SceneNode()
{
	this->mesh = mesh;
}

void StaticObject::render(RenderClues* rc)
{
	this->rs->prepare(rc);
	this->mesh->render(rc);
	this->rs->end();
}

void StaticObject::update(UpdateClues* uc)
{
	
}