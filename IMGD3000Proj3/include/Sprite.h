/*
 * Sprite.h
 *
 *  Created on: Sep 29, 2014
 *      Author: Benny
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "DynamicPtrArray.h"
#include "Frame.h"

/**
 * A sprite made out of characters
 */
class Sprite
{
private:
	//the dimensions of the sprite
	int width;
	int height;

	int color;

	DynamicPtrArray* frames;//list of frames
	string label;//what name this sprite has
public:
	/**
	 * Creates a new sprite
	 * @param frameCount The number of frames in this sprite
	 */
	Sprite(string label, int frameCount);

	/**
	 * Gets the sprites label that it is referenced by in the resource manager
	 * @return
	 */
	string getLabel() const;

	/**
	 * Gets the color of the sprite
	 * @return The color of the sprite
	 */
	int getColor() const;

	/**
	 * Sets the color of the sprite
	 * @param color The new color for the sprite
	 */
	void setColor(int color);

	/**
	 * Gets the width of the sprite
	 * @return The width of the sprite in characters
	 */
	int getWidth() const;

	/**
	 * Sets the width of the sprite
	 * @param width The new width of the sprite in characters
	 */
	void setWidth(int width);

	/**
	 * Sets the height of the sprite
	 * @return The height of the sprite in characters
	 */
	int getHeight() const;

	/**
	 * Sets the height of the sprite
	 * @param height The new height of the sprite in characters
	 */
	void setHeight(int height);

	/**
	 * Get a frame in the sprite
	 * @param index The index of the frame to get
	 * @return The frame at index, or NULL if it is not found
	 */
	Frame* getFrame(int index) const;

	/**
	 * Gets the number of frames in this sprite
	 * @return The number of frames in this sprite
	 */
	size_t getFrameCount() const;

	/**
	 * Adds a frame to the sprite
	 * @param frame The new frame to add
	 * @return True if the frame was added, false otherwise
	 */
	bool addFrame(Frame* frame);
};

#endif /* SPRITE_H_ */
