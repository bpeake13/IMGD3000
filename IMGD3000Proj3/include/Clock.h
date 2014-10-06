/*
 * Clock.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Benny
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include <time.h>

/**
 * Class used for timing
 */
class Clock {
public:
	/**
	 * Create a new clock for timing
	 */
	Clock();

	/**
	 * Gets the time elapsed sense delta was last called or sense the object was created
	 * @return A long int showing the elapsed time in nanoseconds
	 */
	long int delta();

	/**
	 * Gets the time elapsed sense delta was last called or sense the object was created
	 * @return A long int showing the elapsed time in nanosesconds
	 * @remarks This method unlike delta does not reset the timer to the current time
	 */
	long int split();


private:
	timespec prevTime;//the last time that we did delta on
};

#endif /* CLOCK_H_ */
