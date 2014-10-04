#include "GraphicsManager.h"
#include "LogManager.h"

//ABBREVIATED 'GHM'

GraphicsManager::GraphicsManager(){}
GraphicsManager::GraphicsManager(GraphicsManager const&){}
void GraphicsManager::operator=(GraphicsManager const&){}
//Singleton of graphics manager
GraphicsManager &GraphicsManager::getInstance(){
  static GraphicsManager ghm;
  return ghm;
}

//Starts up the graphics manager, with error checking for all of the commands
int GraphicsManager::startUp(){
  LogManager &lm = LogManager::getInstance();
  
  //Start curses mode
  //If error, initscr does not return.
  if(!initscr()){
    lm.writeLog("GraphicsManager::startUp - Failure in initscr()");
    return -1;
  }

  //Initialize buffers
  buffer1 = newwin(0,0,0,0);
  buffer2 = newwin(0,0,0,0);
  p_buffer = buffer1;
 
  getmaxyx(stdscr, maxy, maxx);

  //Turn off cursor
  
  if(curs_set(0) == ERR){
    lm.writeLog("GraphicsManager::startUp - Failure in curs_set()");
    return -1;
  }
    
  //Clear the buffers
  if(werase(buffer1) != OK){
    lm.writeLog("GraphicsManager::startUp - Failure in werase(buffer1)");
    return -1;
  }
  if(werase(buffer2) != OK){
    lm.writeLog("GraphicsManager::startUp - Failure in werase(buffer2)");
    return -1;
  }
 

  if(clearok(buffer1, TRUE) != OK){
    lm.writeLog("GraphicsManager::startUp - Failure in clearok(buffer1)");
    return -1;
  }
  if(clearok(buffer2, TRUE) != OK){
    lm.writeLog("GraphicsManager::startUp - Failure in clearok(buffer2)");
    return -1;
  }
  
  if(leaveok(buffer1, TRUE) != OK){
     lm.writeLog("GraphicsManager::startUp - Failure in leaveok(buffer1)");
     return -1;
  }
  if(leaveok(buffer2, TRUE) != OK){
     lm.writeLog("GraphicsManager::startUp - Failure in leaveok(buffer2)");
     return -1;
  }


  if(has_colors()){
    start_color();
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
  }

  if(wattron(buffer1, A_BOLD) != OK){
    lm.writeLog("GraphicsManager::startUp - Failure in wattron(buffer1)");
    return -1;
  }
  if(wattron(buffer2, A_BOLD) != OK){
    lm.writeLog("GraphicsManager::startUp - Failure in wattron(buffer2)");
    return -1;
  }

  Manager::startUp();
  lm.writeLog("GraphicsManager::startUp - Successful Startup");
  return 1;
}

//Shuts down the manager, checks for error in endwin
void GraphicsManager::shutDown(){
  if(endwin() != ERR){
    LogManager::getInstance().writeLog("Successfully shut down graphics manager.");
  }
  Manager::shutDown();
}

//Draws single character
int GraphicsManager::drawCh(Position world_pos, char ch, int color) const{
  LogManager &lm = LogManager::getInstance();
  //werase(p_buffer);
  
  wattron(p_buffer, COLOR_PAIR(color));
  
  //lm.writeLog("\tGM::drawCh - '%c' at (%d, %d)", ch, world_pos.getX(), world_pos.getY());
  mvwaddch(getCurrentBuffer(),world_pos.getY(), world_pos.getX(), ch);

  wattroff(p_buffer, COLOR_PAIR(color));
}

//Draws a sting with the given position, string, and justification.
//Color is optional, and has a default of white.
int GraphicsManager::drawString(Position world_pos, string str, Justification just, int color) const{
  Position starting_pos = world_pos;
  switch(just){
    case CENTER_JUSTIFIED:
      starting_pos.setX(world_pos.getX() - str.size()/2);
      break;
    case RIGHT_JUSTIFIED:
      starting_pos.setX(world_pos.getX() - str.size());
      break;
    case LEFT_JUSTIFIED:
    default:
      break;
  }

  for(int i=0; i<str.size();i++){
    Position temp_pos(starting_pos.getX() +i, starting_pos.getY());
    //LogManager::getInstance().writeLog("\tdrawString:: %c at (%d,%d)", str[i], temp_pos.getX(), temp_pos.getY());
    drawCh(temp_pos, str[i], color);
  }

  return 0;
}

//Returns boundary in X axis
int GraphicsManager::getHorizontal() const{
  return maxx;  
}

//Returns boundary in Y axis
int GraphicsManager::getVertical() const{
  return maxy;
}

//p_buffer now points to the opposite Window buffer.
int GraphicsManager::swapBuffers() {
  wrefresh(p_buffer);

  if(p_buffer == buffer2){
    p_buffer = buffer1;
  }else{
    p_buffer = buffer2;
  }
  werase(p_buffer);
}

//Returns the buffer that p_buffer is not pointing towards
WINDOW *GraphicsManager::getPreviousBuffer() const{
  if(p_buffer == buffer1){
    return buffer2;
  }else{
    return buffer1;
  }
}

//Points towards the current buffer (p_buffer)
WINDOW *GraphicsManager::getCurrentBuffer() const{
  return p_buffer;
}
