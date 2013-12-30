#ifndef USEREVENTMANAGER_H
#define USEREVENTMANAGER_H
#ifdef _MSC_VER
#include <Windows.h>
#endif
#include <GL/gl.h>
#include "UserEventObserver.h"
#include <vector>
class UserEventManager
{
	friend class Game;
	std::vector<UserEventObserver*> observers;
public:
	UserEventManager();
	void addObserver(UserEventObserver*);
	void dismissObserver(UserEventObserver*);
	void notifyObservers(UserEventArgs*);
};

#endif
