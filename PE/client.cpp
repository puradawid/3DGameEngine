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
#include "./headers/PECommand.h"

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
		rocket->move(SimplePoint(0,0,-0.15));
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

class KillCommand : public PECommand
{
public:
	virtual void doCommand()
	{
		rocket->move(SimplePoint(0,0,20));
	}
};

class CollisionObserverKiller : public CollisionObserver
{
	std::vector<SceneNode*> killers;
	PECommand* killCommand;
public:

	CollisionObserverKiller(PECommand* kill)
	{
		this->killCommand = kill;
	}

	void addKiller(SceneNode* killer)
	{
		killers.push_back(killer);
	}

	virtual void collisionDetected(Collision* collision)
	{
		SceneNode* rocket = collision->getReason();
		SceneNode* killer = collision->getObjects()[0];
		for(int i=0; i < killers.size(); i++)
			if(killer == killers[i])
				this->killCommand->doCommand();
	}
};

class MovementObserver : public UserEventObserver
{
public:

	const double jump = 0.5;

	virtual void handleEvent(UserEventArgs* arg)
	{
		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_LEFT)
		{
			rocket->move(SimplePoint(jump, 0, 0));
		}

		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_RIGHT)
		{
			rocket->move(SimplePoint(-jump, 0, 0));
		}
		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_UP)
		{
			rocket->move(SimplePoint(0, jump, 0));
		}

		if(arg->isSpecialKeyboard() && arg->getEvent() == GLUT_KEY_DOWN)
		{
			rocket->move(SimplePoint(0, -jump, 0));
		}
	}
};

class MyGame : public Game
{
	MeshBuildStrategy* mbs;

	SceneNode* generateBox(double x, double y, double z)
	{
		StaticObject* sn = new StaticObject(this->getOBJPool()->getMesh(mbs, "./resources/obj/cube.obj"));
		sn->setRenderStrategy(dynamic_cast<RenderStrategy*>(new MaterialRenderStrategy()));
		sn->move(SimplePoint(x,y,z));
		this->getScene()->getRoot()->addNode(sn);
		return sn;
	}

	void generateBoxLine(SimplePoint begin, SimplePoint end)
	{
		double value = 0.0;
		if(begin.x - end.x == 0 && begin.z - end.z == 0)
		{
			for(int i = 0; value + 1 <= end.y - begin.y; i++ )
				generateBox(begin.x, begin.y + value++, begin.z);
		} else
		if(begin.y - end.y == 0 && begin.z - end.z == 0)
		{
			for(int i = 0; value + 1 <= end.x - begin.x; i++ )
				generateBox(begin.x + value++, begin.y, begin.z);
		}
		if(begin.x - end.x == 0 && begin.z - end.z == 0)
		{
			for(int i = 0; value + 1 >= end.y - begin.y; i++ )
				generateBox(begin.x, begin.y + value--, begin.z);
		} else
		if(begin.y - end.y == 0 && begin.z - end.z == 0)
		{
			for(int i = 0; value + 1 >= end.x - begin.x; i++ )
				generateBox(begin.x + value--, begin.y, begin.z);
		}
	}
	void generateGate(SimplePoint center)
	{
		double width = 20, height = 20;
		SimplePoint a(center.x - width/2, center.y - width/2, center.z);
		generateBoxLine(SimplePoint(a.x,a.y,a.z), SimplePoint(a.x + width, a.y, a.z));
		generateBoxLine(SimplePoint(a.x + width, a.y, a.z), SimplePoint(a.x + width, a.y + height, a.z));
		generateBoxLine(SimplePoint(a.x + width, a.y + height, a.z), SimplePoint(a.x, a.y + height, a.z));
		generateBoxLine(SimplePoint(a.x, a.y + height, a.z), SimplePoint(a.x, a.y, a.z));
	}

	SceneNode* loadObject(std::string resource)
	{
		StaticObject* sn = new StaticObject(this->getOBJPool()->getMesh(mbs, resource));
		sn->setRenderStrategy(dynamic_cast<RenderStrategy*>(new MaterialRenderStrategy()));
		this->getScene()->getRoot()->addNode(sn);
		return sn;
	}

public:

	virtual void initializeGame(GameConfig* config)
	{
		this->getTimerClock()->addTimer(new MyTimer(1000, 10));
		mbs = dynamic_cast<MeshBuildStrategy*>(new VertexArrayBuildStrategy());
		getUserEventManager()->addObserver(new MovementObserver());

		StaticObject* s1 = new StaticObject(this->getOBJPool()->getMesh(mbs, "./resources/obj/rocket.obj"));
		s1->setRenderStrategy(dynamic_cast<RenderStrategy*>(new MaterialRenderStrategy()));
		this->getScene()->getRoot()->addNode(s1);
		s1->move(SimplePoint(10,10,100));
		s1->rotate(SimplePoint(0,90,0));
		rocket = dynamic_cast<SceneNode*>(s1);

		loadObject("./resources/obj/tunnel.obj")->rotate(SimplePoint(0,90,0));

		camera = new Camera();
		this->getScene()->setCamera(camera);
		rocket->addNode(camera);
		camera->move(SimplePoint(0,12,14));
		camera->rotate(SimplePoint(0,-90,0));
		camera->rotate(SimplePoint(-15, 0,0));

		getCollisionDetector()->addObserver(dynamic_cast<CollisionObserver*>(new CollisionObserverNotify()));
		CollisionObserverKiller* cok = new CollisionObserverKiller(new KillCommand());
		getCollisionDetector()->addObserver(dynamic_cast<CollisionObserver*>(cok));

		getCollisionDetector()->addCollisionable(s1);

		for(int i = 0; i < 20; i++)
		{
			SceneNode* box = generateBox(0, 20, -i*20);
			cok->addKiller(box);
			getCollisionDetector()->addCollisionable(box);
		}
		rocket->update(NULL);
	}
};
int main()
{
	MyGame m;
	m.start();
}
