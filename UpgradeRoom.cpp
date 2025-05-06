#include "UpgradeRoom.h"
#include "SceneManager.h"

string UpgradeRoom::getType() // Returns the type of room
{
	return "upgrade"; // The upgrade room is a special type of room
}
void UpgradeRoom::printScene() // Prints the scene
{
	SceneManager sceneManager; // Creates a scene manager object
	sceneManager.LoadScene(5); // Loads the upgrade room scene
}

int UpgradeRoom::processOption() // Processes the option chosen by the player
{
	cin >> selectedOption; // Gets the option chosen by the player

	switch (selectedOption) // Switches on the option chosen by the player
	{
	case 1: // Upgrade Attack
		return selectedOption;
		break;
	case 2: // Upgrade Max Health
		return selectedOption;
		break;
	case 3: // Move to Next room
		return selectedOption;
		break;
	case 4: // Move to Previous room
		return selectedOption;
		break;
	default: // Invalid option
		cout << "Invalid option. Please try again." << endl; // Prints invalid option message
		return processOption(); // Calls the process option function again
		break;
	}
}