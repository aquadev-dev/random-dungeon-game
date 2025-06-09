#pragma once
#include "Entity.h"
#include <vector>

using namespace std;

class Player : public Entity
{
public:
	static Player& instance() // Singleton pattern to ensure only one instance of Player exists
	{
		static Player localInstance; // Create a static instance of Player
		return localInstance; // Return the instance
	}

	void setPlayerHP(int hp); // Sets the player's health points
	int getPlayerHP() const; // Gets the player's health points
	void setPlayerMaxHP(int maxHP); // Sets the player's maximum health points
	int getPlayerMaxHP() const; // Gets the player's maximum health points
	void setPlayerAP(int ap); // Sets the player's attack points
	int getPlayerAP() const; // Gets the player's attack points

	// Entity-specific methods
	void setEnemyHP(int hp) override; // Sets the enemy's health points
	int getEnemyHP() const override; // Gets the enemy's health points
	int getEnemyAttackPoints() const override; // Gets the enemy's attack points

	// Player-specific methods
	

	void setPlayerName(const string& name); // Sets the player's name
	string getPlayerName() const; // Gets the player's name
	void setPlayerDescription(const string& description); // Sets the player's description
	string getPlayerDescription() const; // Gets the player's description

	void addObserver(Observer* observer) override; // Adds an observer to the list of observers
	void removeObserver(Observer* observer) override; // Removes an observer from the list of observers
	void notifyObservers() override; // Notifies all observers of a change in state
	void statusChanged(int status) override; // Updates the status of the player and notifies observers

private:
	Player() {}; // Private constructor for singleton pattern
	Player(const Player&) = delete; // Delete copy constructor
	Player& operator=(const Player&) = delete; // Delete assignment operator

	int playerHP = 15; // Player health points
	int playerMaxHP = 15; // Player maximum health points
	int playerAP = 3; // Player attack points

	

	string playerName; // Player name
	string playerDescription; // Player description

	string playerStatus; // Player status
	vector<Observer*> observers; // Vector of observers
	
};

