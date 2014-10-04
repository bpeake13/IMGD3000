//Eric Faust - esfaust
//IMGD3000 Project 2
#include "Clock.h"
#include <time.h>

#include "LogManager.h"

//Constructor sets the previous time to 0
Clock::Clock(){
  prev_ts.tv_sec = 0;
  prev_ts.tv_nsec = 0;
}

//Returns the time since delta was last called, in useconds
long int Clock::delta(void){
  long int before_nsec = prev_ts.tv_sec*1000000000 + prev_ts.tv_nsec;

  clock_gettime(CLOCK_REALTIME, &prev_ts);
  
  long int after_nsec = prev_ts.tv_sec*1000000000 + prev_ts.tv_nsec;

  long int diff = after_nsec - before_nsec;
  return diff/1000;
}

//Returns the time since delta was last called, in useconds
long int Clock::split(void) const{
    struct timespec temp_ts = prev_ts;
    struct timespec temp_ts2;
    clock_gettime(CLOCK_REALTIME, &temp_ts2);

    long int before = temp_ts.tv_sec*1000000000 + temp_ts.tv_nsec;
    long int after = temp_ts2.tv_sec*1000000000 + temp_ts2.tv_nsec;
    long int diff = after-before;
    return diff/1000;
}
