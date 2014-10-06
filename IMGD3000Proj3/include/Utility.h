#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <sstream>
#include <string>
#include "IVector.h"

typedef std::string string;//rename the std::string to string for easier use

/**
 * Gets a formatted time string
 * @return A pointer to the time string
 * @remarks The result of this function should be freed after use to prevent memory leaks
 */
char* getTimeString();

long int nanoToMilli(long int nano);

/**
 * Checks to see if two points overlap
 * @param p1 The first point
 * @param p2 The second point
 * @return True if the two points intersect, otherwise false
 */
bool positionIntersect(IVector& p1, IVector& p2);

#endif
