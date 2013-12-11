#include "../headers/TreeNode.h"

#include <GL/gl.h>

TreeNode::TreeNode()
{
	this->id = 10;
}

void TreeNode::addChild(TreeNode *child)
{
	this->childrens.push_back(child);
}

void TreeNode::render()
{
	glPushMatrix();

	glRotatef(rotate.x, 1, 0, 0);
	glRotatef(rotate.y, 0, 1, 0);
	glRotatef(rotate.z, 0, 0, 1);
	glTranslatef(relative.x, relative.y, relative.z);

	runRender();

	for(unsigned int i = 0; i < childrens.size(); i++)
		childrens[i]->render();

	glPopMatrix();
}

void TreeNode::absolute(Point position, Point rotation)
{
	//pass for objects inside
}

void TreeNode::moveObject(Point position)
{
	this->relative.add(position);
}

void TreeNode::rotateObject(Point rotation)
{
	this->rotate.add(rotation);
}
