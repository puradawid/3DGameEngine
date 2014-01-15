#ifndef CAMERA_H
#define CAMERA_H

#include "CameraState.h"
#include "SceneNode.h"
#include "UpdateClues.h"
#include "BoundingBox.h"

#ifdef _MSC_VER
	#define _USE_MATH_DEFINES
	#include <cmath>
#endif

/** Camera
 * Camera is an element of scene which is caterogically not renderable
 * but it can transform by itself or other nodes. (parents or childs).
 * Game can handle camerastate and make it for perspective projection.
 */
class Camera : public SceneNode
{
	friend void display();
	friend class BoundingBox;
private:
	CameraState currentState; //current state of camera (structure)
protected:
	void updateWorld();
public:
	virtual void update(UpdateClues*);
	virtual ~Camera();
};

#endif
