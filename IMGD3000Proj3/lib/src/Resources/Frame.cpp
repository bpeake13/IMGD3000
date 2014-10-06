/*
 * Frame.cpp
 *
 *  Created on: Sep 29, 2014
 *      Author: Benny
 */

#include "Frame.h"

Frame::Frame()
{
	this->width = 0;
	this->height = 0;
	this->str = "";
}

Frame::Frame(int width, int height, string str)
{
	this->width = width;
	this->height = height;
	this->str = str;
}

int Frame::getWidth() const
{
	return width;
}

int Frame::getHeight() const
{
	return height;
}

void Frame::setWidth(int width)
{
	this->width = width;
}

void Frame::setHeight(int height)
{
	this->height = height;
}

string Frame::getString() const
{
	return str;
}

void Frame::setString(string newStr)
{
	this->str = newStr;
}
