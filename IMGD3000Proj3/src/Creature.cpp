/*
 * Creature.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: Eric
 */

#include "Creature.h"

Creature::Creature() {
	// TODO Auto-generated constructor stub

}

Creature::~Creature() {
	// TODO Auto-generated destructor stub
}

/**
 * Getter for attack
 * @return
 */
int Creature::getAttack() const {
	return attack;
}

/**
 * Setter for attack
 * @param attack
 */
void Creature::setAttack(int attack) {
	this->attack = attack;
}

/**
 * Getter for health
 * @return
 */
int Creature::getHealth() const {
	return health;
}

/**
 * Setter for health
 * @param health
 */
void Creature::setHealth(int health) {
	this->health = health;
}

/**
 * Getter for sprite
 * @return
 */
const SpriteObject& Creature::getSpr() const {
	return spr;
}

/**
 * Setter for sprite
 * @param spr
 */
void Creature::setSpr(const SpriteObject& spr) {
	this->spr = spr;
}
