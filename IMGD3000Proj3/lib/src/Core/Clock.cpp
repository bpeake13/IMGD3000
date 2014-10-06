/*
 * Clock.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: Benny
 */

#include "Clock.h"

#ifdef CYGWIN

Clock::Clock()
{
	delta();
}

long int Clock::delta()
{
	timespec current;
	clock_gettime(CLOCK_REALTIME, &current);//get the current time

	long int nanoNow = (long int)current.tv_sec * 1000000000 + current.tv_nsec;
	long int nanoPrev = (long int)prevTime.tv_sec * 1000000000 + prevTime.tv_nsec;

	prevTime = current;

	return nanoNow - nanoPrev;
}

long int Clock::split()
{
	timespec current;
	clock_gettime(CLOCK_REALTIME, &current);//get the current time

	long int nanoNow = (long int)current.tv_sec * 1000000000 + current.tv_nsec;
	long int nanoPrev = (long int)prevTime.tv_sec * 1000000000 + prevTime.tv_nsec;

	return nanoNow - nanoPrev;
}

#endif

#ifdef MACOS

#endif
