#pragma once
#include "IRoom.h"
#include "EmptyRoom.h"
class RoomManager // RoomManager for managing the current room
{
private:
	IRoom* currentRoom; // Pointer to the current room

public:
	RoomManager() : currentRoom(new EmptyRoom()) {}; // Constructor initializes the current room to EmptyRoom

	

	void setCurrentRoom(IRoom* newRoom) { // Sets the current room to a new room
		delete currentRoom; // Free the old room
		currentRoom = newRoom; // Set the new room
	}

	void printScene() { // Prints the current room's scene
		currentRoom->printScene(); // Print the scene of the current room
	}

	string getType() { // Returns the type of the current room
		return currentRoom->getType(); // Get the type of the current room
	}

	int processOption() { // Processes the option in the current room
		return currentRoom->processOption(); // Process the option in the current room
	}

	IRoom* getCurrentRoom() { // Returns the current room
		return currentRoom; // Get the current room
	}
};

