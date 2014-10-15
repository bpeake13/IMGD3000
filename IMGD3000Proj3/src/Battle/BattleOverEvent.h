/*
 * BattleOverEvent.h
 *
 *  Created on: Oct 15, 2014
 *      Author: Benny
 */

#ifndef BATTLEOVEREVENT_H_
#define BATTLEOVEREVENT_H_

#include "Event.h"

#define DF_BATTLE_OVER_EVENT "__boe__"

/**
 * Event called when a battle ends
 */
class BattleOverEvent : public Event
{
public:
	/**
	 * Creates a new battle over event
	 * @param reason The reason the battle ended
	 * @param info The info as to why the battle ended
	 */
	BattleOverEvent(string reason, string info);

	/**
	 * Gets the reason the battle ended
	 * @return A string showing the reason the battle ended
	 */
	string getReason() const;

	/**
	 * Gets the info about the battle ending
	 * @return A string containing the info about the battle ending
	 */
	string getInfo() const;

private:
	string reason;
	string info;
};

#endif /* BATTLEOVEREVENT_H_ */
