#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Entities/Player.h"
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Observers/Observer.h"
#include <iostream>

void Player::addObserver(Observer* observer) // Add an observer to the list
{
	observers.push_back(observer); // Add the observer to the list
}

void Player::removeObserver(Observer* observer) // Remove an observer from the list
{
	observers.erase(remove(observers.begin(), observers.end(), observer), observers.end()); // Remove the observer from the list
}

void Player::notifyObservers() // Notify all observers of the change
{
	for (Observer* observer : observers) // Iterate through all observers
	{
		observer->update(playerStatus); // Notify each observer with the current health status
	}
}
void Player::statusChanged(int status) // Notify observers of a status change
{
	// 0 = health, 1 = attack points, 2 = maxHP
	switch (status)
	{
	case 0: // Player updating health
		playerStatus = "Player HP is now " + to_string(playerHP);
		break;
	case 1: // Player updating attack points
		playerStatus = "Player AP is now " + to_string(playerAP);
		break;
	case 2: // Player is updating maxHP
		playerStatus = "Player maxHP is now " + to_string(playerMaxHP);
		break;
	default:
		break;
	}
	notifyObservers(); // Notify observers of the change
}

void Player::setPlayerHP(int hp) // Set the player's health points
{
	playerHP = hp; // Update player health points
	statusChanged(0); // Notify observers of the change
}

int Player::getPlayerHP() const // Get the player's health points
{
	return playerHP; // Return player health points
}

void Player::setPlayerMaxHP(int maxHP) // Set the player's maximum health points
{
	playerMaxHP = maxHP; // Update player maximum health points
	statusChanged(2); // Notify observers of the change
}

int Player::getPlayerMaxHP() const // Get the player's maximum health points
{
	return playerMaxHP; // Return player maximum health points
}

void Player::setPlayerAP(int ap) // Set the player's attack points
{
	playerAP = ap; // Update player attack points
	statusChanged(1); // Notify observers of the change
}

int Player::getPlayerAP() const // Get the player's attack points
{
	return playerAP; // Return player attack points
}



void Player::setPlayerName(const string& name) // Set the player's name
{
	playerName = name; // Update player name
}

string Player::getPlayerName() const // Get the player's name
{
	return playerName; // Return player name
}

void Player::setPlayerDescription(const string& description) // Set the player's description
{
	playerDescription = description; // Update player description
}

string Player::getPlayerDescription() const // Get the player's description
{
	return playerDescription; // Return player description
}

int Player::getEnemyHP() const // Get the enemy's health points
{
	return 0; // Not applicable for Player
}
int Player::getEnemyAttackPoints() const // Get the enemy's attack points
{
	return 0; // Not applicable for Player
}

void Player::setEnemyHP(int hp) // Set the enemy's health points
{
	// Not applicable for Player
	std::cerr << "setEnemyHP() called on Player, which is not applicable." << std::endl;
	exit(-1);
}


