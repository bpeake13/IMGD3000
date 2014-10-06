/*
 * FVector.cpp
 *
 *  Created on: Sep 8, 2014
 *      Author: Benny
 */

#include "FVector.h"

FVector::FVector(float x, float y)
{
	this->x = x;
	this->y = y;
}

FVector::FVector(IVector& ivec)
{
	this->x = ivec.getX();
	this->y = ivec.getY();
}

void FVector::set(float x, float y)
{
	this->x = x;
	this->y = y;
}

void FVector::setX(float x)
{
	this->x = x;
}

void FVector::setY(float y)
{
	this->y = y;
}

float FVector::getX() const
{
	return x;
}

float FVector::getY() const
{
	return y;
}


bool FVector::operator ==(const FVector& b) const
{
	return this->x == b.x && this->y == b.y;
}

bool FVector::operator !=(const FVector& b) const{
	return this->x != b.x || this->y != b.y;
}

FVector FVector::operator +(const FVector& b) const{
	return FVector(this->x + b.x, this->y + b.y);
}

FVector FVector::operator -(const FVector& b) const{
	return FVector(this->x - b.x, this->y - b.y);
}

FVector FVector::operator -()const{
	return FVector(-this->x, -this->y);
}
