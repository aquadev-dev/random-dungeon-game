#pragma once
#include <memory>
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Entities/Entity.h"

using namespace std;
class EnemyFactory
{
public:
	enum class EnemyType // Enum class to define different enemy types
	{
		DEFAULT, // Default enemy
		BRUISIER, // Bruisier enemy
		DEFENDER // Defender enemy
	};

	unique_ptr<Entity> createEnemy(EnemyType result); // Factory method to create an enemy based on the type

	
	
};

