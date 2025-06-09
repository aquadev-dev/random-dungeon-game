#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Generators/DungeonGenerator.h"
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Factories/RoomFactory.h"


vector<string> DungeonGenerator::generateDungeon() // Function to generate a dungeon
{
	RoomFactory roomFactory; // Create a RoomFactory object

	// Create all of the room types
	std::unique_ptr<IRoom> EmptyRoom = roomFactory.createRoom(RoomType::EMPTY); // Create an empty room
	std::unique_ptr<IRoom> UpgradeRoom = roomFactory.createRoom(RoomType::UPGRADE); // Create an upgrade room
	std::unique_ptr<IRoom> MonsterRoom = roomFactory.createRoom(RoomType::MONSTER); // Create a monster room
	std::unique_ptr<IRoom> TreasureRoom = roomFactory.createRoom(RoomType::TREASURE); // Create a treasure room

	int randomRoomType; // Variable to store the random room type
	srand(time(0)); // Seed the random number generator

	while (rooms.size() != 8) // Loop until we have 8 rooms
	{
		if (rooms.empty()) { // If the rooms vector is empty, add an empty room
			rooms.push_back(EmptyRoom->getType()); // Add an empty room to the vector
			emptyRoomCount++; // Increment the empty room count
		}
		 // Seed the random number generator

		randomRoomType = rand() % 6; // Generate a random number between 0 and 5

		switch (randomRoomType) // Switch statement to determine the type of room to add
		{
			case 0: { 
				if (emptyRoomCount < 2) { // If there are less than 2 empty rooms
					
					rooms.push_back(EmptyRoom->getType()); // Add an empty room to the vector
					emptyRoomCount++; // Increment the empty room count
				}
				break;
			}
			case 1: {
				if (upgradeRoomCount < 2) { // If there are less than 2 upgrade rooms
					
					rooms.push_back(UpgradeRoom->getType()); // Add an upgrade room to the vector
					upgradeRoomCount++; // Increment the upgrade room count
				}
				break;
			}
			case 2: {
				if (treasureRoomCount < 1) { // If there are less than 1 treasure rooms
					
					rooms.push_back(TreasureRoom->getType()); // Add a treasure room to the vector
					treasureRoomCount++; // Increment the treasure room count
				}
				break;
			}
			case 3: {
				if (monsterRoomCount < 3) { // If there are less than 3 monster rooms
					
					rooms.push_back(MonsterRoom->getType()); // Add a monster room to the vector
					monsterRoomCount++; // Increment the monster room count
				}
				break;
			}
			case 4: {
				if (monsterRoomCount < 3) { // If there are less than 3 monster rooms
					rooms.push_back(MonsterRoom->getType()); // Add a monster room to the vector
					monsterRoomCount++; // Increment the monster room count
				}
				break;
			}
			case 5: {
				if (upgradeRoomCount < 2) { // If there are less than 2 upgrade rooms

					rooms.push_back(UpgradeRoom->getType()); // Add an upgrade room to the vector
					upgradeRoomCount++; // Increment the upgrade room count
				}
				break;
			}

			default: {
				// Handle unexpected case
				break;
			}
		}

		
	}

	return rooms; // Return the vector of rooms


	
}