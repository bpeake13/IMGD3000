//Eric Faust - esfaust
//IMGD3000 Project 2
#include "Position.h"

//Default constructor
Position::Position(){}

//Initilization constructor
Position::Position(int init_x, int init_y){
  x = init_x;
  y = init_y;
}

//Setter
void Position::setX(int new_x){
  x = new_x;
}

//Getter
int Position::getX(){
  return x;
}

//Setter
void Position::setY(int new_y){
  y = new_y;
}

//getter
int Position::getY(){
  return y;
}

//initilizes both x and y
void Position::setXY(int new_x, int new_y){
  x = new_x;
  y = new_y;
}
