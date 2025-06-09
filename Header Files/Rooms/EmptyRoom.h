#pragma once
#include <string>
#include <iostream>
#include "IRoom.h"

using namespace std;
class EmptyRoom : public IRoom // Inherit from IRoom
{
public:
	virtual string getType() override; // Get the type of the room
	virtual void printScene() override; // Print the scene of the room
	virtual int processOption() override; // Process the option selected by the user

private:
	int selectedOption = 0; // Variable to store the selected option
};

