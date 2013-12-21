#ifndef RENDERSTRATEGY_H
#define RENDERSTRATEGY_H

class RenderStrategy
{
	virtual void prepare(RenderClues*) = 0;
	virtual void end() = 0;
};

#endif