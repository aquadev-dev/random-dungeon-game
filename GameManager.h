#pragma once

#include <vector> // Include vector for using vectors
#include "SceneManager.h" // Include SceneManager for managing scenes
#include "GameStateManager.h" // Include GameStateManager for managing game states
#include "IRoom.h" // Include IRoom for room interface
#include "DungeonGenerator.h" // Include DungeonGenerator for generating dungeons
#include "Player.h" // Include Player for player-related functionalities
#include "PlayerObserver.h" // Include PlayerObserver for observing player actions
#include "PlayerSaveManager.h" //Include PlayerSaveManager for saving player data
#include "RoomManager.h" // Include RoomManager for managing the players current room
#include "EnemyFactory.h" // Include EnemyFactory for creating enemies
#include "MonsterGenerator.h" // Include MonsterGenerator for generating monsters
#include "EnemyHealthObserver.h" // Include EnemyHealthObserver for observing enemy health

using namespace std;


class GameManager // Class to manage the game flow and interactions
{
private:
	DungeonGenerator dungeonGenerator; // Object to generate dungeons
	GameStateManager stateManager; // Object to manage game states
	SceneManager sceneManager; // Object to manage scenes
	RoomManager roomManager; // Object to manage the current room
	PlayerSaveManager playerSaveManager; // Object to save player data
	int currentRoomNumber; // Current room number
	int currentRoomType; // Current room type
	int currentMonsterType; // Current monster type
	int attackType; // Type of attack
	bool isSuccessful; // Flag to check if the attack was successful
	vector<string> dungeon; // Vector to store the generated dungeon
	Player& player = Player::instance(); // Singleton instance of Player
	string PlayerName = player.getPlayerName(); // Player's name
	string EnemyName = "default"; // Default enemy name
	string PlayerDescription = player.getPlayerDescription(); // Player's description
	PlayerObserver playerObserver = PlayerObserver(PlayerName); // Observer for player actions
	EnemyHealthObserver enemyHealth = EnemyHealthObserver(EnemyName); // Observer for enemy health
	MonsterGenerator monsterGenerator; // Object to generate monsters
public:
	GameManager(); // Constructor

	void StartStartUpLoop(); // Function to start the startup loop
	void StartExploringLoop(); // Function to start the exploring loop
	void StartFightingLoop(); // Function to start the fighting loop
	void EndGame(); // Function to end the game
	

	//RoomLoading
	void setCurrentRoomType(); // Function to set the current room type
	
	
	void LoadRoom(int roomType); // Function to load a room based on the type
	void LoadMonsterRoom(); // Function to load a monster room

	void PlayerMeditate(); // Function for player to meditate
	void PlayerRoomSelectOption(int roomType); // Function to select an option in the room
	void PlayerRoomProcessOption(int roomType, int selcetedOption); // Function to process the selected option in the room

	SceneManager getSceneManager(); // Function to get the scene manager

	


};

