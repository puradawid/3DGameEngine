#include "../headers/TextureRenderStrategy.h"
#include "../headers/GLRenderStrategy.h"

#include <GL/gl.h>


#define bc_w 64
#define bc_h 64

TextureRenderStrategy::TextureRenderStrategy() {
    this->tex_h = bc_h;
    this->tex_w = bc_w;
    int i, j, c;
    
    this->tex = new GLubyte**[bc_h];
    for(int i = 0; i < bc_h; i++)
    {
        tex[i] = new GLubyte*[bc_w];
        for(int j = 0; j < bc_w; j++)
        {
            tex[i][j] = new GLubyte[4];
            for(int k = 0; k < 4; k++)
                tex[i][j][k] = 0;
        }
            
    }
    for (i = 0; i < tex_h; i++) {
        for (j = 0; j < tex_w; j++) {
            c = ((((i & 0x8) == 0)^((j & 0x8)) == 0))*255;
            tex[i][j][0] = (GLubyte) c;
            tex[i][j][1] = (GLubyte) c;
            tex[i][j][2] = (GLubyte) c;
            tex[i][j][3] = (GLubyte) 255;
        }
    }
    tex_points.push_back(*(new pair<GLdouble, GLdouble> (0, 1)));
    tex_points.push_back(*(new pair<GLdouble, GLdouble> (1, 1)));
    tex_points.push_back(*(new pair<GLdouble, GLdouble> (1, 0)));
    tex_points.push_back(*(new pair<GLdouble, GLdouble> (0, 0)));
}

void TextureRenderStrategy::init()
{
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

   glGenTextures(1, &tex_name);
   glBindTexture(GL_TEXTURE_2D, tex_name);

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, 
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
                   GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex_w, 
                tex_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, 
                tex);
}

void TextureRenderStrategy::renderPolygon(vector<Point*>* polygon)
{
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
   glBindTexture(GL_TEXTURE_2D, tex_name);
   glBegin(GL_QUADS);
   for(int i=0; i < polygon->size(); i++)
   {
       Point *p = (*polygon)[i]; 
       glTexCoord2d(tex_points[i].first, tex_points[i].second);
       glVertex3f(p->x(), p->y(), p->z());
   }
   glEnd();
   glDisable(GL_TEXTURE_2D);
}

TextureRenderStrategy::TextureRenderStrategy(const TextureRenderStrategy& orig) {
}

TextureRenderStrategy::~TextureRenderStrategy() {
}

