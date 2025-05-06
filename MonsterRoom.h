#pragma once
#include <string>
#include "IRoom.h"

using namespace std;
class MonsterRoom : public IRoom // Inherit from IRoom
{
private:
	int monsterType; // 0: Default, 1: Brusier, 2: Defender
	int selectedOption; // Variable to store the selected option
public:
	virtual string getType() override; // Get the type of the room
	virtual void printScene() override; // Print the scene of the room
	int processOption() override; // Process the option selected by the user
	void printMonsterRoom(int monsterType); // Getter for monsterType
	int getMonsterType(); // Getter for monsterType
	
	void generateMonster(); // Generate a random monster type

};

