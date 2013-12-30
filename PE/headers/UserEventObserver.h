#ifndef USEREVENTOBSERVER_H
#define USEREVENTOBSERVER_H

#include "UserEventArgs.h"

class UserEventObserver
{
public: 
	virtual void handleEvent(UserEventArgs*);
};

#endif