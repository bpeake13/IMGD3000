/*
 * Monster.h
 *
 *  Created on: Oct 6, 2014
 *      Author: Eric
 */

#ifndef MONSTER_H_
#define MONSTER_H_

#include "Creature.h"

class Monster: public Creature {
private:
	int reward;

public:
	Monster();
	virtual ~Monster();
	void attackPlayer();
	int getReward() const;
	void setReward(int reward);
	void setSpr(string name);
};

#endif /* MONSTER_H_ */
