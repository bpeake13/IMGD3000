#include "Object.h"

class TestObject : public Object {
  public:
    TestObject();
    int eventHandler(Event *p_e);
    void draw();
};
