//Eric Faust - esfaust
//IMGD3000 Project 2
#include "Manager.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "EventStep.h"

#include <string>

//Constructor
Manager::Manager(){
}

//Destructor
Manager::~Manager(){
}

//sets the type of the manager
void Manager::setType(std::string t){
  type = t;
}

//Returns type of the manager
std::string Manager::getType() const{
  return type;
}

//Starts the manager
int Manager::startUp() {
  is_started = true;
}

//Shuts down the manager
void Manager::shutDown() {
  is_started = false; 
}

//Returns is_started
bool Manager::isStarted() const {
  return is_started;
}

//Sends the event to all objects being managed.
int Manager::onEvent(Event *p_event){
  int count=0;
  ObjectList objects = WorldManager::getInstance().getAllObjects();
  ObjectListIterator oli(&objects);
  for(oli.first(); !oli.isDone(); oli.next()){
    oli.currentObject()->eventHandler(p_event);
    count++;
  }
  return count;
}
