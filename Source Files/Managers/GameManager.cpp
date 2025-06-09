#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Managers/GameManager.h" // Include the GameManager header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Managers/SceneManager.h" // Include the SceneManager header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/GameState/FightState.h" //	Include the FightState header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Observers/PlayerObserver.h" // Include the PlayerObserver header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/GameState/WinState.h" // Include the WinState header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/GameState/DeathState.h" // Include the DeathState header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/GameState/ExploringState.h" // Include the ExploringState header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Managers/GameStateManager.h" // Include the GameStateManager header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Rooms/EmptyRoom.h" // Include the IRoom header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Rooms/UpgradeRoom.h"// Include the UpgradeRoom header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Rooms/MonsterRoom.h" // Include the MonsterRoom header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Rooms/TreasureRoom.h" // Include the TreasureRoom header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Entities/BruisierEnemy.h" // Include the BruisierEnemy header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Entities/DefaultEnemy.h" // Include the DefaultEnemy header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Entities/DefenderEnemy.h" //	Include the DefenderEnemy header file
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Entities/Entity.h" // Include the Entity header file

#include <iostream> // Include the iostream header file	
#include <string> // Include the string header file
#include <vector> // Include the vector header file
#include <fstream> // Include the fstream header file
#include <thread> // Include the thread header file
#include <chrono> // Include the chrono header file

using namespace std;

GameManager::GameManager() // Constructor
{
	// Initialize the game manager
	currentRoomNumber = 0; // Set the current room number to 0
	currentRoomType = 0; // Set the current room type to 0
	currentMonsterType = 0; // Set the current monster type to 0
	attackType = 0; // Set the attack type to 0
	isSuccessful = false; // Set the attack success to false

	// Initialize the room manager
	roomManager.setCurrentRoom(new EmptyRoom()); // Set the current room to an empty room
}

void GameManager::StartStartUpLoop() { // Start the startup loop
	stateManager.change(); // Change the state manager
	// Generate the Dungeon
	dungeon = dungeonGenerator.generateDungeon(); // Generate a 5x5 dungeon

	// Customize Player
	sceneManager.LoadScene(2); // Load the StartMenu scene
	cout << "Welcome to the game!" << endl; // Print welcome message
	cout << "Please enter the name of you monk: "; // Prompt for player name
	cin >> PlayerName; // Get player name

	cout << "Please describe your monk: "; // Prompt for player description
	cin >> PlayerDescription; // Get player description

	// Create the player instance
	player.setPlayerName(PlayerName); // Set the player name
	player.setPlayerDescription(PlayerDescription); // Set the player description

	playerObserver.setPlayerName(PlayerName); // Set the player name in the observer
	player.addObserver(&playerObserver); // Add the observer to the player

	sceneManager.LoadScene(3); // Load the PlayerCreation scene

    this_thread::sleep_for(chrono::seconds(5)); // Sleep for 5 seconds to simulate loading time

	StartExploringLoop(); // Start the exploring loop
}

void GameManager::StartExploringLoop() // Start the exploring loop
{
	while (roomManager.getType() != "treasure")
	{
		// Load the room
		setCurrentRoomType(); // Set the current room type based on the room number
		LoadRoom(currentRoomType); // Load the room based on its type
		
		if (roomManager.getType() == "treasure") { // If the room type is treasure
			stateManager.setState(new WinState()); // Set the state to WinState
			stateManager.change(); // Change the state manager
			EndGame(); // End the game
			break;// Load the Win scene
		}

		if (roomManager.getType() == "monster") { // If the room type is monster
			stateManager.setState(new FightState()); // Set the state to FightState
			stateManager.change(); // Change the state manager
			StartFightingLoop(); // Start the fighting loop
		}
		else {
			PlayerRoomSelectOption(currentRoomType); // Process player options
		}
		
	}
	
}

