#pragma once
#include "Observer.h"
class Entity
{
public:
	virtual ~Entity() = default; // Destructor
	virtual void addObserver(Observer* observer) = 0; // Adds an observer to the list of observers
	virtual void removeObserver(Observer* observer) = 0; // Removes an observer from the list of observers
	virtual void notifyObservers() = 0; // Notifies all observers of a change in state

	virtual void statusChanged(int status) = 0; // Updates the status of the enemy and notifies observers

	virtual void setEnemyHP(int hp) = 0; // Sets the enemy's health points
	virtual int getEnemyHP() const = 0; // Gets the enemy's health points

	virtual int getEnemyAttackPoints() const = 0; // Gets the enemy's attack points
};

