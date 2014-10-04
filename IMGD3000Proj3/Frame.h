#ifndef __H_FRAME__
#define __H_FRAME__

#include <string>

using std::string;

class Frame {
  private:
    int width;
    int height;
    string frame_str;

  public:
    Frame();
    Frame(int new_width, int new_height, string frame_str);
    void setWidth(int new_width);
    int getWidth() const;
    void setHeight(int newHeight);
    int getHeight() const;
    void setString(string new_frame_str);
    string getString() const;
};

#endif
