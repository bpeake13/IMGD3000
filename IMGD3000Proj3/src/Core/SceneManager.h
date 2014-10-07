/*
 * SceneManager.h
 *
 *  Created on: Oct 7, 2014
 *      Author: Benny
 */

#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "Manager.h"
#include "DynamicPtrArray.h"
#include "Scene.h"

/**
 * Class used to manage scenes
 */
class SceneManager : public Manager
{
private:
	SceneManager();
	SceneManager (SceneManager const&);
	SceneManager& operator=(const SceneManager& other);

public:

	/**
	 * Called to startup the scene manager
	 * @return 0 when OK, -1 on fail
	 */
	int startUp();

	/**
	 * Called when the manager is shutdown
	 */
	void shutDown();

	/**
	 * Get the static instance of the scene manager
	 * @return
	 */
	static SceneManager& getInstance();

	/**
	 * Peek at the top scene on the stack
	 * @return
	 */
	static Scene* peek() ;

	/**
	 * Push a scene to the top of the stack
	 * @param scene The scene to push onto the stack
	 * @return True if the scene was able to be pushed, false otherwise
	 */
	static bool push(Scene* scene);

	/**
	 * Pops off the top scene and deletes it
	 * @return True if a scene was able to be popped and killed, false otherwise
	 */
	static bool popKill();

	/**
	 * Pops a scene from the stack
	 * @return The scene that was popped or NULL if no scene was popped
	 */
	static Scene* pop();

private:

	Scene* peekStack() const;

	bool pushStack(Scene* scene);

	Scene* popStack();

	bool popKillStack();

	static SceneManager* instance;

	DynamicPtrArray* stack;
};

#endif /* SCENEMANAGER_H_ */
