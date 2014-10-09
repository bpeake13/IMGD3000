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
#include "Utility.h"

#define DF_ATTACK_EVENT "__attack__"

/**
 * Event sent whenever an attack is issued
 */
class AttackEvent : public Event
{
public:
	/**
	 * Creates a new attack event
	 * @param sender The object who is attacking
	 * @param reciever The object who is being attacked
	 * @param damage The damage to deal
	 * @param damageType THe type of damage to deal
	 */
	AttackEvent(Object* sender, Object* reciever, int damage, string damageType);

	/**
	 * Gets the object attacking
	 * @return The object attacking
	 */
	Object* getSender() const;

	/**
	 * Gets the object being attacked
	 * @return The object being attacked
	 */
	Object* getReciver() const;

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

private:
	Object* sender;
	Object* reciever;
	int damage;
	string damageType;
};

#endif /* ATTACKEVENT_H_ */
