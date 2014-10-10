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
	/**
	 * Constructor for monster
	 */
	Monster();

	/**
	 * Constructor for monster
	 * @param name The name of the monster as a string
	 * @param health The health of the monster, as an int
	 * @param attack The attack power of the monster, as an int
	 * @param reward The reward for defeating this monster, as an int
	 * @param desc A description of the monster, as a string
	 */
	Monster(string name, int health, int attack, int reward, string desc);

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
