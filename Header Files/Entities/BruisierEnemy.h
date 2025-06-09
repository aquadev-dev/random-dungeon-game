#pragma once
#include "Entity.h"
#include <vector>
#include <iostream>
using namespace std;
class BruisierEnemy : public Entity
{
public:
	
	
	void addObserver(Observer* observer) override; // Adds an observer to the list of observers
	

	void removeObserver(Observer* observer) override; // Removes an observer from the list of observers
	

	void notifyObservers() override; // Notifies all observers of a change in state
	

	void statusChanged(int status) override; // Updates the status of the enemy and notifies observers

	void setEnemyHP(int hp) override; // Sets the enemy's health points
	int getEnemyHP() const override; // Gets the enemy's health points

	int getEnemyAttackPoints() const override; // Gets the enemy's attack points
	

private:
	vector<Observer*> observers; // Vector of observers
	string enemyHealthStatus; // Enemy health status

	int enemyHP = 5; // Enemy health points
	int enemyAttackPoints = 3; // Enemy attack points

};

