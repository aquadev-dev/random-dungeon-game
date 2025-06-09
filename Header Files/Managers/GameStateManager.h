#pragma once
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/GameState/GameState.h"
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/GameState/ExploringState.h"
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