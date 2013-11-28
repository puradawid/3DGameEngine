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
	int addObject(Figure3D*);
	void removeObject(Figure3D*);
	Figure3D* getObject(int id);
	void render();
	int addCamera(Camera);
	Camera* getCamera();
};


#endif /* SCENE_H_ */
