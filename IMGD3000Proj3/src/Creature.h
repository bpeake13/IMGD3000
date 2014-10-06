/*
 * Creature.h
 *
 *  Created on: Oct 5, 2014
 *      Author: Eric
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include "Object.h"
#include "SpriteObject.h"

class Creature: public Object {
private:
	int health; //How much damage the creature needs to take to be destroyed
	int attack; //The creature's attack value
	SpriteObject spr;

public:
	Creature();
	virtual ~Creature();
	int getAttack() const;
	void setAttack(int attack);
	int getHealth() const;
	void setHealth(int health);
	const SpriteObject& getSpr() const;
	void setSpr(const SpriteObject& spr);
};

#endif /* CREATURE_H_ */
