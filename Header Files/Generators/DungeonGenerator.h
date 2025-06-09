#pragma once
#include <vector>
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Rooms/IRoom.h"

using namespace std;
class DungeonGenerator // Class to generate a dungeon with different types of rooms
{
private:
	int emptyRoomCount = 0; // Number of empty rooms
	int upgradeRoomCount = 0; // Number of upgrade rooms
	int treasureRoomCount = 0; // Number of treasure rooms
	int monsterRoomCount = 0; // Number of monster rooms

	vector<string> rooms; // Vector to store the generated rooms

public:
	vector<string> generateDungeon(); // Function to generate the dungeon
};

