#include "room.h"

#include <iostream>
#include <string>

//Constructor
Room::Room()
{
	//set counter to zero
	counter = 0;

	//Room is locked
	locked = true;

	//Phobia has not been defeated
	defeated = false;

	//Create InputValidation object
	userInput = new InputValidation();

	//Create Menu object
	roomMenu = new Menu();
}

//User enters the room
int Room::enterRoom()
{
	//Increment counter and return
	counter++;
	return counter;
}

//Get and Set functions
bool Room::getIfLocked()
{
	return locked;
}

bool Room::getIfDefeated()
{
	return defeated;
}

int Room::getCounter()
{
	return counter;
}

//Destructor
Room::~Room()
{
	delete userInput;
	delete roomMenu;
}