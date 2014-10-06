/*
 * Object.cpp
 *
 *  Created on: Sep 14, 2014
 *      Author: Benny
 */

#include "Object.h"

#include "WorldManager.h"

#include "GraphicsManager.h"

#include <math.h>

using namespace std;

static int idCount = 0;

Object::Object() : position(IVector(0, 0)), velocity(FVector(0, 0)), velocityCountDown(FVector(1, 1))
{
	position = IVector(0, 0);
	velocity = FVector(0, 0);
	velocityCountDown = FVector(1, 1);
	solidness = Spectral;
	altitude = 0;
	typeName = "";
	id = idCount;
	idCount++;

	WorldManager& world = WorldManager::getInstance();
	world.addObject(this);
	world.addToLayerPool(this);

	color = DF_DEFAULT_COLOR;

	bounds = Box(IVector(0, 0), 1, 1);
}

Object::~Object()
{
	// TODO Auto-generated destructor stub
}

string Object::getType() const
{
	return typeName;
}

void Object::setType(string type)
{
	this->typeName = type;
}

IVector Object::getPosition() const
{
	return position;
}

void Object::setPosition(IVector newPosition)
{
	this->position = newPosition;
}

void Object::setVelocity(FVector velocity)
{
	this->velocity = velocity;
}

void Object::setVelocityX(float x)
{
	this->velocity.setX(x);
}

void Object::setVelocityY(float y)
{
	this->velocity.setY(y);
}

FVector Object::getVelocity() const
{
	return this->velocity;
}

float Object::getVelocityX() const
{
	return this->velocity.getX();
}

float Object::getVelocityY() const
{
	return this->velocity.getY();
}

IVector Object::getVelocityStep()
{
	if(velocity == FVector(0, 0))//if no velocity then do not calculate new position
		return IVector(0, 0);

	FVector absVal = FVector(fabsf(velocity.getX()), fabsf(velocity.getY()));//get the absolute velocity

	velocityCountDown = velocityCountDown - absVal;

	IVector delta = IVector(0, 0);

	float vcdX, vcdY;
	if((vcdX = velocityCountDown.getX()) <= 0)
	{
		float xSpaces = floorf(1.f - vcdX);//get the number of xSpaces we have moved
		velocityCountDown.setX(1.f + fmodf(vcdX, 1));//get the remainder and apply it to the countdown

		delta.setX((int)xSpaces);
	}

	if((vcdY = velocityCountDown.getY()) <= 0)
	{
		float ySpaces = floorf(1.f - vcdY);//get the number of xSpaces we have moved
		velocityCountDown.setY(1.f + fmodf(vcdY, 1));//get the remainder and apply it to the countdown

		delta.setY((int)ySpaces);
	}

	return delta;
}

void Object::setAltitude(unsigned int value)
{
	WorldManager& world = WorldManager::getInstance();

	world.removeFromPool(this);
	this->altitude = value;
	world.addToLayerPool(this);
}

unsigned int Object::getAltitude() const
{
	return this->altitude;
}


unsigned int Object::getID() const
{
	return id;
}

int Object::setID(unsigned int newID)
{
	this->id = newID;
	return 1;//TODO: add world management
}


bool Object::setSolidness(Solidness solidness)
{
	this->solidness = solidness;
	return true;
}

Solidness Object::getSolidness() const
{
	return this->solidness;
}

bool Object::isCollidable()
{
	return this->solidness == Hard || this->solidness == Soft;
}

Box Object::getBounds() const
{
	return bounds;
}

void Object::setBounds(Box bounds)
{
	this->bounds = bounds;
}

Box Object::getWorldBounds() const
{
	Box worldBox = bounds;
	worldBox.setCorner(worldBox.getCorner() + position);
	return worldBox;
}

Box Object::getWorldBounds(const IVector& position) const
{
	Box worldBox = bounds;
	worldBox.setCorner(worldBox.getCorner() + position);
	return worldBox;
}

void Object::setColor(int color)
{
	this->color = color;
}

int Object::getColor() const
{
	return color;
}

int Object::eventHandler(Event* e)
{
	return 0;
}

void Object::draw()
{

}
