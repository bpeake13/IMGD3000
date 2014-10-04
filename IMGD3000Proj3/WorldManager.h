#include "Manager.h"
#include "ObjectList.h"

#define DF_MAX_ALTITUDE 4

class WorldManager : public Manager {
  private:
    WorldManager();
    WorldManager(WorldManager const&);
    void operator=(WorldManager const&);
    ObjectList updates;
    ObjectList deletions;
    
  public:
    static WorldManager &getInstance();
    int startUp();
    void shutDown();
    int insertObject(Object *p_o);
    int removeObject(Object *p_o);
    ObjectList getAllObjects(void) const;
    void update();
    int markForDelete(Object *p_o);
    void draw();
    ObjectList isCollision(Object *p_o, Position wh) const;
    int moveObject(Object *p_o, Position wh);
};
