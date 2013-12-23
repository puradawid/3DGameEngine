#ifndef USEREVENTMANAGER_H
#define USEREVENTMANAGER_H

#include <GL/gl.h>

class UserEventManager
{
	friend class Game;
public:
	void handleKeyboard(char k);
	//TODO: handle other interrupts
};

#endif
