/*
 * AttackEvent.cpp
 *
 *  Created on: Oct 8, 2014
 *      Author: Benny
 */

#include "AttackEvent.h"

AttackEvent::AttackEvent(Object* sender, Object* reciever, int damage,
		string damageType)
{
	this->sender = sender;
	this->reciever = reciever;
	this->damage = damage;
	this->damageType = damageType;

	setType(DF_ATTACK_EVENT);
}

Object* AttackEvent::getSender() const
{
	return sender;
}

Object* AttackEvent::getReciver() const
{
	return reciever;
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

void AttackEvent::setSender(Object* sender) {
	this->sender = sender;
}
