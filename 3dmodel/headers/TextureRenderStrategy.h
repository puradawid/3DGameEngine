#ifndef TEXTURERENDERSTRATEGY_H
#define	TEXTURERENDERSTRATEGY_H

#include "GLRenderStrategy.h"

#include <GL/gl.h>

#include <vector>

class TextureRenderStrategy : public GLRenderStrategy{
public:
    TextureRenderStrategy();      //construct default texture
    TextureRenderStrategy(const TextureRenderStrategy& orig);
    TextureRenderStrategy(char*); //construct texture from file?
    virtual void renderPolygon(vector<Point*>*);
    virtual void init();
    virtual ~TextureRenderStrategy();
protected:
    GLint tex_w, tex_h;       //size of tex
    GLubyte ***tex;             //3-dimensional matrix of tex
    GLuint tex_name;
    std::vector<std::pair<GLdouble, GLdouble> > tex_points;
    
private:

};

#endif	/* TEXTURERENDERSTRATEGY_H */

