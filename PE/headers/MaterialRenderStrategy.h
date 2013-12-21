#ifndef MATERIALRENDERSTRATEGY_H
#define MATERIALRENDERSTRATEGY_H

#include "RenderClues.h"

class MaterialRenderStrategy
{
public:
	virtual void prepare(RenderClues*);
	virtual void close();
};

#endif