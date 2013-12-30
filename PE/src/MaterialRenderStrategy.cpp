#include "../headers/MaterialRenderStrategy.h"

#include <GL/gl.h>

void MaterialRenderStrategy::prepare(RenderClues* renderClues){
	glBegin(GL_TRIANGLES);
}

void MaterialRenderStrategy::end(){
	glEnd();
}