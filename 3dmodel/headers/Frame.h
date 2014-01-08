#ifndef FRAME_H
#define FRAME_H

#include "TreeNode.h"
#include "Point.h"

class Frame
{
	friend class Animation;

protected:
	int elapsed_time;
	Point rotation, scale, translation;

public:
	Frame(Point rotation, Point scale, Point translatin, int elapsed_time)
	{
		this->rotation = rotation;
		this->scale = scale;
		this->translation = translation;
		this->elapsed_time = elapsed_time;
	}
	void tick(int ms, TreeNode* object)
	{
	}
};

#endif