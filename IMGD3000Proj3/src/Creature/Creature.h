/*
 * Creature.h
 *
 *  Created on: Oct 5, 2014
 *      Author: Eric
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include "SpriteObject.h"
#include "AttackEvent.h"

class AttackEvent;

class Creature: public SpriteObject {
private:
	/**
	 * The amount of damage a creature can take before it is destroyed
	 */
	int health;
	/**
	 * The creatures attack value
	 */
	int attack;
	/**
	 * The name of the creature
	 */
	string name;
	/**
	 * A description of the creature
	 */
	string desc;

public:
	/**
	 * Constructor for creature
	 */
	Creature();

	/**
	 * Constructor for creature
	 * @param name The name of the creature, as a string
	 * @param health The health of the creature, as an int
	 * @param attack The attack of the creature, as an int
	 * @param desc A description of the creature, as a string
	 */
	Creature(string name, int health, int attack, string desc);

	/**
	 * Destructor for creature
	 */
	virtual ~Creature();

	/**
	 * Getter for the physical attack value of a creature
	 * @return the attack variable
	 */
	int getAttack() const;

	/**
	 * Fills an attackEvent with the needed information
	 * @param e The AttackEvent to fill
	 */
	void getAttack(AttackEvent *e);

	/**
	 * Setter for attack value
	 * @param attack
	 */
	void setAttack(int attack);

	/**
	 * Getter for health of creature
	 * @return
	 */
	int getHealth() const;

	/**
	 * Setter for health of creature
	 * @param health
	 */
	void setHealth(int health);

	/**
	 * Returns the description of the creature
	 * @return the description, as a string
	 */
	const string getDesc() const;

	/**
	 * Setter for description
	 * @param desc the description as a string
	 */
	void setDesc(string desc);

	/**
	 * Returns the name of the creature, as a string
	 * @return the name as a string
	 */
	const string getName() const;

	/**
	 * Setter for name, takes a string
	 * @param name the name of the creature, as a string
	 */
	void setName(string name);
};

#endif /* CREATURE_H_ */
