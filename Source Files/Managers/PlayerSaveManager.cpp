#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Managers/PlayerSaveManager.h"
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Entities/Player.h"
#include <iostream>
#include <fstream>

using namespace std;

void PlayerSaveManager::SavePlayerData(const Player& player) { // Save player data to a file
	ofstream outFile("/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Saves/" + player.getPlayerName() + ".txt"); // Open the file for writing
	if (outFile.is_open()) { // Check if the file is open
		outFile << "Player Name: " << player.getPlayerName() << endl; // Write player name
		outFile << "Player Description: " << player.getPlayerDescription() << endl; // Write player description
		outFile << "Player Health: " << player.getPlayerHP() << endl; // Write player health
		outFile << "Player Attack Points: " << player.getPlayerAP() << endl; // Write player attack points
		outFile.close(); // Close the file
		cout << "Player data saved successfully!" << endl; // Success message
	}
	else { // If the file could not be opened
		cout << "Error opening file for saving player data." << endl; // Error message
	}
}