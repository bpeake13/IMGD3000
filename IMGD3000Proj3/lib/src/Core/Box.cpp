/*
 * Box.cpp
 *
 *  Created on: Sep 10, 2014
 *      Author: Benny
 */

#include "Box.h"

Box::Box(IVector init_corner, int horizontal, int vertical) : corner(IVector(0, 0))
{
	this->corner = corner;
	this->horizontal = horizontal;
	this->vertical = vertical;
}

Box::Box(IVector minCorner, IVector maxCorner) : corner(IVector(0, 0))
{
	this->corner = minCorner;
	this->horizontal = maxCorner.getX() - minCorner.getX();
	this->vertical = maxCorner.getY() - minCorner.getY();
}

Box::Box() : corner(IVector(0, 0))
{
	this->corner = IVector(0, 0);
	this->horizontal = 0;
	this->vertical = 0;
}

IVector Box::getCorner() const
{
	return corner;
}

IVector Box::getMaxCorner() const
{
	return corner + IVector(horizontal, vertical);
}

int Box::getHorizontal() const
{
	return horizontal;
}

int Box::getVertical() const
{
	return vertical;
}

void Box::setCorner(IVector newCorner)
{
	corner = newCorner;
}

void Box::setHorizontal(int newHorizontal)
{
	horizontal = newHorizontal;
}

void Box::setVertical(int newVertical)
{
	vertical = newVertical;
}

bool Box::contains(IVector point) const
{
	int xDiff = point.getX() - corner.getX();
	int yDiff = point.getY() - corner.getY();

	return xDiff >= 0 && yDiff >= 0 && xDiff <= horizontal && yDiff <= vertical;
}

bool Box::operator ==(Box& other) const
{
	return other.corner == this->corner && other.horizontal == this->horizontal && other.vertical == this->vertical;
}

bool Box::operator !=(Box& other) const
{
	return other.corner != this->corner || other.horizontal != this->horizontal || other.vertical != this->vertical;
}

bool Box::intersects(const Box& box) const
{
	IVector min = this->corner;
	IVector max = this->corner + IVector(this->horizontal, this->vertical);

	IVector otherMin = box.corner;
	IVector otherMax = box.corner + IVector(box.horizontal, box.vertical);

	bool hOverlap = (min.getX() <= otherMax.getX() && min.getX() >= otherMin.getX())
			|| (max.getX() <= otherMax.getX() && max.getX() >= otherMin.getX());

	hOverlap = hOverlap
			|| ((otherMin.getX() <= max.getX() && otherMin.getX() >= min.getX())
			|| (otherMax.getX() <= max.getX() && otherMax.getX() >= min.getX()));

	bool vOverlap = (min.getY() <= otherMax.getY() && min.getY() >= otherMin.getY())
				|| (max.getY() <= otherMax.getY() && max.getY() >= otherMin.getY());

	vOverlap = vOverlap
				|| ((otherMin.getY() <= max.getY() && otherMin.getY() >= min.getY())
				|| (otherMax.getY() <= max.getY() && otherMax.getY() >= min.getY()));

	return hOverlap && vOverlap;
}

