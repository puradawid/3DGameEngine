#ifndef GAME_H
#define GAME_H
/**
 * Game class
 *
 * Game class is the main class of whole Penetration Engine.
 * With this interpretation you can write anything you want to!
*/

 class Game
 {
 private:
    //there will be all field what we dont want to leave alone
    //from UML
    Scene* scene;
    TimerClock* timerClock;
    OBJFactory* objFactory;
    CollisionDetector* collisionDetecotr;
    UserEventMenager* userEventMenager;
 protected:
    virtual void initializeGame(GameConfig* config) = 0; /// You really need to override this method - without it, it is useless
 public:
    void start(); ///Runs game by triggering this here. It is unoverrideable
    void stop();  ///Kill game - stop all displaing and unload resources - exit out

    //Getters and setters - for being more accessible
    static Game* getGameInstance();
    Scene* getScene();
    TimerClock getTimerClock();
    OBJFactory getOBJFactory();
    CollisionDetector* getCollisionDetector();
    UserEventManager* getUserEventManager();

 };

 #endif