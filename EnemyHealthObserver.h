#pragma once
#include "Observer.h"
#include <iostream>
class EnemyHealthObserver : public Observer // Observer for enemy health updates
{
public:
	EnemyHealthObserver(const string& enemyType) : enemyType(enemyType) {} // Constructor initializes the enemy type
	void update(const string& enemyHealth) override // Update method to handle enemy health updates
	{
		cout << enemyType << "'s status updated: " << enemyHealth << endl; // Print the enemy's health status
	}

private:
	string enemyType; // Type of the enemy
};

