#pragma once
#include "Entity.h"
#include "memory"

using namespace std;
class MonsterGenerator // Class to generate monsters
{
public:
	unique_ptr<Entity> generateMonster(int monsterType); // Function to generate a monster based on the type
};

