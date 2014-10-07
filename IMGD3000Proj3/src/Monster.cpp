/*
 * Monster.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: Eric
 */

#include "Monster.h"

Monster::Monster() {
	// TODO Auto-generated constructor stub

}

Monster::~Monster() {
	// TODO Auto-generated destructor stub
}

/**
 * Getter for reward
 * @return
 */
int Monster::getReward() const {
	return reward;
}

/**
 * Setter for reward
 * @param reward
 */
void Monster::setReward(int reward) {
	this->reward = reward;
}

/**
 * This function chooses a living adventurer and attacks them
 */
void Monster::attackPlayer() {
}
