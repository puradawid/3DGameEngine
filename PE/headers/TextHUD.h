#ifndef TEXTHUD_H
#define TEXTHUD_H

#include "HUD.h"

struct TextPlaces
{
	GLdouble x,y;
	string text;
} typedef TextPlaces;

class TextHUD : public HUD
{
	std::vector<TextPlaces> textes;
public:
	virtual void renderHUD(RenderClues*);
};

#endif