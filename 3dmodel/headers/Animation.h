#ifndef ANIMATION_H
#define ANIMATION_H

#include "TreeNode.h"
#include "Frame.h"

#include <vector>


class Animation
{
protected:
	TreeNode* object;
	std::vector<Frame*> frames;
public:
	Animation() { object = NULL; }
	void assignNode(TreeNode* object)	{ this->object = object; }
	void setNextFrame(Frame* frame)		{ this->frames.push_back(frame); }
};

#endif