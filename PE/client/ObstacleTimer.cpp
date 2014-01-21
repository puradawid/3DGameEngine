#include "../headers/Timer.h"
#include "../headers/SimplePoint.h"
#include "../headers/SceneNode.h"
#include "../headers/EnemyObject.h"

class ObstacleTimer : public Timer
{

private:
	std::vector<EnemyObject*> enemies;
public:

	ObstacleTimer(int ticks, int interval)
		: Timer(ticks, interval)
	{

	}

	void addEnemy(EnemyObject* enemy){
		enemies.push_back(enemy);
	}

	virtual void tick()
	{
		for (auto item : enemies)
		{
			item->nextMove();
		}
	}
};