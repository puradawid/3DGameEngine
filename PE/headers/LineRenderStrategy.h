#ifndef LINERENDERSTRATEGY_H
#define LINERENDERSTRATEGY_H

#include "RenderClues.h"

class LineRenderStrategy
{
public:
	virtual void prepare(RenderClues*);
	virtual void close();
};

#endif