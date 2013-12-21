#ifndef CAMERA_H
#define CAMERA_H

#include "CameraState.h"

/** Camera
 * Camera is an element of scene which is caterogically not renderable
 * but it can transform by itself or other nodes. (parents or childs).
 * Game can handle camerastate and make it for perspective projection.
 */
class Camera : public SceneNode
{
private:
	CameraState currentState; //current state of camera (structure)
public:
	virtual void update(UpdateClues*);
};

#endif