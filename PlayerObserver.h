#pragma once
#include <string>
#include <iostream>
#include "Observer.h"

using namespace std;
class PlayerObserver : public Observer // PlayerObserver for observing player status updates
{
public:
	PlayerObserver(const string& playerName) : playerName(playerName) {} // Constructor initializes the player name
	void update(const string& playerStatus) override // Update method to handle player status updates
	{
		cout << playerName << "'s status updated: " << playerStatus << endl; // Print the player's status
	}

	void setPlayerName(const string& name) // Set the player's name
	{
		playerName = name; // Update the player name
	}
private:
	string playerName; // Name of the player
};

