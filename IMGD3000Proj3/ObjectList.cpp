//Eric Faust - esfaust
//IMGD3000 Project 2
#include "ObjectList.h"
#include "ObjectListIterator.h"

//Default constructor
ObjectList::ObjectList(){
  count =0;
}

//Clears so objects can be rewritten
void ObjectList::clear(){
  count =0;
}

//Inserts an object into list. -1 if full
int ObjectList::insert(Object *x){
  if(count==DF_MAX_OBJECTS){
    return -1;
  }
  list[count] = x;
  count++;
  return 0;
}

//Removes an object
int ObjectList::remove(Object *x){
  for(int i=0; i<count; i++){
    if(list[i] == x){
      for(int j=i; j<(count-1); j++){
        list[j] = list[j+1];
      }
      count--;
      return true;
    }
  }
  return false;
}

//Returns number of items
int ObjectList::getCount() const{
  return count;
}

//returns whether is empty
bool ObjectList::isEmpty() const{
  return (count==0);
}

//returns whether is full. DF_MAX_OBJECTS in header
bool ObjectList::isFull() const{
  return (count==DF_MAX_OBJECTS);
}

//Lets you combine object lists with + operator.
ObjectList ObjectList::operator+(ObjectList list){
  ObjectList big_list = *this;
  
  ObjectListIterator i(&list);

  for(i.first(); not i.isDone(); i.next()){
    Object *p_o = i.currentObject();
    big_list.insert(p_o);
  }

  return big_list;
}
