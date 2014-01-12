#ifndef UPDATECLUES_H
#define UPDATECLUES_H

#include "SimplePoint.h"

class UpdateClues
{
public:
	SimplePoint parentTransform;
	SimplePoint parentScale;
	SimplePoint parentRotation;

	UpdateClues()
	{
		parentScale = SimplePoint(1,1,1);
	}
};

#endif