#include "InputManager.h"
#include "GraphicsManager.h"
#include "LogManager.h"

#include "EventKeyboard.h"
#include "EventMouse.h"

InputManager::InputManager(){}
InputManager::InputManager(InputManager const&){}
void InputManager::operator=(InputManager const&){}
//Singleton of Input manager
InputManager &InputManager::getInstance(){
  static InputManager im;
  return im;
}

//Starts the input manager, setting all the necessary commands up for curses game input
int InputManager::startUp(){
  if(!GraphicsManager::getInstance().isStarted()){
    LogManager::getInstance().writeLog("ERROR: InputManager incorrectly started!");
    return -1;
  }

  cbreak(); //Disable \r \n buffer end
  nodelay(stdscr, TRUE); //doesnt wait for input
  noecho();  //characters dont show up on screen when pressed

  nonl(); //disable newline
  curs_set(0); //turn off cursor
  mousemask(BUTTON1_CLICKED, NULL); //mouse events
  keypad(stdscr, TRUE); //enable
  
  Manager::startUp();
  LogManager::getInstance().writeLog("InputManager::startUp - Successfull startup");
  return 1;
}

//shuts down the manager
void InputManager::shutDown(){
  LogManager::getInstance().writeLog("Successfully shut down input manager");
  Manager::shutDown();
}

//Checks for input
void InputManager::getInput(){
  LogManager &lm = LogManager::getInstance();
  lm.writeLog("Searching for input");
  
  int key = getch();
  if(key != ERR){
    //Mouse clicked
    MEVENT m_event;
    if(key == KEY_MOUSE && getmouse(&m_event) == OK){
      lm.writeLog("Mouse input found");
      //Left button clicked
      if(m_event.bstate && BUTTON1_CLICKED){
        int x = m_event.x;
        int y = m_event.y;
        EventMouse em(x,y);
        em.setMouseAction(LEFT_BUTTON_CLICK);
        lm.writeLog("EM type:%s", em.getType().c_str());
        onEvent(&em);
      }
    }else{ //Key event
      lm.writeLog("Keyboard input found");
      EventKeyboard ek(key);
      lm.writeLog("EK type:%s", ek.getType().c_str());
      onEvent(&ek);
    }
  }else{
    lm.writeLog("No input found");
  }
}

