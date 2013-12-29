#ifndef TEXTHUD_H
#define TEXTHUD_H

#include "HUD.h"

#include <GL\gl.h>
#include <string>
#include <vector>

struct TextPlaces
{
	GLdouble x,y;
	std::string text;
} typedef TextPlaces;

class TextHUD : public HUD
{
	std::vector<TextPlaces> textes;
public:
	virtual void renderHUD(RenderClues*);
};

#endif