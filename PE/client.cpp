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
#include "./headers/CollisionObserver.h"

#include <stdio.h>
#include <GL/glut.h>

SceneNode* rocket;
Camera* camera;
SceneNode* helper;

class MyTimer : public Timer
{
public:
	MyTimer(int ticks, int interval)
	: Timer(ticks, interval)
	{

	}

	virtual void tick()
	{
		//rocket->move(SimplePoint(-0.1,0,0));
	}
};

class CollisionObserverNotify : public CollisionObserver
{
	virtual void collisionDetected(Collision* collision)
	{
		SimplePoint vector = collision->getVector();
		
		vector.x = -vector.x;
		vector.y = -vector.y;
		vector.z = -vector.z;

		if(collision->getType() == Translation)
			collision->getReason()->move(vector);
	}
};

class MovementObserver : public UserEventObserver
{
public:
	virtual void handleEvent(UserEventArgs* arg)
	{
		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_LEFT)
		{
			rocket->move(SimplePoint(0.1,0,0));
		}

		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_RIGHT)
		{
			rocket->move(SimplePoint(-0.1,0,0));
		}

		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_UP)
		{
			rocket->move(SimplePoint(0,0,-0.1));
		}

		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_DOWN)
		{
			rocket->move(SimplePoint(0,0,0.1));
		}
		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_HOME)
		{
			helper->rotate(SimplePoint(0.1,0,0));
		}
		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_END)
		{
			helper->rotate(SimplePoint(0,0.1,0));
		}

		if(arg->isKeyboard() && arg->getEvent() == 's')
		{
			helper->move(SimplePoint(0,-0.1,0));
		}
		if(arg->isKeyboard() && arg->getEvent() == 'w')
		{
			helper->move(SimplePoint(0,0.1,0));
		}
		if(arg->isKeyboard() && arg->getEvent() == 'a')
		{
			helper->rotate(SimplePoint(0,0.1,0));
		}
		if(arg->isKeyboard() && arg->getEvent() == 'a')
		{
			helper->rotate(SimplePoint(0,-0.1,0));
		}
	}
};

class MyGame : public Game
{

public:
	virtual void initializeGame(GameConfig* config)
	{
		this->getTimerClock()->addTimer(new MyTimer(1000, 10));
		MeshBuildStrategy* mbs = dynamic_cast<MeshBuildStrategy*>(new VertexArrayBuildStrategy());
		getUserEventManager()->addObserver(new MovementObserver());

		StaticObject* sn = new StaticObject(this->getOBJPool()->getMesh(mbs, "./resources/obj/tower.obj"));
		sn->setRenderStrategy(dynamic_cast<RenderStrategy*>(new MaterialRenderStrategy()));
		sn->move(SimplePoint(4,0,0));
		this->getScene()->getRoot()->addNode(sn);
		
		StaticObject* s2 = new StaticObject(this->getOBJPool()->getMesh(mbs, "./resources/obj/tower.obj"));
		s2->setRenderStrategy(dynamic_cast<RenderStrategy*>(new MaterialRenderStrategy()));
		s2->move(SimplePoint(7,0,0));
		this->getScene()->getRoot()->addNode(s2);

		camera = new Camera();
		this->getScene()->getRoot()->addNode(camera);
		this->getScene()->setCamera(camera);
		camera->move(SimplePoint(0,10,20));
		camera->rotate(SimplePoint(-25,0,0));

		StaticObject* s1 = new StaticObject(this->getOBJPool()->getMesh(mbs, "./resources/obj/rocket.obj"));
		s1->setRenderStrategy(dynamic_cast<RenderStrategy*>(new MaterialRenderStrategy()));
		this->getScene()->getRoot()->addNode(s1);
		s1->move(SimplePoint(10,10,0));
		//s1->rotate(SimplePoint(0,10,0));
		rocket = dynamic_cast<SceneNode*>(s1);
		helper = s1;

		getCollisionDetector()->addObserver(dynamic_cast<CollisionObserver*>(new CollisionObserverNotify()));
		getCollisionDetector()->addCollisionable(s1);
		getCollisionDetector()->addCollisionable(sn);
		getCollisionDetector()->addCollisionable(s2);
	}
};
int main()
{
	MyGame m;
	m.start();
}
