/*
 * Object.h
 *
 *  Created on: Sep 14, 2014
 *      Author: Benny
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "IVector.h"
#include "FVector.h"
#include "Box.h"
#include "Utility.h"
#include "Event.h"
#include "Sprite.h"

/**
 * Represents what type of collision an object has
 */
enum Solidness
{
	Hard,   //!< Hard Will collide with objects, cannot occupy same space as an object that is also hard
	Soft,   //!< Soft Can get collision events, however has no collision response
	Spectral//!< Spectral No collision
};

/**
 * The base class for all objects
 */
class Object {
public:
	/**
	 * Creates a new object in the world
	 * @param addToWorld If true, then this object will be added to the world. By default true
	 */
	Object(bool addToWorld = true);

	/**
	 * DO NOT CALL THROUGH DELETE, CALL THROUGH MARK FOR DELETE
	 */
	virtual ~Object();

	/**
	 * Changes this objects id to the new ID
	 * @param newID The new id to change this objects id to
	 * @return returns the new id that was assigned, or 0 on fail
	 * @remarks When the id is failed to be set we will not go to a 0 id but
	 * just keep the old id
	 */
	int setID(unsigned int newID);

	/**
	 * Gets the ID of this object
	 * @return The object ID
	 */
	unsigned int getID() const;

	/**
	 * Gets the type name of this object
	 * @return The type name of this object
	 */
	string getType() const;

	/**
	 * Sets the type of this object
	 * @param type The new type name for this object
	 */
	void setType(string type);

	/**
	 * Sets the collision model to use with this object
	 * @param solidness The collision model to use
	 * @return True if the solidness could be set, false otherwise
	 */
	bool setSolidness(Solidness solidness);

	/**
	 * Gets the collision model to use with this object
	 * @return The collision model that this object is using
	 */
	Solidness getSolidness() const;

	/**
	 * Checks to see if the object will have a collision
	 * @return True if collision model is set to HARD or SOFT, otherwise false
	 */
	bool isCollidable();

	/**
	 * Set the render order of this object
	 * @param value The new value to set altitude to
	 */
	void setAltitude(unsigned int value);

	/**
	 * Get the render order of this object
	 * @return The altitude as an unsigned int
	 */
	unsigned int getAltitude() const;

	/**
	 * Changes the objects position
	 * @param newPosition The new position this object should be at
	 */
	void setPosition(IVector newPosition);

	/**
	 * Gets the current position of this object
	 * @return The position of this object
	 */
	IVector getPosition() const;

	/**
	 * Sets the velocity of the object
	 * @param velocity The x and y velocity of the object
	 */
	void setVelocity(FVector velocity);

	/**
	 * Sets the x velocity of the object
	 * @param x The x velocity
	 */
	void setVelocityX(float x);

	/**
	 * Set the y velocity of the object
	 * @param y The y velocity
	 */
	void setVelocityY(float y);

	/**
	 * Gets the velocity of the object
	 * @return An FVector that represents the x and y velocity
	 */
	FVector getVelocity() const;

	/**
	 * Gets the x velocity of the object
	 * @return A floating point number that is the x velocity of the object in units/step
	 */
	float getVelocityX() const;

	/**
	 * Gets the y velocity of the object
	 * @return A floating point number that is the y velocity of the object in units/step
	 */
	float getVelocityY() const;

	/**
	 * Steps the object one frame forward
	 * @return The amount moved this frame
	 */
	IVector getVelocityStep();

	/**
	 * Get the bounding box for this object
	 * @return The objects bounding box
	 */
	Box getBounds() const;

	/**
	 * Sets the bounding box for this object
	 * @param bounds The new bounding box
	 */
	void setBounds(Box bounds);

	/**
	 * Gets the objects bounds in world space
	 * @return The objects bounds in world space
	 */
	Box getWorldBounds() const;

	/**
	 * Gets an objects bounds in world space as though the object is at a different position
	 * @param position The new position to say the object is at
	 * @return The objects bounds in world space relative to the position
	 */
	Box getWorldBounds(const IVector& position) const;

	/**
	 * Sets the color to draw the object with
	 * @param color The color to draw the object with
	 */
	void setColor(int color);

	/**
	 * Gets the color to draw the object with
	 * @return The color to draw the object with
	 */
	int getColor() const;

	/**
	 * Handles events given to this object
	 * @param e A pointer to the event data
	 * @return a non-zero number if this object does consume the event, otherwise 0
	 */
	virtual int eventHandler(Event* e);

	/**
	 * Called once per frame to draw the object
	 */
	virtual void draw();

private:

	IVector position;

	FVector velocity;//untis/step

	FVector velocityCountDown;//countdown of the velocity

	string typeName;

	unsigned int id;

	unsigned int altitude;

	Solidness solidness;//the collision mode

	int color;

	Box bounds;
};

#endif /* OBJECT_H_ */
