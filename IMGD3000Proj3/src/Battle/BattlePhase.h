/*
 * BattlePhase.h
 *
 *  Created on: Oct 12, 2014
 *      Author: Benny
 */

#ifndef BATTLEPHASE_H_
#define BATTLEPHASE_H_

#include "Event.h"

/**
 * Represents a single phase of battle, blocking all actions until this phase finishes
 */
class BattlePhase
{
public:
	/**
	 * Creates a new battle phase
	 */
	BattlePhase();

	/**
	 * Called to destroy the current battle phase
	 */
	virtual ~BattlePhase();

	/**
	 * A local
	 * @param e
	 * @return
	 */
	virtual int eventHandler(Event* e);

	/**
	 * Called once per frame to get the next phase, if NULL this phase will resume
	 * @return The next battle phase to activate, or NULL to keep the current battle phase
	 * @remark Returning anything that is not NULL will result in this phase being deleted
	 */
	BattlePhase* getNext();

	/**
	 * Checks to see if the battle should end
	 * @param reason If the battle has ended, this will be filled with the reason for ending the battle
	 * @param info If the battle has ended, this will be filled with the info about why the battle ended
	 * @return True if the battle should end, false otherwise
	 * @remarks This is called once per frame after getNext
	 */
	bool endBattle(string* reason, string* info);
};

#endif /* BATTLEPHASE_H_ */
