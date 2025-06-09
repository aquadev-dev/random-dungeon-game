#pragma once
#include <memory>
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Rooms/IRoom.h"
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Source Files/Rooms/RoomTypes.cpp"

using namespace std;

class RoomFactory // Factory class to create different types of rooms
{
public:
	unique_ptr<IRoom> createRoom(const RoomType& roomType); // Factory method to create a room based on the type
};

