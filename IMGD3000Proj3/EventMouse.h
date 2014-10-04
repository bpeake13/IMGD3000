#include "Event.h"

#define DF_MOUSE_EVENT "__mouse__"

enum MouseActionList{
  LEFT_BUTTON_CLICK,
  LEFT_BUTTON_DOUBLECLICK,
  RIGHT_BUTTON_CLICK,
  RIGHT_BUTTON_DOUBLECLICK,
  UNDEFINED
};

class EventMouse : public Event {
  private:
    enum MouseActionList mouse_action;
    int mouse_x;
    int mouse_y;
  
  public:
    EventMouse();
    EventMouse(enum MouseActionList new_mosue_action);
    EventMouse(int x, int y);
    void setMouseAction(enum MouseActionList new_mouse_action);
    enum MouseActionList getMouseAction() const;
    void setMouseX(int new_x);
    void setMouseY(int new_y);
    int getMouseX() const;
    int getMouseY() const; 
};