void GameManager::StartFightingLoop() // Start the fighting loop
{
	
	unique_ptr<Entity> monster; // Create a unique pointer for the monster

	int EnemyHP; // Enemy health points
	int EnemyAP; // Enemy attack points

	int PlayerHP; // Player health points
	int PlayerAP; // Player attack points
	
	switch (currentMonsterType) { // Switch based on the current monster type
	case 0:
		monster = monsterGenerator.generateMonster(0); // Generate a BruisierEnemy
		
		break;
	case 1:
		monster = monsterGenerator.generateMonster(1); // Generate a DefaultEnemy
		
		break;
	case 2:
		monster = monsterGenerator.generateMonster(2); // Generate a DefenderEnemy
		
		break;
	default:
		cout << "Unknown monster type!" << endl; // Print error message
		exit(-1); // Exit the program
		break;
	}

	EnemyHP = monster->getEnemyHP(); // Get the enemy HP
	EnemyAP = monster->getEnemyAttackPoints(); // Get the enemy AP
	monster->addObserver(&enemyHealth); // Add the enemy health observer

	PlayerHP = player.getPlayerHP(); // Get the player HP
	PlayerAP = player.getPlayerAP(); // Get the player AP

	


	while (PlayerHP != 0 && EnemyHP != 0) { // While player and enemy are alive
		// Player's turn
		player.statusChanged(0); // Notify the player status change
		
		PlayerRoomSelectOption(currentRoomType); // Process player options
		
		switch (attackType) // Switch based on the attack type
		{
		case 0: // Attack
			if (isSuccessful) { // If the attack is successful
				EnemyHP -= PlayerAP; // Decrease enemy HP
				monster->setEnemyHP(EnemyHP); // Set the enemy HP
			}
			else { // If the attack is not successful
				cout << "You missed the attack!" << endl; // Print error message
			}
			break;
		case 1: // Guard
			if (isSuccessful) {// If the guard is successful
				if (PlayerHP == player.getPlayerMaxHP()) { // If the player is already at full health
					cout << "You are already at full health!" << endl; // Print message
				}
				else { // If the player is not at full health
					cout << "You are guarding!" << endl; // Print guard message
					PlayerHP += 1; // Increase the player's attack points
					player.setPlayerHP(PlayerHP);
				}

				 // Set the player HP
			}
			else {
				cout << "You didn't gaurd!" << endl; // Print message if guard failed
			}
			break;
		default:
			cout << "Error Performing Player Move!" << endl; // Print error message
			exit(-1); // Exit the program
			break;
		}

		

		// Enemy's turn
		srand(time(0)); // Seed the random number generator
		int enemyOption = rand() % 2; // Randomly select an enemy option
		int enemySuccess = rand() % 2; // Randomly select enemy success

		if (currentMonsterType != 2) { // If the monster type is not DefenderEnemy
			switch (enemyOption) // Switch based on the enemy option
			{
			case 0: // Attack
				if (enemySuccess == 1) { // If the enemy attack is successful
					PlayerHP -= EnemyAP; // Decrease player HP
					player.setPlayerHP(PlayerHP); // Set the player HP
					cout << "The enemy attacks you!" << endl; // Print attack message
				}
				else { // If the enemy attack is not successful
					cout << "The enemy missed the attack!" << endl; // Print if the attack missed
				}
				break;
			case 1: // Gaurd
				// The enemy guards
				if (enemySuccess == 1) { // If the enemy guard is successful
					EnemyHP += 1; // Increase the enemy's attack points
					monster->setEnemyHP(EnemyHP); // Set the enemy HP
					cout << "The enemy is guarding!" << endl; // Print guard message
				}
				else {
					cout << "The enemy didn't gaurd!" << endl; // Print if the guard failed
				}
				break;
			default:
				cout << "Error Performing Enemy Move!" << endl; // Print error message
				exit(-1); // Exit the program
				break;
			}
		}
		else { // If the monster type is DefenderEnemy
			enemyOption = rand() % 100 + 1; // Randomly select an enemy option
			
			if (enemyOption <= 80) {// 80% chance to attack
				enemyOption = 1;// Guard
				cout << "The enemy is guarding!" << endl; // Print guard message
				EnemyHP += 1; // Increase the enemy's attack points
				monster->setEnemyHP(EnemyHP); // Set the enemy HP
			}
			else {
				enemyOption = 0; // Attack
				if (enemySuccess == 1) { // If the enemy attack is successful
					PlayerHP -= EnemyAP; // Decrease player HP
					player.setPlayerHP(PlayerHP); // Set the player HP
				}
				else {
					cout << "The enemy missed the attack!" << endl; // Print if the attack missed
				}
				
			}
		}


		if (PlayerHP <= 0) { // If the player HP is 0
			cout << "You have been defeated!" << endl; // Print defeat message
			player.setPlayerHP(0); // Set the player HP to 0
			stateManager.setState(new DeathState()); // Set the state to DeathState
			stateManager.change(); // Change the state manager
			EndGame(); // End the game
			break;
		}
		else if (EnemyHP <= 0) { // If the enemy HP is 0
			cout << "You have defeated the enemy!" << endl; // Print victory message
			cout << "Moving to Next Room ..." << endl; // Print moving to next room message
			currentRoomNumber++; // Increment the current room number
			player.setPlayerHP(PlayerHP); // Set the player HP
			player.statusChanged(0); // Notify the player status change
			stateManager.setState(new ExploringState()); // Set the state to WinState
			stateManager.change(); // Update the player on state change
			break;
		}
		else {
			cout << "You are still fighting!" << endl; // Print still fighting message
		}
	}

}	
	
	
void GameManager::PlayerMeditate() // Player meditate function
{
	if (player.getPlayerHP() == player.getPlayerMaxHP()) { // If the player is already at full health
		cout << "You are already at full health but decide to meditate anyway" << endl; // Print message
		playerSaveManager.SavePlayerData(player); // Save player data
	}
	else { // If the player is not at full health
		player.setPlayerHP(player.getPlayerMaxHP()); // Set the player HP to max health
		cout << "You meditate and restore your health to full!" << endl; // Print message
		playerSaveManager.SavePlayerData(player); // Save player data
	}
}

