#ifndef GAME_H
#define GAME_H

#include "OBJPool.h"
#include "UserEventManager.h"
#include "CollisionDetector.h"
#include "GameConfig.h"
#include "TimerClock.h"
#include "Mesh.h"
#include "Collision.h"
#include "Scene.h"
#include "Camera.h"


//implementation
 void display();
 void reshape(int, int);
 void keyboard_event(unsigned char, int, int);
 void keyboard_special_event(int, int, int);
 void mouse_function(int, int);

/**
 * Game class
 *
 * Game class is the main class of whole Penetration Engine.
 * With this interpretation you can write anything you want to!
*/

 class Game
 {
 //friends declatarion
 friend void display();
 friend void reshape(int, int);
 friend void keyboard_event(unsigned char, int, int);
 friend void keyboard_special_event(int, int, int);
 friend void mouse_function(int);

 private:
    Scene* scene;
    TimerClock* timerClock;
    OBJPool* objPool;
    CollisionDetector* collisionDetecotr;
    UserEventManager* userEventMenager;
    GameConfig* config;

    static Game* singleton;

    //private methods for GL communication
    void startLoop();
    void prepareInstance(GameConfig*);

 protected:
    virtual void initializeGame(GameConfig* config) = 0; /// You really need to override this method - without it, it is useless
 public:
    void start(); ///Runs game by triggering this here. It is unoverrideable
    void stop();  ///Kill game - stop all displaing and unload resources - exit out

    //Getters and setters - for being more accessible
    static Game* getGameInstance() {return singleton;}
    Scene* getScene();
    TimerClock getTimerClock();
    OBJPool getOBJPool();
    CollisionDetector* getCollisionDetector();
    UserEventManager* getUserEventManager();
 };

 #endif
