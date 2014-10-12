/*
 * BattlePhase.h
 *
 *  Created on: Oct 12, 2014
 *      Author: Benny
 */

#ifndef BATTLEPHASE_H_
#define BATTLEPHASE_H_

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
};

#endif /* BATTLEPHASE_H_ */
