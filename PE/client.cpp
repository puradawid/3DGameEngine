#include "./headers/Game.h"
#include "./headers/Timer.h"
#include "./headers/MeshBuildStrategy.h"
#include "./headers/VertexArrayBuildStrategy.h"
#include "./headers/StaticObject.h"

#include <stdio.h>

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
		this->getScene()->getRoot()->addNode(sn);
	}
};
int main()
{
	MyGame m;
	m.start();
}
