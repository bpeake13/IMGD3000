#include "Utility.h"

#include <time.h>


char* getTimeString()
{
	time_t raw;
	tm* timeinfo;

	time(&raw);
	timeinfo = localtime(&raw);

	char* timeString = asctime(timeinfo);

	return timeString;
}

long int nanoToMilli(long int nano)
{
	return nano / 1000000;
}

bool positionIntersect(IVector& p1, IVector& p2)
{
	return p1 == p2;
}
