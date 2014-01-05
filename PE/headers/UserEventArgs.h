#ifndef USEREVENTARGS_H
#define USEREVENTARGS_H

enum InputType
{
	SpecialKeyboard, Keyboard, Mouse
}typedef InputType;

class UserEventArgs
{
protected:
	InputType type;
	char event;
public:
	bool isKeyboard();
	bool isMouse();
	UserEventArgs()
	{
		this->type = InputType();
	}
	UserEventArgs(InputType type, char event)
	{
		this->type = type;
		this->event = event;
	}
};

#endif