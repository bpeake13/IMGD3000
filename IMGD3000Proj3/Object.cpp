/*
-Eric Faust
-September 2014
*/
#include "Object.h"
#include "WorldManager.h"
#include "LogManager.h"
#include <math.h>


//Constructor
Object::Object(){
  LogManager::getInstance().writeLog("Adding object to world.");
  id = generateID();
  WorldManager::getInstance().insertObject(this);
}

//Destructor
Object::~Object(){
}

int Object::generateID(){
  static int currID=0;
  return currID++;
}

//Setter for ID
void Object::setID(int new_id){
  id = new_id;
}

//Getter for ID
int Object::getID() const{
  return id;
}

//Setter for type
void Object::setType(string new_type){
  type = new_type;
}

//Getter for type
string Object::getType() const{
  return type;
}

//Setter for position
void Object::setPosition(Position new_pos){
  pos = new_pos;
}

//Getter for position
Position Object::getPosition() const{
  return pos;
}

//Virtual event Handler
int Object::eventHandler(Event *p_e){
}

void Object::draw(){}

//Sets the altitude, returns -1 if invalid altitude
int Object::setAltitude(int new_altitude){
  if(new_altitude > DF_MAX_ALTITUDE || new_altitude < 0){
    return -1;
  }
  altitude = new_altitude;
  return 0;
}

int Object::getAltitude() const{
  return altitude;
}

void Object::setXVelocity(float newx){
  x_velocity = newx;
}

void Object::setYVelocity(float newy){
  y_velocity = newy;
}

float Object::getXVelocity() const{
  return x_velocity;
}

float Object::getYVelocity() const{
  return y_velocity;
}

int Object::getXVelocityStep(){
  if(x_velocity ==0){
    return 0;
  }

  x_velocity_countdown = x_velocity_countdown - fabs(x_velocity);
  if(x_velocity_countdown > 0){
    return 0;
  }

  int spaces = floor(1-x_velocity_countdown);
  x_velocity_countdown = 1 + fmod(x_velocity_countdown, 1);

  if(x_velocity >0){
    return spaces;
  }else{
    return -1 * spaces;
  }

}

int Object::getYVelocityStep(){
  if(y_velocity ==0){
    return 0;
  }

  y_velocity_countdown = y_velocity_countdown - fabs(y_velocity);
  if(y_velocity_countdown > 0){
    return 0;
  }

  int spaces = floor(1-y_velocity_countdown);
  y_velocity_countdown = 1 + fmod(y_velocity_countdown, 1);

  if(y_velocity >0){
    return spaces;
  }else{
    return -1 * spaces;
  }
}

bool Object::isSolid() const{
  if(solidness != SPECTRAL){
    return true;
  }
  return false;
}

int Object::setSolidness(Solidness new_s){
  if(new_s != SPECTRAL && new_s != SOFT && new_s != HARD){
    return -1;
  }
  solidness = new_s;
  return 0;
}

Solidness Object::getSolidness() const{
  return solidness;
}

