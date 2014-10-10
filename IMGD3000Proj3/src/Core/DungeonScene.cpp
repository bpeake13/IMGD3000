/*
 * DungeonScene.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Benny
 */

#include "DungeonScene.h"
#include "EventStep.h"
#include "MathExt.h"

#define EVENT_COUNT 1

DungeonScene::DungeonScene()
{
	events = new DungeonEvent*[EVENT_COUNT];
	stepCounter = 30;
	isSteping = false;

	currentEvent = NULL;
}

int DungeonScene::eventHandler(Event* e)
{
	if(Scene::eventHandler(e))//if the base class has processed then do not process
		return 1;

	string eventType = e->getType();
	if(eventType == DF_EVENT_STEP)
	{
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

void DungeonScene::step()
{
	stepCounter = 30;

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
