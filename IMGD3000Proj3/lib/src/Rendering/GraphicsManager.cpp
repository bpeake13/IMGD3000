/*
 * GraphicsManager.cpp
 *
 *  Created on: Sep 20, 2014
 *      Author: Benny
 */

#include "GraphicsManager.h"
#include "LogManager.h"
#include "WorldManager.h"

GraphicsManager::GraphicsManager()
{
	frontBuffer = NULL;
	backBuffer = NULL;
}

GraphicsManager::GraphicsManager(const GraphicsManager&)
{
	frontBuffer = NULL;
	backBuffer = NULL;
}

GraphicsManager& GraphicsManager::operator =(const GraphicsManager& other)
{
	return *this;
}

GraphicsManager& GraphicsManager::getInstance()
{
	static GraphicsManager gm;
	return gm;
}

void GraphicsManager::setupColors() const
{
	if(has_colors())
	{
		LogManager& log = LogManager::getInstance();
		log.writeLog("HAS COLOR");
		start_color();
	}

	assume_default_colors(DF_DEFAULT_COLOR, COLOR_BLACK);

	init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
	init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
	init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
	init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
}

int GraphicsManager::startUp()
{
	if(hasStarted())
		return 0;

	frontBuffer = initscr();//start curses and make the default window the front buffer
	if(!frontBuffer)//if we don't have a front buffer, return an error
		return -1;

	leaveok(frontBuffer, TRUE);

	backBuffer = newwin(0, 0, 0, 0);//create a new window for the back buffer
	if(!backBuffer)//if we can't create a back buffer then give an error
		return -1;

	leaveok(backBuffer, TRUE);

	wrefresh(frontBuffer);

	if(clearok(backBuffer, TRUE) != OK)//clear the back buffer
		return -1;

	setupColors();//setup the colors

	wattron(frontBuffer, A_BOLD);
	wattron(backBuffer, A_BOLD);

	Manager::startUp();

	return 0;
}

void GraphicsManager::shutDown()
{
	if(!hasStarted())
		return;

	Manager::shutDown();

	frontBuffer = NULL;
	backBuffer = NULL;

	endwin();//close curses

	LogManager& log = LogManager::getInstance();
	log.writeLog("GRAPHICS SHUTDOWN");
}

int GraphicsManager::swapBuffer(bool clearScreen)
{
	WINDOW* temp = backBuffer;
	backBuffer = frontBuffer;
	frontBuffer = temp;

	werase(backBuffer);

	if(clearok(frontBuffer, TRUE) == OK)
	{
		wrefresh(frontBuffer);
		return 1;
	}
	else
		return 0;
}

int GraphicsManager::getHorizontal() const
{
	int x, y;
	getmaxyx(frontBuffer, y, x);

	return x;
}

int GraphicsManager::getVertical() const
{
	int x, y;
	getmaxyx(frontBuffer, y, x);

	return y;
}

int GraphicsManager::drawCh(IVector worldPos, char c, int color) const
{
	wattron(backBuffer, COLOR_PAIR(color));//set the color to draw with

	WorldManager& world = WorldManager::getInstance();
	IVector drawPos = world.worldToView(worldPos);

	mvwaddch(backBuffer, drawPos.getY(), drawPos.getX(), c);

	wattroff(backBuffer, COLOR_PAIR(color));

}

int GraphicsManager::drawString(IVector worldPos, Justification justification,
		string str, int color) const
{
	switch(justification)
	{
	case LEFT_JUSTIFIED:
		break;
	case CENTER_JUSTIFIED:
		worldPos.setX(worldPos.getX() - (int)str.length() / 2);
		break;
	case RIGHT_JUSTIFIED:
		worldPos.setX(worldPos.getX() - (int)str.length());
	}

	int error = 0;

	int length = str.length();
	for(int i = 0; i < length; i++)
	{
		error += drawCh(worldPos, (char)str[i], color);
		worldPos = worldPos + IVector(1, 0);
	}

	return error;
}

WINDOW* GraphicsManager::getBackBuffer() const
{
	return backBuffer;
}

WINDOW* GraphicsManager::getFrontBuffer() const
{
	return frontBuffer;
}

int GraphicsManager::drawFrame(IVector worldPos, const Frame* frame,
		bool centered, int color) const
{
	if(!frame)//if we have an invalid frame then give an error
		return -1;

	int w  = frame->getWidth();
	int h = frame->getHeight();

	if(w == 0 || h == 0)
		return -1;

	if(centered)//if we are centered then calculate the offset to do so
	{
		worldPos = worldPos - IVector(w / 2, h / 2);
	}

	//cache static information
	int wx = worldPos.getX();
	int wy = worldPos.getY();

	string drawString = frame->getString();//get the string to draw

	IVector drawPos(0, 0);//will store where we want to draw
	for(int y = 0; y < h; y++)
	{
		drawPos.setY(y + wy);
		for(int x = 0; x < w; x++)
		{
			drawPos.setX(x + wx);
			int ci = x + y * w;//get the index of the character to draw in the string
			char c = drawString[ci];//get the character
			drawCh(drawPos, c, color);//draw the character at the draw position
		}
	}

	return 0;
}
