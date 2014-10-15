/*
 * Monster.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: Eric
 */

#include "ResourceManager.h"
#include "Monster.h"

Monster::Monster() : Creature(false) {
	reward = 0;
}

Monster::Monster(string name, int health, int attack, int reward, string desc) : Creature(false) {
	setName(name);
	setHealth(health);
	setAttack(attack);
	setReward(reward);
	setDesc(desc);
}


int Monster::getReward() const {
	return reward;
}

void Monster::setReward(int reward) {
	this->reward = reward;
}

void Monster::setSpr(string name){
	string filename = "mon-" + name + "-spr.txt";

	//Load the sprite
	ResourceManager::getInstance().loadSprite(filename, name);
}
