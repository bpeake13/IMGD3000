//Eric Faust - esfaust
//IMGD3000 Project 2
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "EventOut.h"
#include "LogManager.h"
#include "EventCollision.h"
#include "Utility.h"

WorldManager::WorldManager(){}
WorldManager::WorldManager(WorldManager const&){}
void WorldManager::operator=(WorldManager const&){}

//Returns singleton instance
WorldManager &WorldManager::getInstance(){
  static WorldManager wm;
  return wm;  
}

//Starts the world manager with default
int WorldManager::startUp(){
  Manager::startUp();  
  return 1;
}

//Shuts down the wolrd manager and deletes all objects.
void WorldManager::shutDown(){
  LogManager &lm = LogManager::getInstance();
  ObjectListIterator oli(&updates);

  lm.writeLog("Deleting %d objects.", updates.getCount());
  for(oli.first(); !oli.isDone(); oli.next()){
    delete oli.currentObject();
  }
  if(!updates.isEmpty()){
    lm.writeLog("World manager failed to delete all objects");
  }
  
  lm.writeLog("Successfully shut down world manager.");
  Manager::shutDown();
}

//inserts object into the world
int WorldManager::insertObject(Object *p_o){
  LogManager::getInstance().writeLog("wm::insertObject added to world #%d", p_o->getID());
  updates.insert(p_o);
  return 0;
}

//removes object from the world
int WorldManager::removeObject(Object *p_o){
  updates.remove(p_o);
  return 0;
}

//returns all the objects in the world
ObjectList WorldManager::getAllObjects(void) const{
  return updates;
}

//updates the world, deletes objects needing to be deleted
void WorldManager::update(){
  ObjectListIterator oli(&deletions);
  LogManager &lm = LogManager::getInstance();
  
  for(oli.first(); !oli.isDone(); oli.next()){
    updates.remove(oli.currentObject());
    deletions.remove(oli.currentObject());
    delete oli.currentObject();
  }
 
  //lm.writeLog("Movement: %d objects", updates.getCount());  
  ObjectListIterator oli2(&updates);
  for(oli2.first(); !oli2.isDone(); oli2.next()){
    //lm.writeLog("Movement for ID#%d", oli2.currentObject()->getID());
    int x = oli2.currentObject()->getXVelocityStep();
    int y = oli2.currentObject()->getYVelocityStep();

    if(x!=0 || y!=0){
      lm.writeLog("Movement for ID#%d :(%d,%d)", oli2.currentObject()->getID(), x, y);
      Position old_pos = oli2.currentObject()->getPosition();
      Position new_pos(old_pos.getX() +x, old_pos.getY() +y);
      moveObject(oli2.currentObject(), new_pos);
    }
  }

  deletions.clear();
}

//Marks an object for delete
int WorldManager::markForDelete(Object *p_o){

  ObjectListIterator oli(&deletions);
  while(!oli.isDone()){
    if(oli.currentObject() == p_o){
      return 0;
    }
    oli.next();
  }

  deletions.insert(p_o);
}

void WorldManager::draw(){
  LogManager &lm = LogManager::getInstance();
  lm.writeLog("Drawing object");
  ObjectListIterator oli(&updates);
  
  for(oli.first(); !oli.isDone(); oli.next()){
    lm.writeLog("drawing");
    oli.currentObject()->draw();
  }
}

ObjectList WorldManager::isCollision(Object *p_o, Position where) const{
  ObjectList collision_list;

  ObjectListIterator oli(&updates);
  for(oli.first(); !oli.isDone(); oli.next()){
    Object *p_t = oli.currentObject();

    if(p_t != p_o){
      if(Utility::positionsIntersect(p_t->getPosition(), where) && p_t->isSolid()){
	collision_list.insert(p_t);
      }
    }
  }
  return collision_list;
}


int WorldManager::moveObject(Object *p_o, Position where){
  if(p_o->isSolid()){
    ObjectList list = isCollision(p_o, where);
    
    if(!list.isEmpty()){
      bool canMove = true;
      
      ObjectListIterator oli(&list);
     
      for(oli.first(); !oli.isDone(); oli.next()){
        Object *p_t = oli.currentObject();
        EventCollision c(p_o, p_t, where);
        
	p_o->eventHandler(&c);
	p_t->eventHandler(&c);

	if(p_o->getSolidness() == HARD && p_t->getSolidness() == HARD){
	  canMove = false;
	}
      }

      if(!canMove){
	return -1;
      }
    } 
  }
  p_o->setPosition(where);
  if(p_o->getPosition().getX() > GraphicsManager::getInstance().getHorizontal() ||
     p_o->getPosition().getY() > GraphicsManager::getInstance().getHorizontal() ||
     p_o->getPosition().getX() < 0 ||
     p_o->getPosition().getY() < 0){
    EventOut e_o;

    p_o->eventHandler(&e_o);
  }
  
}
















