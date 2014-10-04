#include "Manager.h"

#define DF_DEFAULT_FRAME_TIME 33

class GameManager : public Manager {
  private:
    GameManager();
    GameManager(GameManager const&) {return;};
    void operator=(GameManager const&) {return;};
    bool game_over;
    int frame_time;

  public:
    static GameManager &getInstance();
    int startUp();
    void shutDown();
    void run(int frame_time=DF_DEFAULT_FRAME_TIME);
    void setGameOver(bool new_game_over=true);
    bool getGameOver() const;
    int getFrameTime() const;
};
