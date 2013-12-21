#ifndef STATICOBJECT_H
#define STATICOBJECT_H

class StaticObject : public SceneNode
{
	Mesh* mesh;
public:
	virtual void render(RenderClues*);
};

#endif