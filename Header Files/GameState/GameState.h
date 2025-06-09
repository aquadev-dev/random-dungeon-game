#pragma once
class GameState // Abstract class for game states
{
public:
	virtual void update() = 0; // Update the state
	virtual int getStateNum() = 0; // Get the state number
};

