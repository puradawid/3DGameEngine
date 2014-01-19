#include "EnemyObject.h"

#include "./headers/BoundingBox.h"

#include <stdlib.h>

//#include "../headers/Mesh.h"

EnemyObject::EnemyObject(Mesh* mesh)
: StaticObject(mesh)
{

}

void StaticObject::render(RenderClues* rc)
{
	transform();
	if (this->bb != NULL)
	{
		this->bb->render();
	}
	this->rs->prepare(rc);
	this->mesh->render(rc);
	this->rs->end();

	for (auto node : childs)
	{
		node->render(rc);
	}

	revertTransform();
}

void StaticObject::update(UpdateClues* uc)
{
	SceneNode::update(uc);
}