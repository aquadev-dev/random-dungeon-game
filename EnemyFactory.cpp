#include "EnemyFactory.h"
#include "DefaultEnemy.h"
#include "BruisierEnemy.h"
#include "DefenderEnemy.h"

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