#include "./headers/Game.h"
#include "./headers/Timer.h"

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
	}
};
int main()
{
	MyGame m;
	m.start();
}
