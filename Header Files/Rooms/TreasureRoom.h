#pragma once
#include <string>
#include "IRoom.h"
using namespace std;
class TreasureRoom : public IRoom // Inherit from IRoom
{
public:
	virtual string getType() override; // Get the type of the room
	virtual void printScene() override; // Print the scene of the room
	virtual int processOption() override; // Process the option selected by the user
	
};

