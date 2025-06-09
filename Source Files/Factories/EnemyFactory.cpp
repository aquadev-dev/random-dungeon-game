#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Factories/EnemyFactory.h"
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Entities/DefaultEnemy.h"
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Entities/BruisierEnemy.h"
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Entities/DefenderEnemy.h"

unique_ptr<Entity> EnemyFactory::createEnemy(EnemyType result) // Factory method
{
	// Create a new enemy based on the type passed in
	switch (result)
	{
	case EnemyType::DEFAULT: // Default enemy
		return make_unique<DefaultEnemy>();
	case EnemyType::BRUISIER: // Bruisier enemy
		return make_unique<BruisierEnemy>();
	case EnemyType::DEFENDER: // Defender enemy
		return make_unique<DefaultEnemy>();
	
	}

	//Failed to find a proper enemy, should not happen unless a case is missed
	return nullptr;
}