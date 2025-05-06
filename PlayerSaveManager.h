#pragma once
#include "Player.h"
class PlayerSaveManager // PlayerSaveManager for saving player data
{
public:
	void SavePlayerData(const Player& player); // Saves player data to a file
};

