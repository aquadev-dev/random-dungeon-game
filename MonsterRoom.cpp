#include "MonsterRoom.h"
#include "SceneManager.h"
#include <iostream>

string MonsterRoom::getType() // This function returns the type of the room
{
	return "monster"; // This is a monster room
}

void MonsterRoom::printScene() // This function prints the scene of the room
{
	printMonsterRoom(monsterType); // This function prints the monster room based on the monster type
}

void MonsterRoom::printMonsterRoom(int monsterType) // This function prints the monster room based on the monster type
{
	SceneManager sceneManager; // Create an instance of SceneManager
	switch (monsterType) // Switch case to determine the monster type
	{
	case 0:
		sceneManager.LoadScene(6); // Load the scene for the default monster
		break;
	case 1:
		sceneManager.LoadScene(7); // Load the scene for the bruiser monster
		break;
	case 2:
		sceneManager.LoadScene(8); // Load the scene for the defender monster
		break;
	default:
		cout << "Unknown monster type!" << endl; // Handle unknown monster type
		break;
	}
}

void MonsterRoom::generateMonster() // This function generates a random monster type
{
	srand(time(0)); // Seed the random number generator with the current time

	// Generate a random monster type
	monsterType = rand() % 100 + 1; // Random number between 1 and 100

	if (monsterType <= 50)
	{
		monsterType = 0; // Default monster
	}
	else if (monsterType >= 51 || monsterType <= 75)
	{
		monsterType = 1; // Bruiser monster
	}
	else
	{
		monsterType = 2; // Defender monster
	}
}

int MonsterRoom::getMonsterType() // This function returns the monster type
{
	return monsterType; // Return the monster type
}

int MonsterRoom::processOption() // This function processes the player's option
{
	cin >> selectedOption; // Get the player's option

	switch (selectedOption) // Switch case to determine the player's option
	{
	case 1: // Attack
		return selectedOption;
		break;
	case 2: // Defend
		return selectedOption;
		break;
	default: // Invalid option
		cout << "Invalid option. Please try again." << endl;
		return processOption();
		break;
	}
	
}
