#include "EventKeyboard.h"

EventKeyboard::EventKeyboard(){
  setType(DF_KEYBOARD_EVENT);
}
//set the key
EventKeyboard::EventKeyboard(int new_key){
  setType(DF_KEYBOARD_EVENT); 
  key_val = new_key;
}

//Sets the keyboard event
void EventKeyboard::setKey(int new_key){
  key_val = new_key;
}

//getter
int EventKeyboard::getKey() const{
  return key_val;
}


