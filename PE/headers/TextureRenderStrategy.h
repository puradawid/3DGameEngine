#ifndef TEXTURERENDERSTRATEGY_H
#define TEXTURERENDERSTRATEGY_H

class TextureRenderStrategy
{
	Texture* texture;
	virtual void prepare(RenderClues*);
	virtual void close();
};

#endif