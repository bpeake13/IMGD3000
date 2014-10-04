#ifndef __H_OBJECT__
#define __H_OBJECT__

#include <string>
using std::string;

#include "Position.h"
#include "Event.h"

enum Solidness{
  HARD, //Collisions and physical stopping
  SOFT, //Collisions
  SPECTRAL //Neither
};


class Object {
  private:
    int id;
    string type;
    Position pos;
    int altitude;
    float x_velocity;
    float y_velocity;
    float x_velocity_countdown;
    float y_velocity_countdown;
    Solidness solidness;
    int generateID();

  public:
    Object();
    virtual ~Object();
    void setID(int new_id);
    int getID() const;
    void setType(string new_type);
    string getType() const;
    void setPosition(Position pos);
    Position getPosition() const;
    virtual int eventHandler(Event *p_e);
    virtual void draw();
    int setAltitude(int new_altitude);
    int getAltitude() const;
    void setXVelocity(float x);
    void setYVelocity(float y);
    float getXVelocity() const;
    float getYVelocity() const;
    int getXVelocityStep();
    int getYVelocityStep();    
    bool isSolid() const;
    int setSolidness(Solidness new_solid);
    Solidness getSolidness() const;

};
#endif
