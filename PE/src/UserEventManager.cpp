#include "../headers/UserEventManager.h"


using namespace std;

UserEventManager::UserEventManager(){

}

void UserEventManager::addObserver(UserEventObserver* observer){
	observers.push_back(observer);
}

void UserEventManager::dismissObserver(UserEventObserver* observer){
	for (int i = 0; i < observers.size(); i++){
		if (observers[i] == observer){
			observers.erase(observers.begin() + i);
		}
	}
}

void UserEventManager::notifyObservers(UserEventArgs* userEventArgs){
	for (int j = 0; j < observers.size(); j++){
		observers[j]->handleEvent(userEventArgs);
	}
}