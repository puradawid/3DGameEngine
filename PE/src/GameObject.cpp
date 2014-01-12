#include "../headers/GameObject.h"

void GameObject::render(RenderClues* renderClues) 
{
	this->mesh->render(renderClues);
}