#include "../headers/UserEventArgs.h"

bool UserEventArgs::isKeyboard(){
	if(type == InputType::Keyboard) 
		return true; 
	return false;
}

bool UserEventArgs::isMouse(){
	if(type == InputType::Mouse) 
		return true; 
	return false;
}

bool UserEventArgs::isSpecialKeyboard()
{
	if(type == InputType::SpecialKeyboard) 
		return true; 
	return false;
}