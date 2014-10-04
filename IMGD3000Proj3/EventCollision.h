#include "Event.h"
#include "Object.h"

#define DF_COLLISION_EVENT "__collision__"

class EventCollision : public Event{
  private:
    Position pos;
    Object *p_obj1;
    Object *p_obj2;
    
  public:
    EventCollision();
    EventCollision(Object *p_o1, Object *p_o2, Position p);
    void setObject1(Object *p_o1);
    Object *getObject1() const;
    void setObject2(Object *p_o2);
    Object *getObject2() const;
    void setPosition(Position n_pos);
    Position getPosition() const;
};
