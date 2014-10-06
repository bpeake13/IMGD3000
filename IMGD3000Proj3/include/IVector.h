/*
 * zVector.h
 *
 *  Created on: Sep 8, 2014
 *      Author: Benny
 */

#ifndef IVECTOR_H_
#define IVECTOR_H_

#include "FVector.h"

class FVector;

/**
 * A 2d integer vector
 */
class IVector
{
private:
	int x, y;//x and y value of the vector
public:
	/**
	 * Creates a new IVector
	 * @param x The x coordinate of the IVector
	 * @param y The y coordinate of the IVector
	 */
	IVector(int x, int y);

	/**
	 * Creates a new IVector from an FVector
	 * @param fvec A reference to the FVector to create the IVector from
	 */
	IVector(FVector& fvec);

	/**
	 * Change the value of the vector
	 * @param x the new x value
	 * @param y the new y value
	 */
	void set(int x, int y);

	/**
	 * Change the x value of the vector
	 * @param x the new x value
	 */
	void setX(int x);

	/**
	 * Change the y value of the vector
	 * @param y the new y value
	 */
	void setY(int y);

	/**
	 * Gets the x value of this vector
	 * @return The x value as an int
	 */
	int getX() const;

	/**
	 * Gets the y value of this vector
	 * @return The y value as an int
	 */
	int getY() const;

	/**
	 * Addition operator for vectors (a+b)
	 * @param b the b vector
	 * @return The new vector
	 */
	IVector operator+(const IVector& b) const;

	/**
	 * Subtraction operator for vectors (a-b)
	 * @param b The b vector
	 * @return The new vector
	 */
	IVector operator-(const IVector& b) const;

	/**
	 * Negation operator for vector (-a)
	 * @return The negated version of the vector
	 */
	IVector operator-() const;

	/**
	 * Comparison operator for a==b
	 * @param b The other vector
	 * @return true if the two vectors are equal
	 */
	bool operator==(const IVector& b) const;

	/**
	 * Not Comparison operator for a!=b
	 * @param b The other vector
	 * @return true if the two vectors are not equal
	 */
	bool operator!=(const IVector& b) const;
};

#endif /* IVECTOR_H_ */
