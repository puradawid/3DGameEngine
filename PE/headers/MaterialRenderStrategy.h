#ifndef MATERIALRENDERSTRATEGY_H
#define MATERIALRENDERSTRATEGY_H

#include "RenderClues.h"
#include "RenderStrategy.h"

class MaterialRenderStrategy : public RenderStrategy
{
public:
	virtual void prepare(RenderClues*);
	virtual void end();
};

#endif