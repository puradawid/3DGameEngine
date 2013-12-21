#ifndef USEREVENTARGS_H
#define USEREVENTARGS_H

class UserEventArgs
{
	InputType type;
	bool isKeyboard();
	bool isMouse();
};

#endif