/*
 * IVector.cpp
 *
 *  Created on: Sep 8, 2014
 *      Author: Benny
 */

#include "IVector.h"

IVector::IVector(int x, int y)
{
	this->x = x;
	this->y = y;
}

IVector::IVector(FVector& fvec)
{
	this->x = (int)fvec.getX();
	this->y = (int)fvec.getY();
}

void IVector::set(int x, int y)
{
	this->x = x;
	this->y = y;
}

void IVector::setX(int x)
{
	this->x = x;
}

void IVector::setY(int y)
{
	this->y = y;
}

int IVector::getX() const
{
	return x;
}

int IVector::getY() const
{
	return y;
}


bool IVector::operator ==(const IVector& b) const
{
	return this->x == b.x && this->y == b.y;
}

bool IVector::operator !=(const IVector& b) const{
	return this->x != b.x || this->y != b.y;
}

IVector IVector::operator +(const IVector& b) const{
	return IVector(this->x + b.x, this->y + b.y);
}

IVector IVector::operator -(const IVector& b) const{
	return IVector(this->x - b.x, this->y - b.y);
}

IVector IVector::operator -()const{
	return IVector(-this->x, -this->y);
}
