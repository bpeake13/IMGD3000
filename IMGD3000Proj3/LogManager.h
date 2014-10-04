#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include <stdio.h>
#include "Manager.h"

#define DF_LOGFILE_NAME "dragonfly.log"

class LogManager : public Manager {
  private:
    LogManager();
    LogManager(LogManager const&){return;};
    void operator=(LogManager const&){return;};
    bool do_flush;
    FILE *p_f;
    int verbosity;

  public:
    static LogManager &getInstance();
    void writeLog(int msg_verbosity, const char *fmt, ...);
    void writeLog(const char *fmt, ...);
    int startUp();
    void shutDown();
    void setFlush(bool flush=true);
    void setVerbosity(int v);
};

#endif
