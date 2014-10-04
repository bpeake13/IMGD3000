#include "EventCollision.h"

EventCollision::EventCollision(){}
//Set the objects for each side and position
EventCollision::EventCollision(Object *p_o1, Object *p_o2, Position p){
  p_obj1 = p_o1;
  p_obj2 = p_o2;
  pos = p;
}

//Setters/getters for object1
void EventCollision::setObject1(Object *p_o1){
  p_obj1 = p_o1;
}
Object *EventCollision::getObject1() const{
  return p_obj1;
}

//Setters/getters for object2
void EventCollision::setObject2(Object *p_o2){
  p_obj2 = p_o2;
}
Object *EventCollision::getObject2() const{
  return p_obj2;
}

//Setters/getters for position
void EventCollision::setPosition(Position n_pos){
  pos = n_pos;
}
Position EventCollision::getPosition() const{
  return pos;
}
