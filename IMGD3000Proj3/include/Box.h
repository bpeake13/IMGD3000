/*
 * Box.h
 *
 *  Created on: Sep 10, 2014
 *      Author: Benny
 */

#ifndef BOX_H_
#define BOX_H_

#include "IVector.h"

/**
 * Represents a box
 */
class Box
{
public:
	/**
	 * Creates a new box
	 * @param init_corner The starting corner of the box
	 * @param horizontal The width of the box
	 * @param vertical The height of the box
	 */
	Box(IVector init_corner, int horizontal, int vertical);

	/**
	 * Creates a new box
	 * @param minCorner The upper left corner
	 * @param maxCorner The lower right corner
	 */
	Box(IVector minCorner, IVector maxCorner);

	/**
	 * Creates a default box (0, 0, 0, 0)
	 */
	Box();

	/**
	 * Changes the corner of the box
	 * @param newCorner
	 */
	void setCorner(IVector newCorner);

	/**
	 * Gets the current corner of the box
	 * @return The current corner of the box
	 */
	IVector getCorner() const;

	/**
	 * Gets the far corner of the box
	 * @return The far corner of the box
	 */
	IVector getMaxCorner() const;

	/**
	 * Sets a new horizontal for this box
	 * @param newHorizontal The new horizontal value
	 */
	void setHorizontal(int newHorizontal);

	/**
	 * Gets the current horizontal size of the box
	 * @return The current horizontal size of the box
	 */
	int getHorizontal() const;

	/**
	 * Sets a new vertical for this box
	 * @param newVertical The new vertical value
	 */
	void setVertical(int newVertical);

	/**
	 * Get the current vertical size of the box
	 * @return The current vertical size of the box
	 */
	int getVertical() const;

	bool contains(IVector point) const;

	bool intersects(const Box& box) const;

	bool operator==(Box &other) const;
	bool operator!=(Box &other) const;

private:
	IVector corner;
	int horizontal;
	int vertical;
};

#endif /* BOX_H_ */
