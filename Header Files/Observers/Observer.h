#pragma once
#include <string>

using namespace std;
class Observer // Observer interface for the observer pattern
{
public:
	virtual ~Observer() = default; // Virtual destructor for cleanup
	virtual void update(const string& playerStatus) = 0; // Pure virtual function for updating the observer
};

