#include <GL/gl.h>

#include "../headers/LinesRenderStrategy.h"
#include "../headers/Material.h"
#include "../headers/MaterialRenderStrategy.h"

#include <iostream>

using namespace std;


inline void setNormals(vector<double*>* v)
{
    double a[] = {0,0,1};
    double b[] = {0,0,-1};
    double c[] = {0,-1,0};
    double d[] = {0,1,0};
    double e[] = {-1, 0, 0};
    double f[] = {1, 0,0};
    v->push_back(a);
    v->push_back(b);
    v->push_back(c);
    v->push_back(d);
    v->push_back(e);
    v->push_back(f);
}


MaterialRenderStrategy::MaterialRenderStrategy(double r, double g, double b)
        : LinesRenderStrategy(r, g, b)
{
    material = new Material(NULL, NULL, NULL, NULL, 0.0);
    counter = 0;
    setNormals(&normals);
}

MaterialRenderStrategy::MaterialRenderStrategy(const MaterialRenderStrategy& orig)
        : LinesRenderStrategy(orig)
{
    material = new Material(NULL, NULL, NULL, NULL, 0.0);
    counter = 0;
    setNormals(&normals);
}
void MaterialRenderStrategy::preObject()
{
    //glShadeModel(GL_SMOOTH);
    //glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_NORMALIZE);
    //above move to main.cpp
    
    GLboolean light;
    glGetBooleanv(GL_LIGHTING, &light);
    if(light == GL_FALSE)
        glEnable(GL_LIGHTING);
    material->Apply();
    //glBegin(GL_QUADS);
}

void MaterialRenderStrategy::postObject()
{
    //glEnd();
    //glDisable(GL_LIGHTING);
    //glDisable(GL_COLOR_MATERIAL);
    //glDisable(GL_LIGHT0);
}

void MaterialRenderStrategy::renderPolygon(vector<Point*>* polygon)
{
    glPushMatrix();
    preObject();
    glBegin(GL_POLYGON);
    counter++;
    for(int i = 0; i < polygon->size(); i++)
    {
        material->Apply();
        glNormal3f((*polygon)[i]->normal.x, (*polygon)[i]->normal.y, (*polygon)[i]->normal.z);
        glVertex3f((*polygon)[i]->x, (*polygon)[i]->y, (*polygon)[i]->z);
    }
    glEnd();
    postObject();
    glPopMatrix();
}
MaterialRenderStrategy::~MaterialRenderStrategy() {
}

