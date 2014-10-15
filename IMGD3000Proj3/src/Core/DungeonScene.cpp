/*
 * DungeonScene.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Benny
 */

#include "DungeonScene.h"
#include "EventStep.h"
#include "MathExt.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "PartyManager.h"
#include "GoldFoundEvent.h"
#include "BattleEvent.h"

#define EVENT_COUNT 2

DungeonScene::DungeonScene(int stepCount)
{
	events = new DungeonEvent*[EVENT_COUNT];
	events[0] = new GoldFoundEvent;
	events[1] = new BattleEvent;

	stepCounter = 30;
	isSteping = true;

	currentEvent = NULL;

	steps = 0;
	maxSteps = stepCount;

	PartyManager& pm = PartyManager::getInstance();
	pm.startUp();

	size_t partySize = pm.getPartySize();

	IVector offset = IVector(0, -5);
	statViews = new PlayerStatView*[partySize];
	for(int i = 0; i < partySize; i++)
	{
		Adventurer* a = pm.getPartyMember(0);
		PlayerStatView* psv = new PlayerStatView(a);
		psv->setViewObjectLocation(BOTTOM_LEFT);
		psv->setPosition(offset);
		psv->setColor(COLOR_GREEN);

		offset = offset + IVector(0, -5);

		statViews[i] = psv;
	}

	money = new ViewObject;
	money->setViewString("Gold: ");
	money->setValue(0);
	money->setViewObjectLocation(BOTTOM_RIGHT);
	money->setColor(COLOR_YELLOW);
}

int DungeonScene::eventHandler(Event* e)
{
	if(Scene::eventHandler(e))//if the base class has processed then do not process
		return 1;

	string eventType = e->getType();
	if(eventType == DF_EVENT_STEP)
	{
		PartyManager& pm = PartyManager::getInstance();
		money->setValue(pm.getTreasure());

		if(!currentEvent && isSteping)
		{
			stepCounter--;
			if(stepCounter <= 0)//every time the step counter reaches zero take a step
				step();

			return 1;
		}
		else if(currentEvent)
		{
			if(currentEvent->isDone())
			{
				currentEvent->finish();
				currentEvent = NULL;
			}
		}
	}

	return 0;
}



int DungeonScene::getSteps() const
{
	return steps;
}

void DungeonScene::step()
{
	stepCounter = 30;
	steps++;

	int eventIndex = Math::randomRange(0, EVENT_COUNT);
	DungeonEvent* e = events[eventIndex];

	float p = e->getProbability();
	float r = Math::randomFloat();
	if(r <= p)
	{
		currentEvent = e;
		currentEvent->start();
	}
}

void DungeonScene::draw()
{
	string stepDisplay = "*";
	for(int i = 0; i < maxSteps; i++)
	{
		if(i == steps)
			stepDisplay += "!";
		else
			stepDisplay += "-";
	}

	stepDisplay += "*";

	GraphicsManager& graphics = GraphicsManager::getInstance();
	graphics.drawString(IVector(0, 0), LEFT_JUSTIFIED, stepDisplay);
}
