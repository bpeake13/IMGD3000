/*
 * SpriteObject.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: Benny
 */

#include "SpriteObject.h"
#include "GraphicsManager.h"
#include "Box.h"

SpriteObject::SpriteObject(bool addToWorld) : Object(addToWorld)
{
	spr = NULL;
	drawCentered = false;
	frame = 0;
	slowdown = 0;
	slowdown_count = 0;
}

void SpriteObject::draw()
{
	if(!spr)
			return;

	Frame* f = spr->getFrame(frame);

	GraphicsManager& graphics = GraphicsManager::getInstance();
	graphics.drawFrame(getPosition(), f, drawCentered, getColor());

	if(slowdown == 0)
		return;

	slowdown_count++;
	if(slowdown_count >= slowdown)
	{
		slowdown_count = 0;
		frame += 1;
		frame = frame % spr->getFrameCount();
	}
}

Sprite* SpriteObject::getSprite() const
{
	return spr;
}

void SpriteObject::setSprite(Sprite* sprite, bool setBox)
{
	spr = sprite;

	if(setBox)
	{
		int w = sprite->getWidth();
		int h = sprite->getHeight();

		Box b = getBounds();

		if(drawCentered)
			b.setCorner(IVector(-w / 2, -h / 2));
		else
			b.setCorner(IVector(0, 0));

		b.setHorizontal(w);
		b.setVertical(h);

		setBounds(b);
	}
}

bool SpriteObject::isCentered() const
{
	return drawCentered;
}

void SpriteObject::setCentered(bool centered)
{
	drawCentered = centered;
}

void SpriteObject::setFrameIndex(int frame)
{
	if(spr)
		this->frame = frame % spr->getFrameCount();
	else
		this->frame = 0;
}

int SpriteObject::getFrameIndex() const
{
	return frame;
}

void SpriteObject::setSlowdown(int slowdown)
{
	this->slowdown = slowdown;
	this->slowdown_count = 0;
}

int SpriteObject::getSlowdown() const
{
	return slowdown;
}
