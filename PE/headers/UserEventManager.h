#ifndef USEREVENTMANAGER_H
#define USEREVENTMANAGER_H

class UserEventManager
{
	friend class Game;
public:
	public void handleKeyboard(GLchar k);
	//TODO: handle other interrupts
};

#endif