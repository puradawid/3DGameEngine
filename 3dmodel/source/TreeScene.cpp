
#include "../headers/TreeScene.h"

TreeScene::TreeScene()
{
	this->root = new TreeNode();
}

TreeNode* TreeScene::getRoot()
{
	return this->root;
}

TreeScene::~TreeScene()
{
	delete this->root;
}

void TreeScene::render()
{
	this->root->render();
}


