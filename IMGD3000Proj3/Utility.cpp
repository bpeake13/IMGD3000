//Eric Faust - esfaust
//IMGD3000 Project 2
#include "Utility.h"
#include <time.h>
#include <stdio.h>

//Returns the current localtime as a string
char* Utility::getTimeString() {
  static char time_str[30];

  time_t now;
  time(&now);
  struct tm *p_time  = localtime(&now);

  sprintf(time_str, "%02d:%02d:%02d",
                                p_time->tm_hour,
                                p_time->tm_min,
                                p_time->tm_sec);
  return time_str;
}

//Returns whether the positions intersect

bool Utility::positionsIntersect(Position p1, Position p2){
  if(p1.getX() == p2.getX() && p1.getY() == p2.getY()){
    return true;
  }
  return false;
}
