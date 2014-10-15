/*
 * GameWin.h
 *
 *  Created on: Oct 15, 2014
 *      Author: Eric
 */

#ifndef GAMEWIN_H_
#define GAMEWIN_H_

#include "Scene.h"
#include "Event.h"

class GameWin: public Scene {
public:
	GameWin();
	virtual ~GameWin();
	int eventHandler(Event *e);
};

#endif /* GAMEWIN_H_ */
