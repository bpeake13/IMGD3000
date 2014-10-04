#include "ResourceManager.h"
#include <fstream>
#include "LogManager.h"

ResourceManager::ResourceManager(){}
ResourceManager::ResourceManager(ResourceManager const&){}
void ResourceManager::operator=(ResourceManager const&){}

//Returns singleton resource manager
ResourceManager &ResourceManager::getInstance(){
  static ResourceManager rm;
  return rm;
}

int ResourceManager::startUp(){
  sprite_count = 0;
  Manager::startUp(); 
  LogManager::getInstance().writeLog("ResourceManager::startUp - Successful startup."); 
  return 1;
}

void ResourceManager::shutDown(){
  //delete p_sprite[1];
  LogManager::getInstance().writeLog("ResourceManager::shutDown - Successful shutdown.");
  Manager::shutDown();
}

int ResourceManager::loadSprite(string filename, string label){
  LogManager &lm = LogManager::getInstance();  

  lm.writeLog("Opening file:%s", filename.c_str());
  ifstream ifs(filename.c_str()); //Open the file to stream from

  if(!ifs.good()){
    lm.writeLog("Problem opening file.");
  }else{
    //lm.writeLog("\tOpened file successfully.");
  }

  int line;
  int frames = readLineInt(&ifs, &line, DF_FRAMES_TOKEN);
  int width = readLineInt(&ifs, &line, DF_WIDTH_TOKEN);
  int height = readLineInt(&ifs, &line, DF_HEIGHT_TOKEN);
  string color = readLineStr(&ifs, &line, DF_COLOR_TOKEN);

  //lm.writeLog("\tFrames=%d width=%d height=%d color='%s'", frames, width, height, color.c_str());

  Sprite *spr = new Sprite(frames);
  for(int i=0; i<frames; i++){
    Frame rframe = readFrame(&ifs, &line, width, height);
    string emptystr = "empty";
    Frame empty(-1,-1,emptystr);
    if(rframe.getWidth() == empty.getWidth() &&
	rframe.getHeight() == empty.getHeight() &&
	rframe.getString() == empty.getString()){
      //The returned frame was empty, must have been an error.
      LogManager::getInstance().writeLog("Frame empty, and error occurred on line %d", line);
      return -1;
    }else{
      spr->addFrame(rframe);
    }
  }

  ifs.close();
  spr->setLabel(label);
  
  p_sprite[sprite_count] = spr;
  sprite_count++;
  return 0;
}

//Returns -1 of failure, 0 if ok
int ResourceManager::unloadSprite(string label){
  LogManager::getInstance().writeLog("\tUnload called sprite_count:%d", sprite_count);
  for(int i=0; i<sprite_count;i++){
    LogManager::getInstance().writeLog("\tLabel expected:%s   Found:%s", label.c_str(), p_sprite[i]->getLabel().c_str());
    if(label == p_sprite[i]->getLabel()){
      //delete p_sprite[i];
      LogManager::getInstance().writeLog("Deleted sprite %s at place %d", label.c_str(), i);
      for(int j=i; i<sprite_count-1; j++){
        p_sprite[j] = p_sprite[j+1];
      }
      sprite_count--;
      LogManager::getInstance().writeLog("Successfully unloaded sprite\n");
      return 0;
    }
  }
  LogManager::getInstance().writeLog("Failed to unload sprite '%s'\n", label.c_str());
  return -1;
}

Sprite *ResourceManager::getSprite(string label) const{
  
}

int ResourceManager::readLineInt(ifstream *p_file, int *p_line_num, const char *tag){
  LogManager &lm = LogManager::getInstance();
  //Check if the stream is OK
  if(!p_file->good()){
    lm.writeLog("ReadLineInt ifstream problem.");
    return -1;
  }else{
    //lm.writeLog("ReadLineInt ifstream no problems!");
  }
  
  //Get line
  string line;
  //std::ifstream file("test.txt");
  std::getline(*p_file, line);
 
  //Check if equal
  if(line.compare(0, strlen(tag), tag) !=0){
    lm.writeLog("Incorrect tag passed in readLineInt - expected:'%s'  but is:'%s'", tag, line.substr(0, strlen(tag)).c_str() );
    return -1;
  }

  p_line_num++;
  
  int number = atoi(line.substr(strlen(tag)+1).c_str());
  return number;
}

//Returns the line as a string
string ResourceManager::readLineStr(ifstream *p_file, int *p_line_number, const char *tag){
  //Check if the stream is OK
  if(!p_file->is_open() ||
     !p_file->good()){
    return (string) "-ERROR-";
  }

  //Get line
  string line;
  //std::ifstream file("test.txt");
  std::getline(*p_file, line);
  discardCR(line);

  //Check if equal
  if(line.compare(0, strlen(tag), tag) !=0){
    return (string) "-ERROR-";
  }

  return line.substr(strlen(tag)+1);
}

Frame ResourceManager::readFrame(ifstream *p_file, int *p_line_number, int width, int height){
  LogManager &lm = LogManager::getInstance();
  string line, frame_str;

  for(int i=1; i<=height; i++){
    std::getline(*p_file, line);
    discardCR(line);
  
    if(line.length() != width){
      string emptystr = "empty";
      Frame empty(-1,-1,emptystr);
      lm.writeLog("ReadFrame found incorrect width");
      return empty;
    }
    frame_str += line;
  }
  
  //Get line and discard the carriage return;
  std::getline(*p_file, line);
  discardCR(line);
  
  if(line != "end"){
    string emptystr = "empty";
    Frame empty(-1,-1,emptystr);
    lm.writeLog("ReadFrame found end");
    return empty;
  }

  Frame fr(width, height, frame_str);
  return fr;
}

void ResourceManager::discardCR(string &str){
  if(str.size() > 0 && str[str.size() -1] == '\r'){
    str.erase(str.size() -1);
  }
}
