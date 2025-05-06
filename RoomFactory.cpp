#include "RoomFactory.h"
#include "EmptyRoom.h"
#include "UpgradeRoom.h"
#include "MonsterRoom.h"
#include "TreasureRoom.h"

unique_ptr<IRoom> RoomFactory::createRoom(const RoomType& roomType) // Factory method
{
	switch (roomType) // Switch statement to determine the type of room to create
	{
	case RoomType::EMPTY: // If the room type is EMPTY
		return make_unique<EmptyRoom>();
	case RoomType::UPGRADE: // If the room type is UPGRADE
		return make_unique<UpgradeRoom>();
		
	case RoomType::MONSTER: // If the room type is MONSTER
		return make_unique<MonsterRoom>();
		
	case RoomType::TREASURE: // If the room type is TREASURE
		return make_unique<TreasureRoom>();
		
	}

	//Failed to find a proper room, should not happen unless a case is missed
	return nullptr;
}