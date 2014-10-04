#include "EventMouse.h"

//Constructor empty
EventMouse::EventMouse(){
  setType(DF_MOUSE_EVENT);
}

//Constructor with action list
EventMouse::EventMouse(enum MouseActionList nma){
  setType(DF_MOUSE_EVENT);
  mouse_action = nma;
}

//Constructor to set locatiob
EventMouse::EventMouse(int x, int y){
  setType(DF_MOUSE_EVENT);
  mouse_x = x;
  mouse_y = y;
}

//Sets with new mouse action
void EventMouse::setMouseAction(enum MouseActionList nma){
  mouse_action = nma;
}

//Returns mouse action
enum MouseActionList EventMouse::getMouseAction() const{
  return mouse_action;
}

//Setters
void EventMouse::setMouseX(int new_x){
  mouse_x = new_x;
}
void EventMouse::setMouseY(int new_y){
  mouse_y = new_y;
}

//Getters
int EventMouse::getMouseX() const{
  return mouse_x;
}
int EventMouse::getMouseY() const{
  return mouse_y;
}


