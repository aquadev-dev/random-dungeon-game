#include "BruisierEnemy.h"

void BruisierEnemy::addObserver(Observer* observer) // Add observer to the list
{
	observers.push_back(observer); // Add the observer to the list
}

void BruisierEnemy::removeObserver(Observer* observer) // Remove observer from the list
{
	observers.erase(remove(observers.begin(), observers.end(), observer), observers.end()); // Remove the observer from the list
}

void BruisierEnemy::notifyObservers() // Notify all observers
{
	for (Observer* observer : observers) // For each observer in the list
	{
		observer->update(enemyHealthStatus); // Notify the observer with the current enemy health status
	}
}

void BruisierEnemy::statusChanged(int status) // Notify observers of status change
{
	if (status == 0) { // If status is 0, notify observers of enemy health change
		enemyHealthStatus = "Bruisier Enemy HP is now " + to_string(enemyHP); // Update health status
		notifyObservers(); // Notify observers
	}
	else {
		throw runtime_error("Invalid status code"); // If status is not 0, throw an error
	}
}
void BruisierEnemy::setEnemyHP(int hp) // Set enemy HP and notify observers
{
	enemyHP = hp; // Set enemy HP
	statusChanged(0); // Notify observers of health change
}

int BruisierEnemy::getEnemyHP() const // Get enemy HP
{
	return enemyHP; // Return enemy HP
}
int BruisierEnemy::getEnemyAttackPoints() const // Get enemy attack points
{
	return enemyAttackPoints; // Return enemy attack points
}