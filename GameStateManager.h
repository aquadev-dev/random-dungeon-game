#pragma once
#include "GameState.h"
#include "ExploringState.h"
class GameStateManager // GameStateManager for managing the player's state
{
private:
	GameState* state; // Pointer to the current state

public:
	GameStateManager() : state(new ExploringState()) {}; // Constructor initializes the state to ExploringState

	void setState(GameState* newState); // Sets the current state to a new state

	void change(); // Changes the state based on the current state

	int getStateNumber(); // Returns the state number of the current state

};