#include "GameStateManager.h"
#include <iostream>

using namespace std;

void GameStateManager::setState(GameState* newState) { // Set the new state
	delete state; // Clean up the old state
	state = newState; // Set the new state
}

void GameStateManager::change() { // Change the state
	state->update(); // Update the current state
}

int GameStateManager::getStateNumber() { // Get the state number
	return state->getStateNum(); // Return the state number
}