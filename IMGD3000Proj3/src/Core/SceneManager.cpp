/*
 * SceneManager.cpp
 *
 *  Created on: Oct 7, 2014
 *      Author: Benny
 */

#include "SceneManager.h"

SceneManager* SceneManager::instance = NULL;

SceneManager::SceneManager()
{
	stack = NULL;
}

SceneManager::SceneManager(const SceneManager&)
{
	stack = NULL;
}

SceneManager& SceneManager::operator =(const SceneManager& other)
{
	return *this;
}

int SceneManager::startUp()
{
	stack = new DynamicPtrArray(8);
}

void SceneManager::shutDown()
{
	int stackSize = stack->getSize();
	for(int i = 0; i < stackSize; i++)
	{
		delete static_cast<Scene*>(stack->get(i));
	}

	stack->clear();

	delete stack;
}

SceneManager& SceneManager::getInstance()
{
	if(!instance)
		instance = new SceneManager();

	return *instance;
}

Scene* SceneManager::peek()
{
	return instance->peekStack();
}

bool SceneManager::push(Scene* scene)
{
	return instance->pushStack(scene);
}

Scene* SceneManager::pop()
{
	return instance->popStack();
}

Scene* SceneManager::peekStack() const
{
	size_t stackSize = stack->getSize();
	if(stackSize == 0)
		return NULL;

	return static_cast<Scene*>(stack->get(stackSize - 1));
}

bool SceneManager::pushStack(Scene* scene)
{
	return stack->add(scene);
}

Scene* SceneManager::popStack()
{
	size_t size = stack->getSize();
	if(size == 0)
		return NULL;

	Scene* s = static_cast<Scene*>(stack->get(size - 1));
	stack->remove(size - 1);
	return s;
}
