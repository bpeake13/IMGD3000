#include "Event.h"

#define DF_KEYBOARD_EVENT "__keyboard__"

class EventKeyboard : public Event{
  private:
    int key_val;
    
  public:
    EventKeyboard();
    EventKeyboard(int new_key);
    void setKey(int new_key);
    int getKey() const;

};
