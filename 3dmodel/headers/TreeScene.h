#ifndef TREESCENE_H
#define TREESCENE_H

#include "TreeNode.h"
#include "Scene.h"

class TreeScene : public Scene
{
protected:
	TreeNode* root;
public:
	TreeScene();
	virtual void render();		//triggers rendering objects
	virtual void absolute() {}	//triggers information about absolute position
	virtual TreeNode* getRoot();
	virtual void setRoot(TreeNode*);
	virtual ~TreeScene();
};

#endif
