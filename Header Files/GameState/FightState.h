#pragma once
#include "GameState.h"

class FightState : public GameState // Inherit from GameState
{
public:
	void update() override; // Update the state
	int getStateNum() override; // Get the state number
	
};

