/*
 * Monster.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: Eric
 */

#include "GraphicsManager.h"
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

void Monster::draw(){
	SpriteObject::draw();
	GraphicsManager &gm = GraphicsManager::getInstance();
	IVector thispos = IVector(this->getPosition().getX(), this->getPosition().getY() -2);

	std::stringstream sstm;
	sstm << "HP " << this->getHealth();
	string hp = sstm.str();
	gm.drawString(thispos, LEFT_JUSTIFIED, hp, COLOR_RED);

	IVector nvector(gm.getHorizontal()/2, 5);
	gm.drawString(nvector, CENTER_JUSTIFIED, name, COLOR_WHITE);
	IVector dvector(gm.getHorizontal()/2, 7);
	gm.drawString(dvector, CENTER_JUSTIFIED, desc, COLOR_WHITE);
}
