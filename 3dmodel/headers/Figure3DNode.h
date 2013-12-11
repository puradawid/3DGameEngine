#ifndef FIGURE3DNODE_H

#define FIGURE3DNODE_H
#include "TreeNode.h"
#include "Figure3D.h"

class Figure3DNode : public TreeNode
{
protected:
	Figure3D * object;
public:
	Figure3DNode(Figure3D*, Point relative);

	void runRender();
};

#endif
