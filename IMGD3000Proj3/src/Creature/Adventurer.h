/*
 * Adventurer.h
 *
 *  Created on: Oct 6, 2014
 *      Author: Eric
 */

#ifndef ADVENTURER_H_
#define ADVENTURER_H_

#include "Creature.h"

class Adventurer: public Creature {
private:
	/**
	 * This is the magical attack power of the adventurer
	 */
	int magic;

public:
	/**
	 * Constructor for adventurer
	 */
	Adventurer();
	/**
	 * Constructor for adventurer
	 * @param name The name of the adventurer, as a string
	 * @param health The health of the adventurer, as an int
	 * @param atk The physical attack of the adventurer, as an int
	 * @param mag The magical attack power of the adventurer, as an int
	 * @param desc The description of the adventurer
	 */
	Adventurer(string name, int health, int atk, int mag, string desc);

	/**
	 * The destructor of the adventurer
	 */
	virtual ~Adventurer();

	/**
	 * This magic-type attack fills an AttackEvent with data
	 * @param e The event to modify
	 */
	void magicAttack(AttackEvent* e);

	/**
	 * Getter for magical attack power
	 * @return the magic variable
	 */
	int getMagic() const;
	/**
	 * Setter for magical attack power
	 * @param magic
	 */
	void setMagic(int magic);
};

#endif /* ADVENTURER_H_ */
