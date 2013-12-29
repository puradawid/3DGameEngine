#ifndef USEREVENTARGS_H
#define USEREVENTARGS_H

struct InputType
{
	enum {Keyboard, Mouse} type;
}typedef InputType;

class UserEventArgs
{
	InputType type;
	bool isKeyboard();
	bool isMouse();
};

#endif