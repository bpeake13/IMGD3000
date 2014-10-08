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

	/**
	 * This function is called when the monster gets to make an attack on the player
	 * It deals its 'attack' value in damage
	 */
	void attackPlayer();

	/**
	 * Getter for reward from defeating a monster
	 * @return
	 */
	int getReward() const;

	/**
	 * Setter for the reward from defeating a monster
	 * @param reward The reward amount from defeating the monster
	 */
	void setReward(int reward);

	/**
	 * This function gets a sprite from a filename, and sets the monsters sprite
	 * @param filename The file to get the sprite from
	 */
	void setSpr(string filename);
};

#endif /* MONSTER_H_ */
