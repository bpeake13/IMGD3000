/*
 * ViewObject.cpp
 *
 *  Created on: Sep 30, 2014
 *      Author: Benny
 */

#include <sstream>

#include "ViewObject.h"
#include "EventView.h"

#include "WorldManager.h"

IVector getViewOrigin(ViewObjectLocation location)
{
	WorldManager& world = WorldManager::getInstance();
	Box view = world.getView();
	switch(location)
	{
	case TOP_LEFT:
		return IVector(0, 0);
	case TOP_CENTER:
		return IVector(view.getHorizontal() / 2, 0);
	case TOP_RIGHT:
		return IVector(view.getHorizontal(), 0);
	case BOTTOM_LEFT:
		return IVector(0, view.getVertical());
	case BOTTOM_CENTER:
		return IVector(view.getHorizontal() / 2, view.getVertical());
	case BOTTOM_RIGHT:
		return IVector(view.getHorizontal(), view.getVertical());
	case CENTER_CENTER:
		return IVector(view.getHorizontal() / 2, view.getVertical() / 2);
	}
}

IVector getTextCenterOffset(ViewObjectLocation location, bool bordered)
{
	if(bordered)
	{
		switch(location)
		{
		case TOP_LEFT:
		case TOP_CENTER:
		case TOP_RIGHT:
			return IVector(0, 0);
		case BOTTOM_LEFT:
		case BOTTOM_CENTER:
		case BOTTOM_RIGHT:
			return IVector(0, -3);
		case CENTER_CENTER:
			return IVector(0, -1);
		}
	}
	else
	{
		switch(location)
		{
		case TOP_LEFT:
		case TOP_CENTER:
		case TOP_RIGHT:
			return IVector(0, 0);
		case CENTER_CENTER:
			return IVector(0, 0);
		case BOTTOM_LEFT:
		case BOTTOM_CENTER:
		case BOTTOM_RIGHT:
			return IVector(0, -2);

		}
	}
}

//Convert an int to to a string
string intToString(int i)
{
	std::stringstream ss;
	ss << i;
	return ss.str();
}

string constructRepeatingString(char c, int count)
{
	string s = "";
	for(int i = 0; i < count; i++)
	{
		s += c;
	}

	return s;
}

ViewObject::ViewObject()
{
	// TODO Auto-generated constructor stub
	setSolidness(Spectral);
	setAltitude(LAYER_COUNT - 1);
	setType("ViewObject");

	setValue(0);
	setDrawBorder(true);
	setViewObjectLocation(TOP_CENTER);
	setColor(DF_DEFAULT_COLOR);
}

int ViewObject::eventHandler(Event* e)
{
	EventView* ve = dynamic_cast<EventView*>(e);

	if(!ve || ve->getTag() != viewString)
		return 0;

	if(ve->getDelta())
		value += ve->getValue();
	else
		value = ve->getValue();

	return 1;
}

void ViewObject::draw()
{
	WorldManager& world = WorldManager::getInstance();
	int color = getColor();

	IVector origin = getViewOrigin(location);//get what our world origin should be

	IVector viewLocation = getPosition() + origin;//get the offset from that origin

	IVector offset = getTextCenterOffset(location, drawBorder);

	viewLocation = viewLocation + offset;//apply the offset

	IVector worldLocation = world.viewToWorld(viewLocation);//convert into world coordinates

	GraphicsManager& graphics = GraphicsManager::getInstance();

	string renderString = viewString + " " + intToString(value);//get the render string
	if(drawBorder)
	{
		renderString = "|" + renderString + "|";
		string border = constructRepeatingString('-', renderString.length());

		graphics.drawString(worldLocation, justification, border, color);
		graphics.drawString(worldLocation + IVector(0, 2), justification, border, color);

		worldLocation = worldLocation + IVector(0, 1);
	}

	graphics.drawString(worldLocation, justification, renderString, color);
}

string ViewObject::getViewString() const
{
	return viewString;
}

void ViewObject::setViewString(string viewString)
{
	this->viewString = viewString;
}

int ViewObject::getValue() const
{
	return value;
}

void ViewObject::setValue(int value)
{
	this->value = value;
}

bool ViewObject::getDrawBorder() const
{
	return drawBorder;
}

void ViewObject::setDrawBorder(bool drawBorder)
{
	this->drawBorder = drawBorder;
}

Justification ViewObject::getJustification() const
{
	return this->justification;
}

void ViewObject::setJustification(Justification justification)
{
	this->justification = justification;
}

ViewObjectLocation ViewObject::getViewObjectLocation() const
{
	return location;
}

void ViewObject::setViewObjectLocation(
		ViewObjectLocation enumViewObjectLocation)
{
	this->location = enumViewObjectLocation;

	switch(location)
	{
	case TOP_LEFT:
	case BOTTOM_LEFT:
		setJustification(LEFT_JUSTIFIED);
		break;
	case TOP_CENTER:
	case CENTER_CENTER:
	case BOTTOM_CENTER:
		setJustification(CENTER_JUSTIFIED);
		break;
	case TOP_RIGHT:
	case BOTTOM_RIGHT:
		setJustification(RIGHT_JUSTIFIED);
		break;
	}
}
