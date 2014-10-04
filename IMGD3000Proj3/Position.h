#ifndef __H_POSITION__
#define __H_POSITION__

class Position {
  private:
    int x;
    int y;

  public:
    Position(int init_x, int init_y);
    Position();
    void setX(int new_x);
    int getX();
    void setY(int new_y);
    int getY();
    void setXY(int new_x, int new_y);

};

#endif
