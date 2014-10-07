/*
 * Math.h
 *
 *  Created on: Oct 7, 2014
 *      Author: Benny
 */

#ifndef MATH_H_
#define MATH_H_

namespace Math
{

/**
 * Gets a random int inside the range
 * @param min The min value of the random range
 * @param max The max value of the random range
 * @return A random range between min and max. The value will be min <= randRange < max
 */
int randomRange(int min, int max);
/**
 * Generates a random float between 0 and 1
 * @return The random float between 0 and 1
 */
float randomFloat();

/**
 * Generates a random float between min and max
 * @param min The min value of the float
 * @param max The max value of the float
 * @return The random float between min and max
 */
float randomFloat(float min, float max);

/**
 * Clamps an int betwee two values
 * @param v The value
 * @param min The min value
 * @param max The max value
 * @return a number such that min <= v <= max
 */
int clamp(int v, int min, int max);

/**
 * Clamps a float betwee two values
 * @param v The value
 * @param min The min value
 * @param max The max value
 * @return a number such that min <= v <= max
 */
float fclampf(float v, float min, float max);

} /* namespace Math */

#endif /* MATH_H_ */
