#ifndef SCENE_H_
#define SCENE_H_

#include "Figure3D.h"
#include "Camera.h"

class Scene
{
protected:
	std::vector<Figure3D*> objects;
	std::vector<Camera> cameras;
	int current_camera;
public:
	Scene(); //default constructor
	virtual int addObject(Figure3D*);
	virtual void removeObject(Figure3D*);
	virtual Figure3D* getObject(int id);
	virtual void render();
	virtual int addCamera(Camera);
	virtual Camera* getCamera();
};


#endif /* SCENE_H_ */
