#include "../headers/MaterialRenderStrategy.h"
#ifdef _MSC_VER
#include <Windows.h>
#endif
#include <GL/gl.h>

void MaterialRenderStrategy::prepare(RenderClues* renderClues){
	glBegin(GL_TRIANGLES);
}

void MaterialRenderStrategy::end(){
	glEnd();
}