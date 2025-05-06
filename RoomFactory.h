#pragma once
#include <memory>
#include "IRoom.h"
#include "RoomTypes.cpp"

using namespace std;

class RoomFactory // Factory class to create different types of rooms
{
public:
	unique_ptr<IRoom> createRoom(const RoomType& roomType); // Factory method to create a room based on the type
};

