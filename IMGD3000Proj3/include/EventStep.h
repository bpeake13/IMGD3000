/*
 * EventStep.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Benny
 */

#ifndef EVENTSTEP_H_
#define EVENTSTEP_H_

#define DF_EVENT_STEP "event_step"

#include "Event.h"

/**
 * Event called every step
 */
class EventStep : public Event
{
public:
	/**
	 * Creates a new step event
	 * @param stepCount The number step this is in the engine sense startup
	 */
	EventStep(unsigned int stepCount);

	/**
	 * Called when the step event is killed
	 */
	virtual ~EventStep();

	/**
	 * Get the step count from this event
	 * @return An unsigned int representing the step count
	 */
	unsigned int getStepCount() const;

private:
	unsigned int stepCount;//holder for the step count
};

#endif /* EVENTSTEP_H_ */
