#ifndef LINERENDERSTRATEGY_H
#define LINERENDERSTRATEGY_H

#include "RenderClues.h"
#include "RenderStrategy.h"

class LineRenderStrategy : public RenderStrategy
{
public:
	virtual void prepare(RenderClues*);
	virtual void end();
};

#endif