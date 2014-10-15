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
protected:
	int health;
	int maxhealth;
	int attack;
	string name;
	string desc;

public:

	/**
	 * Whether or not to add the creature to the world
	 * @param addToWorld True or false whether to add to the world
	 */
	Creature(bool addToWorld=true);
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
	 * Does an attack and gets the damage done
	 */
	virtual int doAttack();

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
	 * Returns the maximum health of the creature
	 * @return The maximum health
	 */
	int getMaxHealth() const;

	/**
	 * This function sets the max health of the creature
	 * @param newmax The new max health to set
	 */
	void setMaxHealth(int newmax);
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

	/**
	 * Damages a creature by some amount
	 * @param damage The amount of damage to cause
	 */
	virtual void damage(int damage);

	/**
	 * Returns whether the creature is dead or not
	 * @return True if dead, false otherwise
	 */
	bool isDead();
};

#endif /* CREATURE_H_ */
