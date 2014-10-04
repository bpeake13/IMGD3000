//Eric Faust - esfaust
//IMGD3000 Project 2
#include "ObjectListIterator.h"

//Default private constructor
ObjectListIterator::ObjectListIterator(){}

//Constructor that links to an object list
ObjectListIterator::ObjectListIterator(const ObjectList *p_l){
  p_list = p_l;
  first();
}

//Sets the index to 0 for looping
void ObjectListIterator::first() {
  index = 0;
}

//Incrememnts loop index
void ObjectListIterator::next() {
  if(index < (p_list->count)){
    index++;
  }
}

//Returns true if at the final index
bool ObjectListIterator::isDone() const{
  return (index == (p_list->count));
}

//Returns a pointer to the current object
Object* ObjectListIterator::currentObject() const{
  return p_list->list[index];
}
