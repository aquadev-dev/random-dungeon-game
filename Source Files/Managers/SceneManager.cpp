#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Managers/SceneManager.h"
#include <iostream>
#include <fstream>
#include <string>

SceneManager::SceneManager()
{
	// Constructor implementation
}

SceneManager::~SceneManager()
{
	// Destructor implementation
}

void SceneManager::LoadScene(int sceneNumber) // Load a scene based on the scene number
{
	string sceneFileName = "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Scenes/";	//Declare a string variable to hold the name of the scene file.
	// Load the scene from the file
	
	switch (sceneNumber) { // Switch statement to determine which scene to load
	case 1: // Splash Screen
		sceneFileName += "SplashScreen.txt";
		break;
	case 2: // Start Menu
		sceneFileName += "StartMenu.txt";
		break;
	case 3: // Starting Cutscene
		sceneFileName += "StartingCutscene.txt";
		break;
	case 4: // Empty Room
		sceneFileName += "EmptyRoom.txt";
		break;
	case 5: // Upgrade Room
		sceneFileName += "UpgradeRoom.txt";
		break;
	case 6: // Monster Room 1
		sceneFileName += "Monster1.txt";
		break;
	case 7: // Monster Room 2
		sceneFileName += "Monster2.txt";
		break;
	case 8: // Monster Room 3
		sceneFileName += "Monster3.txt";
		break;
	case 9: // Monster Death
		sceneFileName += "MonsterDeath.txt";
		break;
	case 10: // Player Death
		sceneFileName += "PlayerDeath.txt";
		break;
	case 11: // Treasure Room
		sceneFileName += "TreasureRoom.txt";
		break;
	default: // Invalid scene number
		cout << "Invalid scene number." << endl;
		return; // Exit the function if the scene number is invalid
	}


	fstream file(sceneFileName); //fstream represents the file stream (both ofstream and ifstream capabilities).

	if (file.is_open()) { // Check if the file is open
		cout << file.rdbuf();	//rdbuf() is currently associated stream buffer.
		file.close(); // Close the file
	}
	else { // If the file could not be opened
		cout << "Error - File cannot be opened"; // Error message
	}
}