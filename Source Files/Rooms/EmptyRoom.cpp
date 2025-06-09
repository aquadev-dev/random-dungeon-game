#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Rooms/EmptyRoom.h"
#include "/School/Year 2/Object Orientated Systems Development/Assignment 1/Project/Code/Assignment 1 OOSD NLB/Header Files/Managers/SceneManager.h"

string EmptyRoom::getType() // returns the type of the room
{
	return "empty";// returns the type of the room
}

void EmptyRoom::printScene() // prints the scene
{
	SceneManager manager; // creates a scene manager object
	manager.LoadScene(4); // loads the scene
}

int EmptyRoom::processOption() 
{
	cin >> selectedOption; // gets the selected option from the user

	switch (selectedOption) // switch statement to check the selected option
	{
	case 1: // Meditate
		return selectedOption;
		break;
	case 2: // Move to Next room
		return selectedOption;
		break;
	case 3: // Move to Previous room
		return selectedOption;
		break;
	default: // Invalid option
		cout << "Invalid option. Please try again." << endl; // prints invalid option message
		return processOption(); // calls the process option function again
		break;
	}

	
}