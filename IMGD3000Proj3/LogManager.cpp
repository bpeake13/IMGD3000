//Eric Faust - esfaust
//IMGD3000 Project 2
#include "LogManager.h"

#include <stdio.h>
#include <stdarg.h>
#include "Utility.h"

#define DEFAULT_VERBOSITY 1

//sets default verbosity
LogManager::LogManager(){
  setVerbosity(DEFAULT_VERBOSITY);
}
//Returns the singleton instance of logmanager
LogManager &LogManager::getInstance() {
  static LogManager lm;
  return lm;
}

//Writes log with verbosity at highest (always write)
void LogManager::writeLog(const char *fmt, ...){
  fprintf(p_f, "\nM(%s):", Utility::getTimeString());
  va_list args;
  va_start(args, fmt);
  vfprintf(p_f, fmt, args);
  va_end(args);
  fflush(p_f);
}

//Displays message only if above or == the verbosity level.
void LogManager::writeLog(int msg_verbosity, const char *fmt, ...) { 
  if(verbosity > msg_verbosity)
    return;
  fprintf(p_f, "\nM(%s):", Utility::getTimeString());
  va_list args;
  va_start(args, fmt);
  vfprintf(p_f, fmt, args);
  va_end(args);
  fflush(p_f);
}

//Opens file system
int LogManager::startUp() {
  if((p_f=fopen(DF_LOGFILE_NAME, "w")) == NULL){
    printf("Cannot open log file.\n");
    return -1;
  }
  
  Manager::startUp();
  writeLog("LogManager::startUp - Successful startup.");
  return 1;
}

//Closes file system
void LogManager::shutDown() {
  fclose(p_f);
  //If the next line shows up in the log, the file was not closed
  LogManager::getInstance().writeLog("Failure shutting down LogManager.");
}

//Sets whether to flush after 
void LogManager::setFlush(bool flush){
  do_flush = flush;
}

//Sets verbosity
void LogManager::setVerbosity(int v){
  this->verbosity = v;
}
