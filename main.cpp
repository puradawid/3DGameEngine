#include <cstdlib>
#include <iostream>
#include <math.h>

//OpenGL for windows
#ifdef _WIN32
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/glut.h>
#else //OpenGL for Linux and other stuff (if there will be no OS, add another)
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/freeglut.h>
#endif

#define _USE_MATH_DEFINES

#include <vector>

#include "3dmodel/headers/Point.h"
#include "3dmodel/headers/Cube.h"
#include "3dmodel/headers/CubeGL.h"
#include "3dmodel/headers/LinesRenderStrategy.h"
#include "3dmodel/headers/MaterialRenderStrategy.h"
#include "3dmodel/headers/TextureRenderStrategy.h"

using namespace std;

vector<CubeGL*> cubes;

enum Perspective {
    ORTHOGONAL,
    PERSPECTIVE
};


static Perspective perspective;

GLfloat* light;

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

    //rotateFunction -> more than important
    void rotateX(float angle) {if(angle > 0 && center.x >= 360) center.x = 0; else center.x += angle;}
    void rotateY(float angle) {if(angle > 0 && center.y >= 360) center.y = 0; else center.y += angle;}
    void move(float x, float z) {
    	//rotate vector x, z in point 0,0;
    	float angle = (center.x/180) * M_PI;
    	float x_r = x*cos(angle) - z*sin(angle);
    	float z_r = x*sin(angle) + z*cos(angle);
    	//add it to existing position
    	eye.z += z_r;
    	eye.x += x_r;
    }
} camera;

static LinesRenderStrategy* lrs;
static MaterialRenderStrategy* mrs;
static TextureRenderStrategy* trs;

struct Camera initialize_camera() {
    struct Camera stc;
    stc.eye.x = 0.0;
    stc.eye.y = 0.0;
    stc.eye.z = 0.0;
    stc.center.x = 0.0;
    stc.center.y = 0.0;
    stc.center.z = 0.0;
    stc.up.x = 0;
    stc.up.y = 1;
    stc.up.z = 0;
    return stc;
}

