#pragma once
#include "GameState.h"
class ExploringState : public GameState // Inherit from GameState
{
public:
	void update() override; // Update the state
	int getStateNum() override; // Get the state number
};

