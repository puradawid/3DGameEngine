#ifndef TEXTURERENDERSTRATEGY_H
#define TEXTURERENDERSTRATEGY_H

#include "RenderClues.h"

struct Texture
{
	//here will be Texture vars
} typedef Texture;

class TextureRenderStrategy
{
	Texture* texture;
	virtual void prepare(RenderClues*);
	virtual void close();
};

#endif