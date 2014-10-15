/*
 * GameOver.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: Eric
 */

#include "GameOver.h"
#include "TextObject.h"
#include "GraphicsManager.h"
#include "EventKeyboard.h"
#include <cstdlib>

GameOver::GameOver() {
	TextObject gameover;

	gameover.setViewString("Game over.");
	GraphicsManager &gm = GraphicsManager::getInstance();
	IVector pos(gm.getHorizontal()/2, gm.getVertical()/2);
	gameover.setPosition(pos);
}

GameOver::~GameOver() {
	// TODO Auto-generated destructor stub
}

int GameOver::eventHandler(Event* e)
{
	string typeName = e->getType();
	if(typeName == DF_EVENT_KEYBOARD)
	{
		EventKeyboard* ek = static_cast<EventKeyboard*>(e);
		if(ek->getKey() == ' '){
			exit(0);
		}
	}

	return 0;
}
