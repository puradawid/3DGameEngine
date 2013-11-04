#include <GL/gl.h>

#include "../headers/LinesRenderStrategy.h"
#include "../headers/Material.h"
#include "../headers/MaterialRenderStrategy.h"


MaterialRenderStrategy::MaterialRenderStrategy(double r, double g, double b)
        : LinesRenderStrategy(r, g, b)
{
    material = new Material(NULL, NULL, NULL, NULL, NULL);
}

MaterialRenderStrategy::MaterialRenderStrategy(const MaterialRenderStrategy& orig)
        : LinesRenderStrategy(orig)
{
    material = new Material(NULL, NULL, NULL, NULL, NULL);
}

void MaterialRenderStrategy::preObject()
{
    glShadeModel(GL_SMOOTH);
    glEnable( GL_COLOR_MATERIAL );
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    material->Apply();
    glBegin(GL_POLYGON);
}

void MaterialRenderStrategy::postObject()
{
    glEnd();
    glDisable(GL_LIGHTING);
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHT0);
}

void MaterialRenderStrategy::renderPolygon(vector<Point*>* polygon)
{
    preObject();
    for(int i = 0; i < polygon->size(); i++)
        glVertex3f((*polygon)[i]->x(), (*polygon)[i]->y(), (*polygon)[i]->z());
    postObject();
}
MaterialRenderStrategy::~MaterialRenderStrategy() {
}

