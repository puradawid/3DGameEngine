#include <cstdlib>
#include <iostream>
#include <GL\gl.h>
#include <GL\glu.h>
#include <vector>
#include "glut\glut.h"

#include "3dmodel/headers/Point.h"
#include "3dmodel/headers/Cube.h"
#include "3dmodel/headers/CubeGL.h"
#include "3dmodel/headers/LinesRenderStrategy.h"
#include "3dmodel/headers/MaterialRenderStrategy.h"

using namespace std;

static float adding = 0.1; //add to position after display method
static float x_pos = 0.00;
static float y_pos = 0.00;

static GLdouble fovy = 60;

vector<CubeGL*> cubes;

//render method
static struct Camera {

    struct Eye {
        GLdouble x;
        GLdouble y;
        GLdouble z;
    } eye;

    struct Center {
        GLdouble x;
        GLdouble y;
        GLdouble z;
    } center;
    
    struct Up {
        GLdouble x;
        GLdouble y;
        GLdouble z;
    } up;
} camera;

struct Camera initialize_camera()
{
    struct Camera stc;
    stc.eye.x = 0.0;
    stc.eye.y = 0.0;
    stc.eye.z = 0.0;
    stc.center.x = 0.0;
    stc.center.y = 0.0;
    stc.center.z = -1;
    stc.up.x = 0;
    stc.up.y = 1;
    stc.up.z = 0;
    return stc;
}

//Ligth



void render_polygon(double x, double y) {
    glBegin(GL_POLYGON);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);

    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);

    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);

    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);

    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);

    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glEnd();
}


//open_gl_init initalize the OpenG

inline void glut_init(int* argc, char** argv) {
    glutInit(argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("This is test window");
}

void display(void) {
    // Clear frame buffer and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(camera.eye.x, camera.eye.y, camera.eye.z, camera.center.x,
    //          camera.center.y, camera.center.z, camera.up.x, camera.up.y, camera.up.z);
    
    glRotatef(camera.center.x, 0, 1.0 ,0);
    glRotatef(camera.center.y, 1.0, 0 ,0);
    glTranslatef(camera.eye.x, camera.eye.y, camera.eye.z);
    for(int i=0; i < cubes.size(); i++)
       cubes[i]->render();

    glFlush();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    //glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    
    gluPerspective (60, (GLfloat)width / (GLfloat)height, 1.0, 1000.0);
    //if (width < height && width > 0)
    //    glFrustum(-2.0, 2.0, -2.0 * height / width, 2.0 * height / width, 1.0, 5.0);

    //if (width >= height && height > 0)
    //    glFrustum(-2.0 * width / height, 2.0 * width / height, -2.0, 2.0, 1.0, 5.0);

    display();
}

void menu_function_context(int parameter) {
    switch(parameter)
    {
        case 1:
            //handle wire
            cubes[0]->setStrategy(new LinesRenderStrategy(0.1, 0.1, 0.1));
            break;
        case 2:
            //handle solid
            cubes[0]->setStrategy(new MaterialRenderStrategy(0.1, 0.1, 0.1));
            break;
        case 3:
            //handle textured
            break;
    }
    //..at least refresh screen? :D
    reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void keyboard_event(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            camera.center.y += 1;
            break;
        case 's':
            camera.center.y -= 1;
            break;
        case 'a':
            camera.center.x -= 1;
            break;
        case 'd':
            camera.center.x += 1;
            break;
    }
    reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void keyboard_special_event(int event, int x, int y)
{
    switch(event)
    {
        case GLUT_KEY_LEFT:
            camera.eye.x -= 0.1;
            break;
            case GLUT_KEY_RIGHT:
            camera.eye.x += 0.1;
            break;
            case GLUT_KEY_UP:
            camera.eye.y -= 0.1;
            break;
            case GLUT_KEY_DOWN:
            camera.eye.y += 0.1;
            break;
    }
    reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void menu_function(int parameter) {
    switch(parameter)
    {
        case 1:
            exit(0);
            break;
        case 2: 
            camera = initialize_camera();
            break;
    }
    reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

inline void open_gl_init() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_SHORT);
    GLfloat globalAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
    glLightModelfv( GL_LIGHT_MODEL_AMBIENT, globalAmbient );

    //menu adding?
    glutCreateMenu(menu_function); //creation by passing handling function
    glutAddMenuEntry("Exit", 1); //adding menu entry as Exit
    glutAddMenuEntry("Reset position", 2); //adding menu entry as Exit
    glutAttachMenu(GLUT_RIGHT_BUTTON); //attaching menu as right button event

    //context menu
    glutCreateMenu(menu_function_context);
    glutAddMenuEntry("Lines", 1);
    glutAddMenuEntry("Solid", 2);
    glutAddMenuEntry("Textured", 3);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}

int main(int argc, char** argv) 
{
    glut_init(&argc, argv); //initialize first GLUT window
    //generate more than one
    /*
    for(int i=0; i < 10; i++)
    {
        Point p(1 * i, 0.0, -2.0); 
        CubeGL *cube = new CubeGL(p, 0.5);
        cube->setStrategy(new MaterialRenderStrategy(0.4,.2,0.1));
        cubes.push_back(cube);
    }
    */
    
    
    Point p1(1,0,-2);
    Point p2(2,1,-2);
    CubeGL *c1, *c2;
    c1 = new CubeGL(p1, 0.6);
    c1->setStrategy(new MaterialRenderStrategy(0,0,0));
    c2 = new CubeGL(p2, 0.4);
    c2->setStrategy(new LinesRenderStrategy(0.1,0.5,0));
    
    //cubes.push_back(c1);
    cubes.push_back(c2);
    
    camera = initialize_camera();
    open_gl_init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard_event);
    glutSpecialFunc(keyboard_special_event);

    //provide control for GLUT
    glutMainLoop();
    
    for(int i = 0; i < cubes.size(); i++)
        delete cubes[i];
    return 0;
}

