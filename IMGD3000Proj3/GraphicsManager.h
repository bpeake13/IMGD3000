#ifdef CYGWIN
#include <ncurses/curses.h>
#else
#include <curses.h>
#endif

#include "Manager.h"
#include "Position.h"

#define DF_COLOR_DEFAULT COLOR_WHITE

enum Justification {
  LEFT_JUSTIFIED,
  CENTER_JUSTIFIED,
  RIGHT_JUSTIFIED,
};


class GraphicsManager : public Manager {
  private:
    GraphicsManager();
    GraphicsManager(GraphicsManager const&);
    void operator=(GraphicsManager const&);
    WINDOW *buffer1;
    WINDOW *buffer2;
    WINDOW *p_buffer;
    int maxy;
    int maxx;

  public:
    static GraphicsManager &getInstance();
    int startUp();
    void shutDown();
    int drawCh(Position world_pos, char ch, int color=DF_COLOR_DEFAULT) const;
    int drawString(Position world_post, string str, Justification just, int color=DF_COLOR_DEFAULT) const;
    int getHorizontal() const;
    int getVertical() const;
    int swapBuffers();
    WINDOW *getPreviousBuffer() const;
    WINDOW *getCurrentBuffer() const;
};
