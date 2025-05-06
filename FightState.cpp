#include "FightState.h"
#include <iostream>

using namespace std;

void FightState::update()
{
	// Implement the logic for the fight state here
	// For example, you might want to display the current fight status or allow the player to make a move
	cout << "Fight State" << endl;
	// Add more fight logic as needed
}

int FightState::getStateNum()
{
	// Return the state number for the fight state
	return 1; 
}