#ifndef VBOBJECT_H

#define VBOBJECT_H

#include "Figure3D.h"

class VBObject : public Figure3D
{
protected:
	bool isTransformNeeded;
public:
	VBObject();
	virtual void draw(); //reloaded draw
};

#endif
