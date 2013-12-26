#ifndef OBJECTID_H
#define OBJECTID_H

#include <Gl\gl.h>

struct ObjectId
{
	GLint id;
	ObjectId(int id)
	{
		this->id = id;
	}

	ObjectId()
	{
		this->id = 0;
	}
} typedef ObjectId;

#endif