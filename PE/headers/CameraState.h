#ifndef CAMERASTATE_H
#define CAMERASTATE_H

#include "SimplePoint.h"

struct CameraState
{
	SimplePoint p;  //localization od scene
	SimplePoint up; //up vector
	SimplePoint rot;//rotations
};

#endif