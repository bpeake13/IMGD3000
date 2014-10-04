#ifndef __H_SPRITE__
#define __H_SPRITE__

#include <string>
#include "Frame.h"

using std::string;

class Sprite{
  private:
    int width;
    int height;
    int max_frame_count;
    int frame_count;
    int color;
    Frame *frame;
    string label;
    Sprite();

  public:
    ~Sprite();
    Sprite(int max_frames);
    void setWidth(int new_width);
    int getWidth() const;
    void setHeight(int new_height);
    int getHeight() const;
    void setColor(int new_color);
    int getColor() const;
    Frame getFrame(int frame_num);
    int getFrameCount() const;
    int addFrame(Frame new_frame);
    void setLabel(string new_label);
    string getLabel() const;
};

#endif
