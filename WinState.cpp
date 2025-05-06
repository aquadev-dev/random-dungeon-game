#include "WinState.h"
#include <iostream>

using namespace std;

void WinState::update()
{
	// Implement the logic for the win state here
	// For example, you might want to display a victory message or allow the player to exit the game
	cout << "Win State!" << endl;
	// Add more win logic as needed
}

int WinState::getStateNum()
{
	// Return the state number for the win state
	return 3; // Assuming 4 is the state number for the win state
}