#include "../headers/Scene.h"
#include<GL/gl.h>
#include<vector>
#include<stdlib.h>

Scene::Scene()
{
	this->objects = std::vector<Figure3D*>();
	this->cameras = std::vector<Camera>();
	this->current_camera = 0;
}

void Scene::render()
{
	for(int i = 0; i < objects.size(); i++)
	{
		struct Pos p = objects[i]->pos();
		GLfloat x = p.x, y = p.y, z = p.z;
		glPushMatrix();
		glTranslatef(x,y,z);
		objects[i]->render();
		glPopMatrix();
	}
}

int Scene::addObject(Figure3D *figure)
{
	objects.push_back(figure);
	return objects.size() - 1;
}

Figure3D* Scene::getObject(int id)
{
	return objects[id];
}

int Scene::addCamera(Camera camera)
{
	cameras.push_back(camera);
	return cameras.size() - 1;
}

Camera* Scene::getCamera()
{
	if(cameras.size() >= 1)
		return &(cameras[current_camera]);
	else
		return NULL;
}
