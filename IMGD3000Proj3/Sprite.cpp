#include "Sprite.h"
#include "GraphicsManager.h"
#include "LogManager.h"

//Constructor
Sprite::Sprite(int max_f){
  max_frame_count = max_f;
  frame_count = 0;
  width =0;
  height=0;
  frame = new Frame[max_f];
  color = DF_COLOR_DEFAULT;
}

//Destructor also deletes the frame
Sprite::~Sprite(){
  if(frame != NULL){
    delete frame;
  }
}

//Width getter and setter
void Sprite::setWidth(int nw){
  width = nw;
}
int Sprite::getWidth() const{
  return width;
}

//Height getter and setter
void Sprite::setHeight(int nh){
  height =nh;
}
int Sprite::getHeight() const{
  return height;
}

//Color getter and setter
void Sprite::setColor(int nc){
  color = nc;
}
int Sprite::getColor() const{
  return color;
}


//Adds given frame to sprite
//Returns -1 if error, 0 if success.
int Sprite::addFrame(Frame nf){
  if(frame_count == max_frame_count){
    LogManager::getInstance().writeLog("Max frame count reached in Sprite, not adding frame.");
    return -1;
  }

  frame[frame_count] = nf;
  //LogManager::getInstance().writeLog("Frame added to sprite: h=%d w=%d str=%s", frame[frame_count].getHeight(), frame[frame_count].getWidth(), frame[frame_count].getString().c_str());
  frame_count++;

  return 0;
}

//Returns an empty frame if invalid, otherwise the desired frame
Frame Sprite::getFrame(int frame_num){
  if(frame_num <0 || frame_num >= frame_count){
    Frame empty;
    return empty;
  }
  return frame[frame_num];
}

void Sprite::setLabel(string nl){
  label = nl;
}
string Sprite::getLabel() const{
  return label;
}
