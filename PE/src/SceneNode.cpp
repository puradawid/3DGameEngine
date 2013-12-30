#include "../headers/SceneNode.h"
#ifdef _MSC_VER
	#include <Windows.h>
#endif
#include "../headers/SimplePoint.h"
#include <GL\gl.h>

ObjectId SceneNode::addNode(SceneNode* child)
{
	this->childs.push_back(child);
	ObjectId obj(this->childs.size() - 1);
	return ObjectId(obj);
}

void SceneNode::removeNode(ObjectId id)
{
	childs.erase(childs.begin() + id.id);
}

void SceneNode::render(RenderClues* rc)
{
	transform();
	for(auto node : childs)
	{
		node->render(rc);
	}
	revertTransform();
}

void SceneNode::update(UpdateClues* uc)
{

}

void SceneNode::setRenderStrategy(RenderStrategy* rs)
{
	this->rs = rs;
}

void SceneNode::transform()
{
	glPushMatrix();		//store matrix
	glRotatef(rotation.x, 1, 0 , 0); //rotate x
	glRotatef(rotation.y, 0, 1 , 0); //rotate y
	glRotatef(rotation.z, 0, 0 , 1); //rotate z
	glTranslatef(translation.x, translation.y, translation.z); //translate
	glScalef(scale.x, scale.y, scale.z); //scale
}

void SceneNode::revertTransform()
{
	glPopMatrix();
}

SceneNode::SceneNode()
{
	this->scale = SimplePoint(1,1,1);
}

void SceneNode::move(SimplePoint vector)
{
	translation.x += vector.x;
	translation.y += vector.y;
	translation.z += vector.z;
}