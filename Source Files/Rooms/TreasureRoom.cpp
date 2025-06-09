#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Rooms/TreasureRoom.h"
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Managers/SceneManager.h"

string TreasureRoom::getType() // Returns the type of room
{
	return "treasure"; // The treasure room is a special type of room
}

void TreasureRoom::printScene() // Prints the scene
{
	SceneManager sceneManager; // Creates a scene manager object
	sceneManager.LoadScene(11); // Loads the treasure room scene
}

int TreasureRoom::processOption() // Processes the option chosen by the player
{
	// Does nothing because the treasure room is the win condition
	return 0;
}