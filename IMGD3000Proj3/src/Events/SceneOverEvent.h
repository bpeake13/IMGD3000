/*
 * SceneOverEvent.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Benny
 */

#ifndef SCENEOVEREVENT_H_
#define SCENEOVEREVENT_H_

#include "Event.h"
#include "Utility.h"

/**
 * An event that is sent when a scene has ended that can give additional info on why the scene ended
 */
class SceneOverEvent : public Event
{
public:
	/**
	 * Creates a new SceneOverEvent
	 * @param reason The reason this scene ended
	 * @param info Additional info that can be parsed
	 */
	SceneOverEvent(string reason, string info);

	/**
	 * Gets the reason the scene ended
	 * @return The reason the scene ended
	 */
	string getReason() const;

	/**
	 * Gets the info about the scene ending
	 * @return A string containing the info about the scene ending
	 */
	string getInfo() const;

private:
	string reason, info;
};

#endif /* SCENEOVEREVENT_H_ */
