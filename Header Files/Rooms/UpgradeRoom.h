#pragma once
#include <string>
#include "IRoom.h"
#include <iostream>

using namespace std;
class UpgradeRoom : public IRoom // Inherit from IRoom
{
public:
	virtual string getType() override; // Get the type of the room
	virtual void printScene() override; // Print the scene of the room
	int processOption() override; // Process the option selected by the user
private:
	int selectedOption = 0; // Variable to store the selected option
};

