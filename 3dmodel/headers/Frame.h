#ifndef FRAME_H
#define FRAME_H

#include "TreeNode.h"
#include 

class Frame
{
protected:
	int elapsed_time;
	Point rotation, scale, translation;

public:
	tick(int ms, TreeNode* object)
	{
	}
};

#endif