//Eric Faust - esfaust
//IMGD3000 Project 2
#include "EventStep.h"

//Constructor sets the event type. DF_STEP_EVENT is located in header
EventStep::EventStep(){
  setType(DF_STEP_EVENT);
}

//Constructor sets the step count
EventStep::EventStep(int init_step_count){
  setType(DF_STEP_EVENT);
  step_count = init_step_count;
}

//Sets the step count
void EventStep::setStepCount(int new_step_count){
  step_count = new_step_count;
}

//Gets the step count
int EventStep::getStepCount()const{
  return step_count;
}
