//Eric Faust - esfaust
//IMGD3000 Project 2
#include "GameManager.h"
#include "LogManager.h"
#include "Clock.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "EventStep.h"

//Constructor initializes the frame time (located in header) of 33msed
GameManager::GameManager(){
  game_over = false;
  frame_time = DF_DEFAULT_FRAME_TIME;
}

//Returns the singleton instance
GameManager &GameManager::getInstance(){
  static GameManager gm;
  return gm;
}

//Starts gamemanager
int GameManager::startUp(){
  LogManager &lm = LogManager::getInstance();
  WorldManager &wm = WorldManager::getInstance();
  GraphicsManager &ghm = GraphicsManager::getInstance();
  InputManager &im = InputManager::getInstance();

  if(lm.startUp() ==1 &&
     wm.startUp() ==1 &&
    ghm.startUp() ==1 &&
     im.startUp() ==1){
   
    lm.writeLog("All managers started successfully.");
    Manager::startUp();
    return 1;
  }

  lm.writeLog("Managers did not start successfully.");
  return -1;
}

//Shuts down the gamemanager
void GameManager::shutDown(){
  GraphicsManager::getInstance().shutDown();
  InputManager::getInstance().shutDown();
  WorldManager::getInstance().shutDown();
  LogManager::getInstance().shutDown();
  
  Manager::shutDown();
}

//Runs the game.
//100 frames, resulting in roughly 3.3 seconds of 'game'
//Remember delta/split return usecs not msecs, for accuracy
void GameManager::run(int frame_time){
  Clock clock;
  LogManager &lm = LogManager::getInstance(); 
  WorldManager &wm = WorldManager::getInstance();
  GraphicsManager &ghm = GraphicsManager::getInstance();
  InputManager &im = InputManager::getInstance();

  lm.writeLog("Now running game");

  long int adjust_t =0;
  for(int i=0; i<100; i++){
    //lm.writeLog("Start of cycle");
    clock.delta();
   
    struct timespec sleep_time;
    sleep_time.tv_sec =0;
    sleep_time.tv_nsec = 15000000;
    
    im.getInput();
    wm.update();
    wm.draw();
    ghm.swapBuffers();
    EventStep s;
    onEvent(&s);
    //nanosleep(&sleep_time, NULL); //Sleeps for 15ms
    
    long int loop_t = clock.split(); //In usecs how long the loop took 
    long int sleep_t = frame_time*1000 - loop_t - adjust_t; //In usecs
    //lm.writeLog("Sleep_t = frame_t - loop_t");
    //lm.writeLog("%d = %d - %d", sleep_t, frame_time*1000, loop_t);
    if(sleep_t <0){
      sleep_t = 32500;
    }
    //usleep(sleep_t);
    long int totalTime = clock.delta();
    if(totalTime > frame_time*1000){
      adjust_t = totalTime - frame_time*1000;
    }
    //lm.writeLog("End of cycle");
  }
  lm.writeLog("Game over");
}

//Sets game over
void GameManager::setGameOver(bool new_game_over){
  game_over = new_game_over;
}

//gets status of game over
bool GameManager::getGameOver() const{
  return game_over;
}

//getter for frametime
int GameManager::getFrameTime() const{
  return frame_time;
}
