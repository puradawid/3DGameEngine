#ifndef USEREVENTOBSERVER_H
#define USEREVENTOBSERVER_H

class UserEventObserver
{
public: 
	virtual void handleMouse(UserEventArgs*);
	virtual void handleKeyboard(UserEventArgs*);
};

#endif