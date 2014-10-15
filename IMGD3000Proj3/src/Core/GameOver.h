/*
 * GameOver.h
 *
 *  Created on: Oct 15, 2014
 *      Author: Eric
 */

#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include "Scene.h"
#include "Event.h"

class GameOver: public Scene {
public:
	GameOver();
	virtual ~GameOver();
	int eventHandler(Event *e);
};

#endif /* GAMEOVER_H_ */
