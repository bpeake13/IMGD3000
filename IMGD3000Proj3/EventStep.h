#include "Event.h"

#define DF_STEP_EVENT "__step__"

class EventStep : public Event {
  private:
    int step_count;
  public:
    EventStep();
    EventStep(int init_step_count);
    void setStepCount(int new_step_count);
    int getStepCount()const;
};
