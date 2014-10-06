/*
 * Frame.h
 *
 *  Created on: Sep 29, 2014
 *      Author: Benny
 */

#ifndef FRAME_H_
#define FRAME_H_

#include "Utility.h"

/**
 * A single frame of a sprite
 */
class Frame
{
private:
	int width;//the width of the frame in characters
	int height;//the height of the frame in characters
	string str;//the characters that compose the frame
public:
	/**
	 * Creates an empty frame
	 */
	Frame();

	/**
	 * Creates a new frame
	 * @param width The width of the frame
	 * @param height The height of the frame
	 * @param str The characters that compose the frame
	 */
	Frame(int width, int height, string str);

	/**
	 * Gets the width of the frame
	 * @return The width of the frame
	 */
	int getWidth() const;

	/**
	 * Gets the height of the frame
	 * @return The height of the frame
	 */
	int getHeight() const;

	/**
	 * Sets the width of the frame
	 * @param width The new width of the frame
	 */
	void setWidth(int width);

	/**
	 * Sets the height of the frame
	 * @param height The new height of the frame
	 */
	void setHeight(int height);

	/**
	 * Get the string that this frame uses
	 * @return The string for this frame
	 */
	string getString() const;

	/**
	 * Set the string that this frame uses
	 * @param newStr The new string to use for this frame
	 */
	void setString(string newStr);
};

#endif /* FRAME_H_ */
