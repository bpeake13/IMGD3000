/*
 * GameWin.cpp
 *
 *  Created on: Oct 15, 2014
 *      Author: Eric
 */

#include "GameWin.h"
#include "GraphicsManager.h"
#include "TextObject.h"
#include "EventKeyboard.h"
#include <cstdlib>

GameWin::GameWin() {
	TextObject gameover;

	gameover.setViewString("You won!");
	GraphicsManager &gm = GraphicsManager::getInstance();
	IVector pos(gm.getHorizontal()/2, gm.getVertical()/2);
	gameover.setPosition(pos);
}

GameWin::~GameWin() {

}

int GameWin::eventHandler(Event* e)
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
