#include "Frame.h"
#include "LogManager.h"

Frame::Frame(){}

//If invalid width/height, will set to -1
Frame::Frame(int new_width, int new_height, string new_frame_str){
  LogManager &lm = LogManager::getInstance();  

  if(new_width <=0){
    width = -1;
  }else{
    width = new_width;
  }

  if(new_height <=0){
    height = -1;
  }else{
    height = new_height;
  }

  frame_str = new_frame_str;
  
//  lm.writeLog("Created Frame. h=%d w=%d str=%s", height, width, frame_str.c_str());
}

//Widht getter and setter
//if invalid width/height, returns immediately
void Frame::setWidth(int new_width){
  if(new_width<=0){
    return;
  }
  width = new_width;
}
int Frame::getWidth() const{
  return width;
}

//Height getter and setter
//if invalid width/height, returns immediately
void Frame::setHeight(int new_height){
  if(new_height<=0){
    return;
  }

  height = new_height;
}
int Frame::getHeight() const{
  return height;
}

//Frame Str getter and setter
void Frame::setString(string new_frame_str){
  frame_str = new_frame_str;
}
string Frame::getString() const{
  return frame_str;
}
