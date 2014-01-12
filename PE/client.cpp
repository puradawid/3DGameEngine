#include "./headers/Game.h"
#include "./headers/Timer.h"
#include "./headers/MeshBuildStrategy.h"
#include "./headers/VertexArrayBuildStrategy.h"
#include "./headers/StaticObject.h"
#include "./headers/LineRenderStrategy.h"
#include "./headers/MaterialRenderStrategy.h"
#include "./headers/Camera.h"
#include "./headers/UserEventManager.h"
#include "./headers/UserEventObserver.h"
#include "./headers/UserEventArgs.h"

#include <stdio.h>
#include <GL/glut.h>

SceneNode* rocket;
Camera* camera;

class MyTimer : public Timer
{
public:
	MyTimer(int ticks, int interval)
	: Timer(ticks, interval)
	{

	}

	virtual void tick()
	{
		printf("tick!\n");
		rocket->move(SimplePoint(0,0,-0.1));
	}
};

class MovementObserver : public UserEventObserver
{
public:
	virtual void handleEvent(UserEventArgs* arg)
	{
		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_LEFT)
		{
			rocket->move(SimplePoint(1,0,0));
		}

		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_RIGHT)
		{
			rocket->move(SimplePoint(-1,0,0));
		}

		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_UP)
		{
			rocket->move(SimplePoint(0,0,-1));
		}

		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_DOWN)
		{
			rocket->move(SimplePoint(0,0,1));
		}
	}
};

class MyGame : public Game
{

public:
	virtual void initializeGame(GameConfig* config)
	{
		this->getTimerClock()->addTimer(new MyTimer(1000, 1000));
		MeshBuildStrategy* mbs = dynamic_cast<MeshBuildStrategy*>(new VertexArrayBuildStrategy());
		StaticObject* sn = new StaticObject(this->getOBJPool()->getMesh(mbs, "./resources/obj/rocket.obj"));
		sn->setRenderStrategy(dynamic_cast<RenderStrategy*>(new MaterialRenderStrategy()));
		this->getScene()->getRoot()->addNode(sn);
		rocket = dynamic_cast<SceneNode*>(sn);
		camera = new Camera();
		//this->getScene()->getRoot()->addNode(camera);
		rocket->addNode(camera);
		rocket->rotate(SimplePoint(0,10,0));
		this->getScene()->setCamera(camera);
		camera->move(SimplePoint(0,0,20));
		getUserEventManager()->addObserver(new MovementObserver());

		StaticObject* s1 = new StaticObject(this->getOBJPool()->getMesh(mbs, "./resources/obj/rocket.obj"));
		s1->setRenderStrategy(dynamic_cast<RenderStrategy*>(new MaterialRenderStrategy()));
		this->getScene()->getRoot()->addNode(s1);
	}
};
int main()
{
	MyGame m;
	m.start();
}
