#include "../headers/SceneNode.h"

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
	for(auto node : childs)
	{
		node->render(rc);
	}
}

void SceneNode::update(UpdateClues* uc)
{

}

void SceneNode::setRenderStrategy(RenderStrategy* rs)
{
	this->rs = rs;
}