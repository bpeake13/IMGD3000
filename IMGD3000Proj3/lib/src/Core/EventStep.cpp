/*
 * EventStep.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: Benny
 */

#include "EventStep.h"

EventStep::EventStep(unsigned int stepCount)
{
	this->stepCount = stepCount;
	setType(DF_EVENT_STEP);//set this to the correct type
}

EventStep::~EventStep()
{
}

unsigned int EventStep::getStepCount() const
{
	return stepCount;
}
