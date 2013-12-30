#include "../headers/LineRenderStrategy.h"

#include <Gl/gl.h>

void LineRenderStrategy::prepare(RenderClues* renderClues){
	glBegin(GL_LINES);
}

void LineRenderStrategy::end(){
	glEnd();
}
