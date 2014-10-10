/*
 * AttackEvent.cpp
 *
 *  Created on: Oct 8, 2014
 *      Author: Benny
 */

#include "AttackEvent.h"

AttackEvent::AttackEvent(){
	setType(DF_ATTACK_EVENT);
}
AttackEvent::AttackEvent(Creature* receiver){
	this->receiver = receiver;
	setType(DF_ATTACK_EVENT);
}
AttackEvent::AttackEvent(Creature* sender, Creature* receiver, int damage,
		string damageType)
{
	this->sender = sender;
	this->receiver = receiver;
	this->damage = damage;
	this->damageType = damageType;

	setType(DF_ATTACK_EVENT);
}

Creature* AttackEvent::getSender() const
{
	return sender;
}

Creature* AttackEvent::getReceiver() const
{
	return receiver;
}

int AttackEvent::getDamage() const
{
	return damage;
}

string AttackEvent::getDamageType() const
{
	return damageType;
}

void AttackEvent::setDamage(int damage) {
	this->damage = damage;
}

void AttackEvent::setDamageType(const string& damageType) {
	this->damageType = damageType;
}

void AttackEvent::setSender(Creature* sender) {
	this->sender = sender;
}
