#include "../headers/Figure3DNode.h"

Figure3DNode::Figure3DNode(Figure3D* obj, Point relative)
{
	this->relative = relative;
	this->object = obj;
}

Figure3DNode::Figure3DNode(Figure3D* obj)
{
	this->relative = Point(0,0,0);
	this->object = obj;
}

void Figure3DNode::runRender()
{
	this->object->render();
}
