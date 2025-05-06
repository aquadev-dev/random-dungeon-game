#include "DefenderEnemy.h"

void DefenderEnemy::addObserver(Observer* observer) // Add an observer to the list
{
	observers.push_back(observer); // Add the observer to the list
}

void DefenderEnemy::removeObserver(Observer* observer) // Remove an observer from the list
{
	observers.erase(remove(observers.begin(), observers.end(), observer), observers.end()); // Remove the observer from the list
}

void DefenderEnemy::notifyObservers() // Notify all observers of the change
{
	for (Observer* observer : observers) // Iterate through all observers
	{
		observer->update(enemyHealthStatus); // Notify each observer with the current health status
	}
}

void DefenderEnemy::statusChanged(int status) // Notify observers of a status change
{
	if (status == 0) { // If status is 0, notify observers of a health change
		enemyHealthStatus = "Defender Enemy HP is now " + to_string(enemyHP); // Update health status
		notifyObservers(); // Notify observers
	}
	else { // If status is not 0, check for other status codes
		throw runtime_error("Invalid status code"); // Throw an error for invalid status codes
	}
}

void DefenderEnemy::setEnemyHP(int hp) // Set the enemy's health points
{
	enemyHP = hp; // Update enemy health points
	statusChanged(0); // Notify observers of the change
}

int DefenderEnemy::getEnemyHP() const // Get the enemy's health points
{
	return enemyHP; // Return enemy health points
}

int DefenderEnemy::getEnemyAttackPoints() const // Get the enemy's attack points
{
	return enemyAttackPoints; // Return enemy attack points
}