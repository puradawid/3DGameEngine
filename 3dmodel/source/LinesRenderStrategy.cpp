#include "../headers/GLRenderStrategy.h"
#include "../headers/LinesRenderStrategy.h"
#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>

using namespace std;


LinesRenderStrategy::LinesRenderStrategy(double r, double g, double b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

LinesRenderStrategy::LinesRenderStrategy(const LinesRenderStrategy& orig) {
}

LinesRenderStrategy::~LinesRenderStrategy() {
}

void LinesRenderStrategy::renderLines(vector<Point*> *points_ptr, void* parameters)
{
    /* 
    //@Deprecated
    vector<Point*> points = *points_ptr;
    vector< pair<int, int> > *lines = (vector<pair<int, int> >*)(parameters);
    //iteration
    for(int i=0; i < lines->size(); i++)
    {
        int first = (*lines)[i].first;
        int second = (*lines)[i].second;
        glColor3f(this->r, this->g, this->b);
        glVertex3f(points[first]->x(), points[first]->y(), points[first]->z());
        glColor3f(this->r, this->g, this->b);
        glVertex3f(points[second]->x(), points[second]->y(), points[second]->z());
    }
    */ 
}

void LinesRenderStrategy::renderPolygon(vector<Point*>* polygon)
{
    preObject();
    for(int j = 0; j < polygon->size(); j++)
    {
        Point *p1 = (*polygon)[j];
        Point *p2 = NULL;
        if(j+1 == polygon->size())
            p2 = (*polygon)[0];
        else
            p2 = (*polygon)[j+1];
        glVertex3f(p1->x, p1->y, p1->z);
        glVertex3f(p2->x, p2->y, p2->z);
    }
    postObject();
        
}

void LinesRenderStrategy::preObject()
{
    GLboolean light;
    glGetBooleanv(GL_LIGHTING, &light);
    if(light == GL_TRUE)
        glDisable(GL_LIGHTING);
    glColor3f(this->r, this->g, this->b);
    glBegin(GL_LINES);
}

void LinesRenderStrategy::postObject()
{
    GLboolean light;
    glGetBooleanv(GL_LIGHTING, &light);
    if(light == GL_TRUE)
        glEnable(GL_LIGHTING);
    glEnd();
}

