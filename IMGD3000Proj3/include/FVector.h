/*
 * FVector.h
 *
 *  Created on: Sep 8, 2014
 *      Author: Benny
 */

#ifndef FVECTOR_H_
#define FVECTOR_H_

#include "IVector.h"

class IVector;

/**
 * A 2d floating pofloat vector
 */
class FVector
{
private:
	float x, y;//x and y value of the vector
public:
	/**
	 * Creates a new FVector
	 * @param x The x coordinate of the FVector
	 * @param y The y coordinate of the FVector
	 */
	FVector(float x, float y);

	/**
	 * Creates a new FVector from an IVector
	 * @param ivec A reference to the IVector to create this from
	 */
	FVector(IVector& ivec);

	/**
	 * Change the value of the vector
	 * @param x the new x value
	 * @param y the new y value
	 */
	void set(float x, float y);

	/**
	 * Change the x value of the vector
	 * @param x the new x value
	 */
	void setX(float x);

	/**
	 * Change the y value of the vector
	 * @param y the new y value
	 */
	void setY(float y);

	/**
	 * Gets the x value of this vector
	 * @return The x value as an float
	 */
	float getX() const;

	/**
	 * Gets the y value of this vector
	 * @return The y value as an float
	 */
	float getY() const;

	/**
	 * Addition operator for vectors (a+b)
	 * @param b the b vector
	 * @return The new vector
	 */
	FVector operator+(const FVector& b) const;

	/**
	 * Subtraction operator for vectors (a-b)
	 * @param b The b vector
	 * @return The new vector
	 */
	FVector operator-(const FVector& b) const;

	/**
	 * Negation operator for vector (-a)
	 * @return The negated version of the vector
	 */
	FVector operator-() const;

	/**
	 * Comparison operator for a==b
	 * @param b The other vector
	 * @return true if the two vectors are equal
	 */
	bool operator==(const FVector& b) const;

	/**
	 * Not Comparison operator for a!=b
	 * @param b The other vector
	 * @return true if the two vectors are not equal
	 */
	bool operator!=(const FVector& b) const;
};

#endif /* FVector_H_ */
