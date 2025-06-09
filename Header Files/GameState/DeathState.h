#pragma once
#include "GameState.h"
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Managers/SceneManager.h"
class DeathState : public GameState // Inherit from GameState
{
public:
	void update() override; // Update the state
	int getStateNum() override; // Get the state number

private:
	SceneManager sceneManager; // Scene manager to handle scenes
};

