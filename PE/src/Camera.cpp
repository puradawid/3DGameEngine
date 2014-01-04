#include "../headers/Camera.h"

#ifdef _MSC_VER
	#include <Windows.h>
#endif
	#include <GL/gl.h>

void Camera::update(UpdateClues* uc)
{
	SceneNode::update(uc);
	currentState.p = getTranslation();
	currentState.rot = getRotation();
}

Camera::~Camera(){

}

void Camera::updateWorld()
{
	glRotatef(-currentState.rot.x, 1.0, 0, 0);
    glRotatef(-currentState.rot.y, 0, 1.0, 0);
    glTranslatef(-currentState.p.x, -currentState.p.y, -currentState.p.z); //can be reverted moves
}