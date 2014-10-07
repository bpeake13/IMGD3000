/*
 * Math.cpp
 *
 *  Created on: Oct 7, 2014
 *      Author: Benny
 */

#include "MathExt.h"

#include <math.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

namespace Math
{

int randomRange(int min, int max)
{
	int range = max - min;
	int randRange = rand() % range;

	return randRange + min;
}

float randomFloat()
{
	float normalized = (float)rand() / (float)RAND_MAX;

	return normalized;
}

float randomFloat(float min, float max)
{
	float normalized = randomFloat();

	float range = max - min;
	float rangedF = range * normalized;

	return rangedF + min;
}

int clamp(int v, int min, int max)
{
	return std::max(std::min(v, max), min);
}

float fclampf(float v, float min, float max)
{
	return fmaxf(fminf(v, min), max);
}

} /* namespace Math */
