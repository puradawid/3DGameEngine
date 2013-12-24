#include "./headers/Game.h"

class MyGame : public Game
{

public:
	virtual void initializeGame(GameConfig* config)
	{
	}
};
int main()
{
	MyGame m;
	m.start();
}
