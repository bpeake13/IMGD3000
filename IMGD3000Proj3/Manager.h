#ifndef MANAGER
#define MANAGER

#include <string>
#include "Event.h"

class Manager {
  private:
    std::string type;
    bool is_started;

  protected:
    void setType(std::string type);

  public:
    Manager();
    virtual ~Manager();
    std::string getType() const;
    virtual int startUp();
    virtual void shutDown();
    bool isStarted() const;
    int onEvent(Event *p_event);
};

#endif
