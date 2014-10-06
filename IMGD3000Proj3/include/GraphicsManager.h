/*
 * GraphicsManager.h
 *
 *  Created on: Sep 20, 2014
 *      Author: Benny
 */

#ifndef GRAPHICSMANAGER_H_
#define GRAPHICSMANAGER_H_

#include "Manager.h"
#include "Frame.h"
#include "Utility.h"
#include "IVector.h"

#ifdef CYGWIN
#include <ncurses/curses.h>
#else
#include <curses.h>
#endif

#define DF_DEFAULT_COLOR COLOR_WHITE

enum Justification {
  LEFT_JUSTIFIED,
  CENTER_JUSTIFIED,
  RIGHT_JUSTIFIED,
};

/**
 * Manages drawing and rendering to the screen
 */
class GraphicsManager : Manager
{
private:
	//singleton object, these are not used
	GraphicsManager();
	GraphicsManager (GraphicsManager const&);
	GraphicsManager& operator=(const GraphicsManager& other);

	WINDOW* frontBuffer;//a pointer to the displaying buffer
	WINDOW* backBuffer;//pointer to the current drawing buffer

public:

	/**
	 * Get the graphics manager instance
	 * @return A reference to the graphics manager instance
	 */
	static GraphicsManager& getInstance();

	/**
	 * Called when the graphics manager is started
	 * @return 0 if the graphics manager was started, otherwise returns < 0
	 */
	int startUp();

	/**
	 * Called when the graphics manager is shutdown
	 */
	void shutDown();

	/**
	 * Swaps the front and back buffer
	 * @param clear If true, clears the new back buffer
	 * @return 1 when the swap worked, -1 if not
	 */
	int swapBuffer(bool clear = true);

	/**
	 * Gets the horizontal size of the terminal in characters
	 * @return An integer showing how many characters across the terminal is
	 */
	int getHorizontal() const;

	/**
	 * Gets the vertical size of the terminal in characters
	 * @return An integer showing how many characters across the terminal is
	 */
	int getVertical() const;

	/**
	 * Draws a character at the world position
	 * @param worldPos The world position to draw the character at
	 * @param c The character to draw
	 * @param color The color to draw the character
	 * @return 0 if ok, -1 if not
	 */
	int drawCh(IVector worldPos, char c, int color=DF_DEFAULT_COLOR) const;

	/**
	 * Draws a string at the world position
	 * @param worldPos The world position to draw the string at
	 * @param justification The justification to draw the string at
	 * @param str The string to draw
	 * @param color The color to draw the string with
	 * @return 0 on ok, -1 to on fail
	 */
	int drawString(IVector worldPos, Justification justification, string str, int color=DF_DEFAULT_COLOR) const;

	/**
	 * Draws a frame of characters
	 * @param worldPos The world position to draw the frame at
	 * @param frame The frame to draw
	 * @param centered If true, then we should consider the draw point the center of the frame
	 * @param color The color to draw the frame with
	 * @return 0 on ok , -1 on fail
	 */
	int drawFrame(IVector worldPos, const Frame* frame, bool centered, int color=DF_DEFAULT_COLOR) const;

	/**
	 * Gets the current buffer we are rendering to
	 * @return A pointer to the back buffer
	 */
	WINDOW* getBackBuffer() const;

	/**
	 * Gets the current buffer we are displaying
	 * @return A pointer to the front buffer
	 */
	WINDOW* getFrontBuffer() const;

private:

	void setupColors() const;
};

#endif /* GRAPHICSMANAGER_H_ */
