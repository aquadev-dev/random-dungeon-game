#pragma once
#include "GameState.h"
#include "SceneManager.h"
class DeathState : public GameState // Inherit from GameState
{
public:
	void update() override; // Update the state
	int getStateNum() override; // Get the state number

private:
	SceneManager sceneManager; // Scene manager to handle scenes
};

