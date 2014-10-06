/*
 * Sprite.cpp
 *
 *  Created on: Sep 29, 2014
 *      Author: Benny
 */

#include "Sprite.h"
#include "GraphicsManager.h"

Sprite::Sprite(string label, int frameCount)
{
	this->label = label;
	this->frames = new DynamicPtrArray(frameCount);
	this->color = DF_DEFAULT_COLOR;
	this->width = 0;
	this->height = 0;
}

string Sprite::getLabel() const
{
	return label;
}

int Sprite::getColor() const
{
	return color;
}

void Sprite::setColor(int color)
{
	this->color = color;
}

int Sprite::getWidth() const
{
	return width;
}

void Sprite::setWidth(int width)
{
	this->width = width;

	int frameCount = frames->getSize();
	for(int i = 0; i < frameCount; i++)
	{
		delete static_cast<Frame*>(frames->get(i));
	}

	frames->clear();
}

int Sprite::getHeight() const
{
	return height;
}

void Sprite::setHeight(int height)
{
	this->height = height;

	int frameCount = frames->getSize();
	for(int i = 0; i < frameCount; i++)
	{
		delete static_cast<Frame*>(frames->get(i));
	}

	frames->clear();
}

Frame* Sprite::getFrame(int index) const
{
	return static_cast<Frame*>(frames->get(index));
}

size_t Sprite::getFrameCount() const
{
	return frames->getSize();
}

bool Sprite::addFrame(Frame* frame)
{
	if(frame->getWidth() != width || frame->getHeight() != height)//do not add frames that are not the right dimensions
		return false;

	return frames->add(frame);
}
