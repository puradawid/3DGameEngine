#ifndef TREENODE_H
#define TREENODE_H

#include<vector>
#include "Figure3D.h"

class TreeNode
{
static int ID;
protected:
	int id;
	std::vector<TreeNode*> childrens;
	TreeNode* parent;
	Point relative;
	Point rotate;
	Point scale;
public:
	TreeNode();
	virtual void render();
	virtual void runRender() {};
	virtual void absolute(Point absolute, Point rotation);
	virtual void moveObject(Point point);
	virtual void rotateObject(Point rotation);
	void addChild(TreeNode* child);
	virtual ~TreeNode() {};
};

#endif
