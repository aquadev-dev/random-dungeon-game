#include "MonsterGenerator.h"
#include "EnemyFactory.h"

unique_ptr<Entity> MonsterGenerator::generateMonster(int monsterType) // 0 = Default, 1 = Bruisier, 2 = Defender
{
	EnemyFactory enemyFactory; // Assuming EnemyFactory is a class that creates enemies

	std::unique_ptr<Entity> DefaultEnemy = enemyFactory.createEnemy(EnemyFactory::EnemyType::DEFAULT); // Default enemy
	std::unique_ptr<Entity> BruisierEnemy = enemyFactory.createEnemy(EnemyFactory::EnemyType::BRUISIER); // Bruisier enemy
	std::unique_ptr<Entity> DefenderEnemy = enemyFactory.createEnemy(EnemyFactory::EnemyType::DEFENDER); // Defender enemy

	switch (monsterType) // Switch statement to determine which enemy to create
	{
	case 0:
		return DefaultEnemy; // Default enemy
	case 1:
		return BruisierEnemy; // Bruisier enemy
	case 2:
		return DefenderEnemy; // Defender enemy
	default:
		return nullptr; // Invalid monster type
	}
}