void GameManager::EndGame() // End game function
{
	cout << "Game ended!" << endl; // Print end game message
	exit(0); // Exit the program
}

void GameManager::LoadRoom(int roomType)
{
	// Load the room based on its type
	
	switch (currentRoomType) {
	case 0: // Empty room
		roomManager.setCurrentRoom(new EmptyRoom()); // Set the current room to an empty room
		roomManager.printScene(); // Load the empty room scene
		break;
	case 1: // Upgrade room
		roomManager.setCurrentRoom(new UpgradeRoom()); // Set the current room to an upgrade room
		roomManager.printScene();// Load the upgrade room scene
		break;
	case 2: // Monster room
		LoadMonsterRoom(); // Load the monster room
		break;
	case 3: // Treasure room
		roomManager.setCurrentRoom(new TreasureRoom()); // Set the current room to a treasure room
		roomManager.printScene(); // Load the treasure room scene
		// Load the treasure room scene
		break;
	default:
		cout << "Unknown room type!" << endl; // Print error message
		exit(-1); // Exit the program
	}
}

void GameManager::LoadMonsterRoom() // Load monster room function
{
	// Load a monster room
	
	cout << "Loading monster room..." << endl; // Print loading message

	roomManager.setCurrentRoom(new MonsterRoom()); // Set the current room to a monster room

	IRoom* currentRoom = roomManager.getCurrentRoom(); // Get the current room
	
	MonsterRoom* monsterRoom = dynamic_cast<MonsterRoom*>(currentRoom); // Cast the current room to a MonsterRoom

	monsterRoom->generateMonster(); // Generate a random monster
	currentMonsterType = monsterRoom->getMonsterType(); // Get the monster type
	monsterRoom->printScene(); // Load the monster room scene
}



void GameManager::setCurrentRoomType()
{
	// Set the current room type based on the room number
	if (dungeon[currentRoomNumber] == "treasure") { // If the room type is treasure
		currentRoomType = 3; // Treasure room
	}
	else if (dungeon[currentRoomNumber] == "monster") { // If the room type is monster
		currentRoomType = 2; // monster room
	}
	else if (dungeon[currentRoomNumber] == "empty") { // If the room type is empty
		currentRoomType = 0; // Empty room
	}
	else if (dungeon[currentRoomNumber] == "upgrade") { // If the room type is upgrade
		currentRoomType = 1; // Upgrade room
	}
	else { // If the room type is unknown
		cout << "Unknown room type!" << endl; // Print error message
		exit(-1); // Exit the program
	}
}

void GameManager::PlayerRoomSelectOption(int roomType) // Player room select option function
{
	// Implement the logic to calculate player options

	int selectedOption = 0; // Initialize selectedOption to 0
	



	// Initialize selectedOption to 0

	switch (roomType) // Switch based on the room type
	{
	case 0: // Empty room
		cout << "You are in an empty room. Your options are as follows." << endl; // Print room message
		cout << "1. Meditate" << endl; // Print meditate option
		cout << "2. Leave To the next room" << endl; // Print leave to next room option
		if (currentRoomNumber == 0) {// If the current room number is 0
			cout << "You are at the first room. You cannot go back." << endl; // Print this message
		}
		else { // If the current room number is not 0
			cout << "3. Leave to the previos room, roomType: " + dungeon[currentRoomNumber - 1] << endl; // Print leave to previous room option
		}
		selectedOption = roomManager.processOption(); // Process the selected option
		break;
	case 1: // Upgrade room
		cout << "You are in an upgrade room. You can upgrade your skills or leave." << endl; // Print room message
		cout << "1. Upgrade Attack" << endl; // Print upgrade attack option
		cout << "2. Upgrade Max Health" << endl; // Print upgrade max health option
		cout << "3. Leave to the next room" << endl; // Print leave to next room option

		if (currentRoomNumber == 0) { // If the current room number is 0
			cout << "4. Leave to the previos room, roomType: " + dungeon[0] << endl; // Print this message
		}
		else { // If the current room number is not 0
			cout << "4. Leave to the previos room, roomType: " + dungeon[currentRoomNumber - 1] << endl; // Print leave to previous room option
		}
		selectedOption = roomManager.processOption(); // Process the selected option
		break;
	case 2: // Monster room
		cout << "You are in a monster room. You can fight or gaurd." << endl; // Print room message
		cout << "1. Attack" << endl; // Print attack option
		cout << "2. Gaurd" << endl; // Print guard option
		selectedOption = roomManager.processOption(); // Process the selected option
		break;
	default:
		cout << "Unknown room type!" << endl; // Print error message
		exit(-1); // Exit the program
		break;
	}

	PlayerRoomProcessOption(roomType, selectedOption); // Process player options
}

