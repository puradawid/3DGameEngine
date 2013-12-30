#ifdef PROBLEM
#include <cstdlib>
#include <iostream>
#include <math.h>

//OpenGL for windows
#ifdef _MSC_VER
#include <Windows.h>
#endif
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
#include "3dmodel/headers/Camera.h"
#include "3dmodel/headers/Scene.h"
#include "3dmodel/headers/Material.h"
#include "3dmodel/headers/TreeScene.h"
#include "3dmodel/headers/TreeNode.h"
#include "3dmodel/headers/Figure3DNode.h"
#include "3dmodel/headers/OBJBuilder.h"
#include "3dmodel/headers/XMLSceneBuilder.h"

using namespace std;

vector<CubeGL*> cubes;

enum Perspective {
    ORTHOGONAL,
    PERSPECTIVE
};


static Perspective perspective;

TreeScene* world;

GLfloat* light;

//render method

Camera camera;

static LinesRenderStrategy* lrs;
static MaterialRenderStrategy* mrs;
static TextureRenderStrategy* trs;

Camera initialize_camera() {
    Camera stc;
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
    glutSetCursor(GLUT_CURSOR_NONE);
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
    
    //for (int i = 0; i < cubes.size(); i++)
    //    cubes[i]->render();
    world->render();
    //foreach(element in scene) element.render();

    //temporarily render floor - not elegant but enough for now
    Material mat(0,0,0,0,0);
    mat.Apply();
    glBegin(GL_QUADS);
    	glVertex3f(-1000.0, -0.5, 1000.0);
    	glVertex3f(1000.0, -0.5, 1000.0);
    	glVertex3f(1000.0, -0.5, -1000.0);
    	glVertex3f(-1000.0, -0.5, -1000.0);
    glEnd();

    glutSwapBuffers();
    //glFlush();
}
void reshape(int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    if (perspective == PERSPECTIVE)
        gluPerspective(60, (GLfloat) width / (GLfloat) height, 1.0, 100.0);
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
            camera.move(0.1, 0);
            break;
        case GLUT_KEY_RIGHT:
            camera.move(-0.1, 0);
            break;
        case GLUT_KEY_UP:
            camera.move(0, 0.1);
            break;
        case GLUT_KEY_DOWN:
            camera.move(0, -0.1);
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
    //glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_NORMALIZE);

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
    GLfloat light1_position[] = {3, 0.0, 0.0, 1.0};
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

    //trs->init();
    perspective = PERSPECTIVE;
}

//"old" position of mouse
int x_mouse_pos = 0;
int y_mouse_pos = 0;

void mouseFunction(int x, int y)
{
	x_mouse_pos = glutGet(GLUT_WINDOW_WIDTH)/2;
	y_mouse_pos = glutGet(GLUT_WINDOW_HEIGHT)/2;
	//if(x == glutGet(GLUT_WINDOW_WIDTH)/2 && y == glutGet(GLUT_WINDOW_HEIGHT)/2) return;
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
	//broken code
	glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH)/2, glutGet(GLUT_WINDOW_HEIGHT)/2);

	//glutPostRedisplay();
	reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void generateKloc(float x, float y, float z)
{
	Point p(0, 0, 0);
	CubeGL *c2;
	c2 = new CubeGL(p, 1);
	c2->moveFigure(x,y,z);
	c2->setStrategy(mrs);
	TreeNode *t = new Figure3DNode(dynamic_cast<Figure3D*>(c2), Point(x,y,z));
	world->getRoot()->addChild(t);
}


int main(int argc, char** argv) {
	OBJBuilder builder("resources/obj/rocket.obj");
	XMLSceneBuilder xsb("resources/scene.xml");
	world = dynamic_cast<TreeScene*>(xsb.buildScene());
	//world = new TreeScene();

	Figure3D* rocket = builder.build();

	glut_init(&argc, argv); //initialize first GLUT window

    //builder.build();

    //init strategies
    lrs = new LinesRenderStrategy(0.1, 0.1, 0.1);
    mrs = new MaterialRenderStrategy(0.1, 0.5, 0.1);
    //trs = new TextureRenderStrategy();

    light = new GLfloat[4];
    light[0] = 1.0;
    light[1] = 1.0;
    light[2] = 1.0;
    light[3] = 1;

    //for(int i = 0; i < 100; i++)
    //	generateKloc(i,i,i);
    rocket->setRenderStrategy(mrs);
    //world->getRoot()->addChild(new Figure3DNode(rocket, Point(0,0,0)));

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
#endif

/**
 * Here ends legacy code - it is not neccessary to hide, but you need
 * to know old legacy before you will port this classes to new code, so
 * even you just scroll down code - maybe you will discover something
 * new.
 */
#ifdef _MSC_VER
#include <Windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

#ifdef __MINGW32__
	#include <GL/glut.h>
#else
	#include <GL/freeglut.h>
#endif

#include "../headers/Game.h"
#include "../headers/TimerClock.h"

 //it is awful but..
 Game* Game::singleton = 0x0; //initialization of singleton expression

 void Game::start()
 {
    this->prepareInstance(config); //prepare instance of system - make some fields, load data, etc
    this->initializeGame(config); //ok - what user want to do? Answer.
    this->startLoop(); //jumping to loop - without any window :)
 }

 void Game::prepareInstance(GameConfig* gameConfig)
 {

 }

int timestamp;  
void msTick()
{
    int time_left = glutGet(GLUT_ELAPSED_TIME) - timestamp; //in ms
    timestamp = glutGet(GLUT_ELAPSED_TIME);
    Game::getGameInstance()->getTimerClock()->inform(time_left);
}

void tick()
{
    msTick();
    glutPostRedisplay();
}

 void Game::startLoop()
 {
    glutInitWindowSize(this->config->getIntAttribute("h_resolution"),
    	               this->config->getIntAttribute("v_resolution"));
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow(const_cast<const char*>(this->config->getAttribute("window_name").c_str()));
    glutSetCursor(GLUT_CURSOR_NONE);

 	glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard_event);
    glutSpecialFunc(keyboard_special_event);
    glutPassiveMotionFunc(mouse_function);
    glutIdleFunc(tick);

    //provide control for GLUT
    timestamp = glutGet(GLUT_ELAPSED_TIME);
    glutMainLoop();
}

void display()
{
	//here rendering
    // Clear frame buffer and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //drawing

    RenderClues* rc = new RenderClues();
    Game::getGameInstance()->scene->render(rc);
    delete rc;

    glBegin(GL_QUADS);
        glVertex3f(-1000.0, -0.5, 1000.0);
        glVertex3f(1000.0, -0.5, 1000.0);
        glVertex3f(1000.0, -0.5, -1000.0);
        glVertex3f(-1000.0, -0.5, -1000.0);
    glEnd();

    glutSwapBuffers();
}

void mouse_function(int x, int y)
{
	//push mouse event
}

void reshape(int width, int height)
{
	//reshape when something is wrong
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(60, (GLfloat) width / (GLfloat) height, 1.0, 100.0);
}

void keyboard_event(unsigned char key, int x, int y)
{
	//here is event from keyboard
}

void keyboard_special_event(int event, int x, int y)
{

}

void Game::stop()
{
	//need to be implemented like others ;)
}

Game::Game()
{
    config = dynamic_cast<GameConfig*>(new TypicalConfig());
    timerClock = new TimerClock();
    scene = new Scene();
    objPool = new OBJPool();
    singleton = this;
}

Game::~Game()
{
    delete this->config;
}