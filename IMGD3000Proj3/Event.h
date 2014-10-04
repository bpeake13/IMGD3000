#ifndef __H_EVENT__
#define __H_EVENT__

#include <string>

#define DF_UNDEFINED_EVENT "__undefined__"

using std::string;

class Event {
  private:
    string event_type;

  public:
    Event();
    virtual ~Event();
    void setType(string new_type);
    string getType() const;
};
#endif
