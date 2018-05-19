#include "thanatophobia.h"
#include "room.h"
#include "menu.h"
#include "inputvalidation.h"
#include "phobia.h"
#include "death.h"

#include <iostream>

//Constructor
Thanatophobia::Thanatophobia()
{
	//Create Phobia object
	death = new Death();
}



//Set room pointers
void Thanatophobia::doors(Room * right, Room * left,
	Room * up, Room * down)
{
	//Set room pointers to adjacent rooms
	//If no room, set to NULL
	this->right = right;
	this->left = left;
	this->up = up;
	this->down = down;
}

//Phobia quiz to unlock room
bool Thanatophobia::unlock()
{
	//Print instructions
	std::cout << "The room is locked.\n";
	std::cout << "In order to gain access, you must match the\n"
		<< "scientific name of the phobia to its definition.\n";
	std::cout << "Pick the definition for Thanatophobia.\n\n";

	//Get the user's answer
	int answer = roomMenu->action(1);

	//If the answer is correct
	if (answer == 6)
	{
		//Print message
		std::cout << "Correct!\n";
		std::cout << "The room has been unlocked.\n\n";

		//Change the locked flag
		locked = false;

		//Call the enterRoom function
		enterRoom();
	}
	//If the answer is incorrect
	else
	{
		//Print message
		std::cout << "Oops - that's incorrect.\n";
		std::cout << "You receive a strong electric shock!\n";
		std::cout << "You lose 5 health points.\n\n";
	}
	//Return the room's status of locked/unlocked
	return locked;
}

//Print information about room
void Thanatophobia::explore()
{
	//Print name of room
	std::cout << "You take a look around the room.\n";
	std::cout << "There is a sign with the name Thanatophobia.\n";
	//If phobia is alive
	if (death != NULL)
	{
		//Print description of phobia
		std::cout << "Death beckons.\n";
		std::cout << "You're not ready to die yet!\n";
	}
	//If phobia is dead
	else
	{
		//Print message about dead phobia
		std::cout << "Death has been defeated - you are immortal!\n";
		std::cout << "You can now escape.\n\n";
	}

	//Print message about rooms
	std::cout << "There are two doors leading to other rooms\n"
		<< "and the door to the outside.\n\n";
}

//User changes to another room
Room * Thanatophobia::changeRoom()
{
	//Print options
	std::cout << "There are doors leading to the following rooms:\n";
	std::cout << "1. Phasmophobia\n";
	std::cout << "2. Mysophobia\n";
	std::cout << "Which room would you like to move to?\n";
	std::cout << "(Enter 3 if you want to stay in this room.)\n";

	//Get user choice
	int choice = userInput->validateIntAndRange(1, 3);

	//Return pointer to selected room
	switch (choice)
	{
	case 1: return left;
		break;
	case 2: return up;
		break;
	case 3: return this;
	}
}

//Phonia is defeated
void Thanatophobia::phobiaDefeated()
{
	death = NULL;
	defeated = true;
}

//Get functions
std::string Thanatophobia::getName()
{
	return name;
}

Phobia * Thanatophobia::getBoss()
{
	return death;
}

Room * Thanatophobia::getRight()
{
	return right;
}

Room * Thanatophobia::getLeft()
{
	return left;
}

Room * Thanatophobia::getUp()
{
	return up;
}

Room * Thanatophobia::getDown()
{
	return down;
}

Thanatophobia::~Thanatophobia()
{
	if (death != NULL)
	{
		delete death;
	}
}