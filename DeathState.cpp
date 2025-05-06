#include "DeathState.h"
#include <iostream>

using namespace std;

void DeathState::update()
{
	// Implement the logic for the death state here
	// For example, you might want to display a game over message or allow the player to restart
	cout << "Death State." << endl;
	sceneManager.LoadScene(10);
	// Add more death logic as needed
}

int DeathState::getStateNum()
{
	// Return the state number for the death state
	return 2; // Assuming 3 is the state number for the death state
}