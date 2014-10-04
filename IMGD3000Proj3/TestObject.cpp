#include "LogManager.h"
#include "TestObject.h"
#include "EventStep.h"
#include "EventOut.h"
#include "EventMouse.h"
#include "EventKeyboard.h"
#include "GraphicsManager.h"
#include "WorldManager.h"

 TestObject::TestObject(){
}

//This testing object handles different events differently.
int TestObject::eventHandler(Event *p_e) {
  LogManager &lm = LogManager::getInstance();
 
  if(p_e->getType() == DF_STEP_EVENT){
    lm.writeLog("\tTestObject::eventHandler - Step Event received.");
  }else if(p_e->getType() == "CustomEvent"){
    //lm.writeLog("TestObject::CustomEvent received");
  }else if(p_e->getType() == DF_KEYBOARD_EVENT){
    EventKeyboard *k_e = (EventKeyboard*) p_e;
    if(k_e->getKey() == KEY_RIGHT){
      lm.writeLog("TO noticed an RIGHT key press");
    }else{
      lm.writeLog("TO noticed a KEY press");
    }
  }else if(p_e->getType() == DF_MOUSE_EVENT){
    EventMouse *m_e = (EventMouse*) p_e;
    lm.writeLog("TO noticed a MOUSE click at (%d,%d)", m_e->getMouseX(), m_e->getMouseY());
  }else if(p_e->getType() == DF_OUT_EVENT){
    WorldManager &wm = WorldManager::getInstance();
    lm.writeLog("TO is deleting itself. MFD");
    wm.markForDelete(this);
  }
}

//Default for test object is a cyan X
void TestObject::draw(){
  LogManager &lm = LogManager::getInstance();
  lm.writeLog("\tTestObject::draw at (%d,%d)", getPosition().getX(), getPosition().getY());
  GraphicsManager &ghm = GraphicsManager::getInstance();
  
  ghm.drawString(getPosition(), "X", LEFT_JUSTIFIED, COLOR_CYAN);
}
