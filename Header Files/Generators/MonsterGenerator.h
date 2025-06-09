#pragma once
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Entities/Entity.h"
#include "memory"

using namespace std;
class MonsterGenerator // Class to generate monsters
{
public:
	unique_ptr<Entity> generateMonster(int monsterType); // Function to generate a monster based on the type
};

