#include "LogManager.h"
#include "Utility.h"
#include "Clock.h"
#include "GameManager.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "TestObject.h"
#include "EventStep.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <sys/time.h>
#include "Frame.h"
#include "Sprite.h"
#include "ResourceManager.h"

//This test just goes through a bunch of instantiations of frames.
//It shows the minor error checking added to throw messages if height/width of <1
int FrameTesting(){
  GameManager::getInstance().startUp();
  LogManager &lm = LogManager::getInstance();
  
  Frame f;
  
  f.setHeight(5);
  f.setWidth(6);
  string str = "cool!";
  f.setString(str);
  lm.writeLog("FT: frame height=%d width=%d str='%s'", f.getHeight(), f.getWidth(), f.getString().c_str());

  //The height and width will not change, because -1 is invalid, and 0 is invalid.
  f.setHeight(-1);
  f.setWidth(0);
  lm.writeLog("FT: frame height=%d width=%d str='%s'", f.getHeight(), f.getWidth(), f.getString().c_str());

  
  str = "12345";
  lm.writeLog("FT: frame height=%d width=%d str='%s'", f.getHeight(), f.getWidth(), f.getString().c_str());
  str = "1FOO2BAR3";
  lm.writeLog("FT: frame height=%d width=%d str='%s'", f.getHeight(), f.getWidth(), f.getString().c_str());

  
  lm.writeLog("\nEach following entry will be a new instantiation");

  Frame f2(5,10,"frame2");  
  lm.writeLog("FT: frame height=%d width=%d str='%s'", f2.getHeight(), f2.getWidth(), f2.getString().c_str());
  
  Frame f3(-1,10,"\tframe3.\n.\n.");
  lm.writeLog("FT: frame height=%d width=%d str='%s'", f3.getHeight(), f3.getWidth(), f3.getString().c_str());

  Frame f4(-5, -5, "");
  lm.writeLog("FT: frame height=%d width=%d str='%s'", f4.getHeight(), f4.getWidth(), f4.getString().c_str());

}

//Tests the creation of sprites, and editing all of its member variables
int SpriteTesting(){
  GameManager::getInstance().startUp();
  LogManager &lm = LogManager::getInstance();
  
  Frame f1(2,2,"f1");
  Frame f2(3,3,"f2");
  Frame f3(2,2,"f3");
  Frame f4(2,2,"f4");

  Sprite sp(3);
  if(sp.addFrame(f1) == -1) lm.writeLog("f1 addition failed");
  if(sp.addFrame(f2) == -1) lm.writeLog("f2 addition failed");
  if(sp.addFrame(f3) == -1) lm.writeLog("f3 addition failed");
  if(sp.addFrame(f4) == -1) lm.writeLog("f4 addition failed"); //Expecting this to fail


  Frame fr = sp.getFrame(0);
  lm.writeLog("Frame[0] in sprite: h=%d w=%d str=%s", fr.getHeight(), fr.getWidth(), sp.getFrame(0).getString().c_str());
  lm.writeLog("After sprite");
  
  sp.setLabel("sp label");
  sp.setWidth(10);
  sp.setHeight(10);
  int color = sp.getColor();
  lm.writeLog("Sprite label=%s h=%d w=%d color=%s", sp.getLabel().c_str(), sp.getHeight(), sp.getWidth(), ((color==DF_COLOR_DEFAULT ? "default" : "error")) );


  GameManager::getInstance().shutDown();
}

int ResourceManagerTesting(){
  GameManager::getInstance().startUp();
  LogManager &lm = LogManager::getInstance();
  ResourceManager &rm = ResourceManager::getInstance();
  rm.startUp();

  if(rm.isStarted()){
    lm.writeLog("ResourceManager is started: true");
  }else{
    lm.writeLog("ResourceManager is started: false");
    return -1;
  }
  
  int r1 = rm.loadSprite("sprites/saucer-spr.txt", "s1");
  int r1b = rm.loadSprite("sprites/saucer-spr.txt", "s1a"); //making sure that multiple can be created with same sprite
  int r2 = rm.loadSprite("sprites/bad-height.txt", "s2");
  int r3 = rm.loadSprite("sprites/bad-width.txt", "s3");
  int r4 = rm.loadSprite("sprites/bad-frames.txt","s4");

  //Each of these will print to log, showing that the code knows there were problems
  if(r1 ==-1) lm.writeLog("r1 incorrectly thought to be an error"); //wont print out
  if(r2 ==-1) lm.writeLog("r2 error found");
  if(r3 ==-1) lm.writeLog("r3 error found");
  if(r4 ==-1) lm.writeLog("r4 error found"); 
  
  int r1u = rm.unloadSprite("s1");
  if(r1u == -1) lm.writeLog("Unloading of s1 failed.");


  ResourceManager::getInstance().shutDown();
  GameManager::getInstance().shutDown(); 
}


//Uncomment for each section testing
int main(){
  //FrameTesting();
  //SpriteTesting();
  ResourceManagerTesting();



  if(GameManager::getInstance().isStarted()){
    GameManager::getInstance().shutDown();
  }
  return 1;
}

