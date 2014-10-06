/*
 * TesterObject.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: Benny
 */

#include "TesterObject.h"

#include "Utility.h"
#include "EventStep.h"
#include "EventCollision.h"
#include "EventKeybaord.h"
#include "EventMouse.h"
#include "EventOut.h"
#include "EVentView.h"
#include "WorldManager.h"
#include "GameManager.h"

#include <stdio.h>
#include <ncurses/ncurses.h>

TesterObject::TesterObject(IVector position)
{
	// TODO Auto-generated constructor stub
	setPosition(position);

	setVelocityX(0.25f);
	setSolidness(Hard);
}

TesterObject::~TesterObject()
{
	GameManager& gm = GameManager::getInstance();
	gm.setGameOver(true);
}

int TesterObject::eventHandler(Event* e)
{
	string typeName = e->getType();

	if (typeName == DF_EVENT_STEP)
	{
		EventStep* es = static_cast<EventStep*>(e);

		if (es->getStepCount() == 500)
		{
			WorldManager& wm = WorldManager::getInstance();
			wm.markForDelete(this);
		}

		return 1;
	}
	else if (typeName == DF_EVENT_KEYBOARD)
	{
		EventKeybaord* ek = static_cast<EventKeybaord*>(e);

		LogManager& log = LogManager::getInstance();
		log.writeLog("Key {id:%d} Pressed", ek->getKey());

		if(ek->getKey() == 'r')
		{
			WorldManager& wm = WorldManager::getInstance();
			EventView ev = EventView("Press r", 1, true);
			wm.onEvent(&ev);
		}
		else if(ek->getKey() == 'q')
		{
			WorldManager& wm = WorldManager::getInstance();
			EventView ev = EventView("Press q", 1, false);
			wm.onEvent(&ev);
		}
	}
	else if (typeName == DF_EVENT_MOUSE)
	{
		EventMouse* em = static_cast<EventMouse*>(e);

		LogManager& log = LogManager::getInstance();
		log.writeLog("Mouse Pressed {x:%d|y:%d}", em->getX(), em->getY());
	}
	else if (typeName == DF_EVENT_OUT)
	{
		WorldManager& wm = WorldManager::getInstance();
		wm.markForDelete(this);
	}

	return 0;
}

void TesterObject::draw()
{
	Object::draw();

	//GraphicsManager& g = GraphicsManager::getInstance();
	//g.drawString(IVector(0, 0), LEFT_JUSTIFIED, "TEST");
}
