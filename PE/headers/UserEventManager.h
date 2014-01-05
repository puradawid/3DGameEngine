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
	friend void keyboard_special_event(int, int, int);
	friend void keyboard_event(unsigned char, int, int);
	friend void mouse_function(int, int);
	std::vector<UserEventObserver*> observers;
protected:
	void propagateEvent(UserEventArgs*);
public:
	UserEventManager();
	void addObserver(UserEventObserver*);
	void dismissObserver(UserEventObserver*);
	void notifyObservers(UserEventArgs*);
};

#endif
