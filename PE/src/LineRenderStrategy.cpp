#include "../headers/LineRenderStrategy.h"
#ifdef _MSC_VER
#include <Windows.h>
#endif
#include <Gl/gl.h>

void LineRenderStrategy::prepare(RenderClues* renderClues){
	glBegin(GL_LINES);
}

void LineRenderStrategy::end(){
	glEnd();
}
