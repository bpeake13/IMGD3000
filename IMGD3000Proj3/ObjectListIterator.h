#ifndef __H_OBJECT_LIST_ITERATOR__
#define __H_OBJECT_LIST_ITERATOR__

#include "ObjectList.h"

class ObjectList;

class ObjectListIterator{
  private:
    ObjectListIterator();
    int index;
    const ObjectList *p_list;
   
  public:
    ObjectListIterator(const ObjectList *p_l);
    void first();
    void next();
    bool isDone() const;
    Object* currentObject() const;
};
#endif
