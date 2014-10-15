/*
 * BattleWinPhase.h
 *
 *  Created on: Oct 14, 2014
 *      Author: Benny
 */

#ifndef BATTLEWINPHASE_H_
#define BATTLEWINPHASE_H_

#include "BattlePhase.h"

class BattleWinPhase : public BattlePhase
{
public:
	BattleWinPhase(Battle* battle);

	int eventHandler(Event* e);

	string getMessage();

	BattlePhase* getNext();

	bool endBattle(string* reason, string* info);

private:
	bool buttonPressed;
};

#endif /* BATTLEWINPHASE_H_ */
