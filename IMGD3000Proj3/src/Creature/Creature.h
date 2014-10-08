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
	int attack; //The creature's attack value, physical
	SpriteObject spr; //The creatures sprite object
	string name; //Name of the creature
	string desc; //Description for the creature

public:
	Creature();
	Creature(string name, int health, int attack, string desc);
	virtual ~Creature();
	int getAttack() const;
	void setAttack(int attack);
	int getHealth() const;
	void setHealth(int health);
	const SpriteObject& getSpr() const;
	void setSpr(string name);
	const string& getDesc() const;
	void setDesc(const string& desc);
	const string& getName() const;
	void setName(const string& name);
};

#endif /* CREATURE_H_ */
