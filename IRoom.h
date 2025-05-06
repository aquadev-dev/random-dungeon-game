#pragma once

#include <string>

using namespace std;

class IRoom // Interface for the room
{
public:
	string virtual getType() = 0; // Get the type of the room
	void virtual printScene() = 0; // Print the scene of the room
	int virtual processOption() = 0; // Process the option selected by the user
};