inline void glut_init(int* argc, char** argv) {
    glutInit(argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("This is test window");
}

void changeCameraPos(GLfloat*pos) {
    for (int i = 0; i < 1; i++)
        if (pos[i] > 2)
            pos[i] = 0;
        else
            pos[i] += 0.1;
}

void display(void) {
    // Clear frame buffer and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //if you want to move
    glRotatef(camera.center.y, 1.0, 0, 0);
    glRotatef(camera.center.x, 0, 1.0, 0);

    glTranslatef(camera.eye.x, camera.eye.y, camera.eye.z);

    //sets light position with camera
    glLightfv(GL_LIGHT0, GL_POSITION, light);
    
    for (int i = 0; i < cubes.size(); i++)
        cubes[i]->render();

    //temporarily render floor - not elegant but enough for now
    glBegin(GL_QUADS);
    	glVertex3f(-1000.0, -0.5, 1000.0);
    	glVertex3f(1000.0, -0.5, 1000.0);
    	glVertex3f(1000.0, -0.5, -1000.0);
    	glVertex3f(-1000.0, -0.5, -1000.0);
    glEnd();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    if (perspective == PERSPECTIVE)
        gluPerspective(60, (GLfloat) width / (GLfloat) height, 1.0, 10.0);
    else
        glOrtho(0, width, 0, height, 0, 10); //it is not working ?
    display();
}

void menu_function_context(int parameter) {
    switch (parameter) {
        case 1:
            //handle wire
            cubes[0]->setStrategy(lrs);
            break;
        case 2:
            //handle solid
            cubes[0]->setStrategy(mrs);
            break;
        case 3:
            //handle textured
            cubes[0]->setStrategy(trs);
            break;
    }
    //..at least refresh screen? :D
    reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void keyboard_event(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            camera.center.x += 1;
            break;
        case 's':
            camera.center.x -= 1;
            break;
        case 'a':
            camera.center.y -= 1;
            break;
        case 'd':
            camera.center.y += 1;
            break;
	case 'r':
	    camera.eye.y += 0.1;
	    break;
	case 'f':
	   camera.eye.y -= 0.1;
	break; 
    }
    reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void keyboard_special_event(int event, int x, int y) {
    switch (event) {
        case GLUT_KEY_LEFT:
            camera.move(-0.1, 0);
        	//camera.eye.x -= 0.1;
            break;
        case GLUT_KEY_RIGHT:
            camera.move(0.1, 0);
        	//camera.eye.x += 0.1;
            break;
        case GLUT_KEY_UP:
            camera.move(0, 0.1);
        	//camera.eye.z += 0.1;
            break;
        case GLUT_KEY_DOWN:
            camera.move(0, -0.1);
        	//camera.eye.z -= 0.1;
            break;
    }
    reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void menu_function(int parameter) {
    switch (parameter) {
        case 1:
            exit(0);
            break;
        case 2:
            camera = initialize_camera();
            break;
        case 3:
            perspective = ORTHOGONAL;
            break;
        case 4:
            perspective = PERSPECTIVE;
            break;
    }
    reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

inline void open_gl_init() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_SHORT);

    //menu adding?
    glutCreateMenu(menu_function); //creation by passing handling function
    glutAddMenuEntry("Exit", 1); //adding menu entry as Exit
    glutAddMenuEntry("Reset position", 2); //adding menu entry as Exit
    glutAddMenuEntry("Otho", 3); //Orthogonal projection
    glutAddMenuEntry("Perspective", 4); //Perspective projection
    glutAttachMenu(GLUT_RIGHT_BUTTON); //attaching menu as right button event

    //context menu
    glutCreateMenu(menu_function_context);
    glutAddMenuEntry("Lines", 1);
    glutAddMenuEntry("Solid", 2);
    glutAddMenuEntry("Textured", 3);
    glutAttachMenu(GLUT_LEFT_BUTTON);

    //general settings
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    //light settings
    GLfloat light_diffuse[] = {1, 1, 1, 1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    GLfloat light_ambient[] = {0.2, 0.2, 0.2, 1};
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    GLfloat light_specular[] = {0.1, 0.1, 0.1, 1};
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    GLfloat light1_ambient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat light1_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light1_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light1_position[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat spot_direction[] = {-1.0, -1.0, 0.0};

    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

    glEnable(GL_LIGHT1);

    trs->init();
    perspective = PERSPECTIVE;
}

//"old" position of mouse
int x_mouse_pos = 0;
int y_mouse_pos = 0;

void mouseFunction(int x, int y)
{
	if(x_mouse_pos == 0 && y_mouse_pos == 0)
		{ x_mouse_pos = x; y_mouse_pos = y; return; }
	//there is changing x and y;
	if(x - x_mouse_pos > 0)
		camera.rotateX(0.7);
	if(x - x_mouse_pos < 0)
		camera.rotateX(-0.7);
	if(y - y_mouse_pos > 0)
		camera.rotateY(0.7);
	if(y - y_mouse_pos < 0)
		camera.rotateY(-0.7);

	//store old position
	x_mouse_pos = x; y_mouse_pos = y;

	reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}


int main(int argc, char** argv) {
    glut_init(&argc, argv); //initialize first GLUT window

    //init strategies
    lrs = new LinesRenderStrategy(0.1, 0.1, 0.1);
    mrs = new MaterialRenderStrategy(0.1, 0.5, 0.1);
    trs = new TextureRenderStrategy();

    light = new GLfloat[4];
    light[0] = 1.0;
    light[1] = 1.0;
    light[2] = 1.0;
    light[3] = 1;

    Point p2(-0.5, 0, -5);
    CubeGL *c;
    c = new CubeGL(p2, 1);
    c->setStrategy(lrs);

    cubes.push_back(c);

    camera = initialize_camera();
    open_gl_init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard_event);
    glutSpecialFunc(keyboard_special_event);
    glutPassiveMotionFunc(mouseFunction);

    //provide control for GLUT
    glutMainLoop();

    for (int i = 0; i < cubes.size(); i++)
        delete cubes[i];
    return 0;
}

