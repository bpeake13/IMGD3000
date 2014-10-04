#include <time.h>

class Clock {
  private:
    struct timespec prev_ts;
  public:
    Clock();
    long int delta(void);
    long int split(void) const;
};