void GameManager::PlayerRoomProcessOption(int roomType, int selectedOption) // Player room process option function
{
	// Implement the logic to process player options
	switch (roomType) {
	case 0: { // Empty room
		switch (selectedOption) // Switch based on the selected option
		{
		case 1: // Meditate
			PlayerMeditate();
			 // clean up memory
			PlayerRoomSelectOption(0);
			
			break;
		case 2: // Move to Next room
			 // clean up memory
			currentRoomNumber++; // Increment the current room number
			cout << "Moving to the next room ..." << endl; // Print moving to next room message
			
			break;
		case 3: // Move to Previous room
			
			if (currentRoomNumber == 0) { // If the current room number is 0
				cout << "You walk into a wall realizing your exit is blocked." << endl; // Print this message
				// clean up memory
				PlayerRoomSelectOption(0); // Process player options
			}
			else { // If the current room number is not 0
				currentRoomNumber--; // Decrement the current room number
				cout << "You moved to the previous room roomType: " << dungeon[currentRoomNumber] << endl; // Print room type message
			}
			break;
		default:
			cout << "Invalid option!" << endl; // Print error message
			exit(-1); // Exit the program
			break;
		}
		break;
	}


	case 1: { // Upgrade room
		switch (selectedOption) // Switch based on the selected option
		{// Upgrade room
		case 1: // Upgrade Attack
			player.setPlayerAP(player.getPlayerAP() + 2); // Increase player attack points
			cout << "You upgraded your attack!" << endl; // Print upgrade message
			 // clean up memory
			PlayerRoomSelectOption(1); // Process player options
			
			break;
		case 2: // Upgrade Max Health
			player.setPlayerMaxHP(player.getPlayerMaxHP() + 5);// Increase player max health
			player.setPlayerHP(player.getPlayerMaxHP()); // Set player HP to max health
			cout << "You upgraded your max health!" << endl; // Print upgrade message
			 // clean up memory
			PlayerRoomSelectOption(1); // Process player options
			
			break;
		case 3: // Move to Next room
			 // clean up memory
			currentRoomNumber++; // Increment the current room number
			cout << "Moving to the next room ..." << endl; // Print moving to next room message
			
			break;
		case 4: // Move to Previous room
			 // clean up memory
			currentRoomNumber--; // Decrement the current room number
			cout << "You moved to the previous room, roomType: " << dungeon[currentRoomNumber] << endl; // Print room type message
			break;
		default:
			cout << "Invalid option!" << endl; // Print error message
			exit(-1); // Exit the program
			break;
		}
		break;
	}
	case 2: { // Monster room
		switch (selectedOption) // Switch based on the selected option Monster room
		{
		case 1: {
			// Attack
			srand(time(0)); // Seed the random number generator

			int attackSuccess = rand() % 2; // Randomly select attack success

			if (attackSuccess == 1) { // If the attack is successful
				// Attack the monster
				cout << "You attack the monster!" << endl; // Print attack message
				isSuccessful = true; // Set attack success to true
			}
			else {
				cout << "Your attack missed!" << endl; // Print if the attack missed
				isSuccessful = false; // Set attack success to false
			}
			attackType = 0; // Set attack type to 0 (attack)
			
			break;
		} 
			
		case 2: {
			// Gaurd
			srand(time(0)); // Seed the random number generator

			int guardSuccess = rand() % 2; // Randomly select guard success

			if (guardSuccess == 1) { // If the guard is successful
				// Guard against the monster's attack
				cout << "You guard against the monster's attack!" << endl; // Print guard message
				isSuccessful = true; // Set guard success to true
			}
			else {
				cout << "Your guard failed!" << endl; // Print if the guard failed
				isSuccessful = false; // Set guard success to false
			}
			attackType = 1; // Set attack type to 1 (guard)
			 // clean up memory
			break;
		}
		default:
			cout << "Invalid option!" << endl; // Print error message
			exit(-1); // Exit the program
			break;
		}
		break;
	}

	default:
		cout << "Unknown room type!" << endl; // Print error message
		exit(-1); // Exit the program
		break;
	}
}

SceneManager GameManager::getSceneManager() // Get the scene manager
{
	return sceneManager; // Return the scene manager
}





