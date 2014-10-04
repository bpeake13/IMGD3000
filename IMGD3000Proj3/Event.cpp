//Eric Faust - esfaust
//IMGD3000 Project 2
#include "Event.h"

//This constructor sets the type to undefined
Event::Event(){
  event_type = DF_UNDEFINED_EVENT;
}

//Descrtuctor
Event::~Event(){
}

//Type setter
void Event::setType(string new_type){
  event_type = new_type;
}

//Type getter
string Event::getType() const{
  return event_type;
}
