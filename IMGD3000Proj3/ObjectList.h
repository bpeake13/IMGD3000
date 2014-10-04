#ifndef __H_OBJECT_LIST__
#define __H_OBJECT_LIST__

#define DF_MAX_OBJECTS 5000

#include "Object.h"
#include "ObjectListIterator.h"

class ObjectList{
  private:
    int count;
    Object *list[DF_MAX_OBJECTS];

  public:
    friend class ObjectListIterator;
    ObjectList();
    int insert(Object *p_o);
    int remove(Object *p_o);
    void clear();
    int getCount() const;
    bool isEmpty() const;
    bool isFull() const;
    ObjectList operator+(ObjectList list);
};
#endif
