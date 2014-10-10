/*
 * AttackEvent.h
 *
 *  Created on: Oct 8, 2014
 *      Author: Benny
 */

#ifndef ATTACKEVENT_H_
#define ATTACKEVENT_H_

#include "Event.h"
#include "Object.h"
#include "Creature.h"
#include "Utility.h"

#define DF_ATTACK_EVENT "__attack__"

class Creature;

/**
 * Event sent whenever an attack is issued
 */
class AttackEvent : public Event
{
public:

	/**
	 * Creates a new empty attack event
	 */
	AttackEvent();

	/**
	 * Creates a new attack event aimed at a creature
	 * @param receiver The creature getting attacked
	 */
	AttackEvent(Creature* receiver);

	/**
	 * Creates a new attack event
	 * @param sender The object who is attacking
	 * @param reciever The object who is being attacked
	 * @param damage The damage to deal
	 * @param damageType The type of damage to deal
	 */
	AttackEvent(Creature* sender, Creature* receiver, int damage, string damageType);

	/**
	 * Gets the object attacking
	 * @return The object attacking
	 */
	Creature* getSender() const;

	/**
	 * Gets the object being attacked
	 * @return The object being attacked
	 */
	Creature* getReceiver() const;

	/**
	 * Gets the damage of the attack
	 * @return THe damage of the attack
	 */
	int getDamage() const;

	/**
	 * Gets the damage type of the attack
	 * @return The damage type of the attack
	 */
	string getDamageType() const;

	/**
	 * Sets the damage to be dealt by the attack
	 * @param damage The amount of damage
	 */
	void setDamage(int damage);

	/**
	 * Sets the type of the damage of the attack
	 * @param damageType The damage type of the attack
	 */
	void setDamageType(const string& damageType);

	/**
	 * Sets the object attacking
	 * @param sender The object that is attacking
	 */
	void setSender(Creature* sender);

private:
	Creature* sender;
	Creature* receiver;
	int damage;
	string damageType;
};

#endif /* ATTACKEVENT_H_ */
