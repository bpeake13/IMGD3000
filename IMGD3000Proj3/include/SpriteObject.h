/*
 * SpriteObject.h
 *
 *  Created on: Oct 5, 2014
 *      Author: Benny
 */

#ifndef SPRITEOBJECT_H_
#define SPRITEOBJECT_H_

#include "Object.h"

/**
 * Object that can display a sprite to the screen
 */
class SpriteObject : public Object
{
public:
	/**
	 * Creates a default sprite object
	 */
	SpriteObject();

	virtual void draw();

	/**
	 * Gets the sprite that this object uses
	 * @return The sprite this object uses or NULL if there is none
	 */
	Sprite* getSprite() const;

	/**
	 * Sets the sprite for this object
	 * @param sprite The sprite that this object should use
	 * @param setBox If true then the bounding box for this object will be set to fit this sprite
	 */
	void setSprite(Sprite* sprite, bool setBox = true);

	/**
	 * Checks to see if this object is centered on its position
	 * @return True if it is centered, false otherwise
	 */
	bool isCentered() const;

	/**
	 * Sets if this object should be centered on its world position or not
	 * @param centered If true the object will be centered, if false the object will not
	 */
	void setCentered(bool centered);

	/**
	 * Sets the current frame that the object should render
	 * @param frame The index of the frame in the sprite, if this number is out of bounds it will be wrapped around to fit
	 */
	void setFrameIndex(int frame);

	/**
	 * Gets the index of the current frame of the sprite
	 * @return The index of the current frame
	 */
	int getFrameIndex() const;

	/**
	 * Sets the slowdown on the animation
	 * @param slowdown The number of frames to wait before drawing the next frame
	 */
	void setSlowdown(int slowdown);

	/**
	 * Gets the slowdown for the animation
	 * @return The number of frames to wait before drawing the next frame
	 */
	int getSlowdown() const;

private:
	Sprite* spr;//the sprite to use, if NULL then the object will not draw
	int frame;//the frame of the sprite to render on
	bool drawCentered;//if true then draw the sprite from the center
	int slowdown;
	int slowdown_count;
};

#endif /* SPRITEOBJECT_H_ */
