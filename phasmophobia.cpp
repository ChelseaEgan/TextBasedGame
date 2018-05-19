#include "phasmophobia.h"
#include "room.h"
#include "menu.h"
#include "inputvalidation.h"
#include "phobia.h"
#include "ghost.h"

#include <iostream>

//Constructor
Phasmophobia::Phasmophobia()
{
	//Create Phobia object
	ghost = new Ghost();

	//Create Item object and initialize
	bugrepellant = new Item();
	bugrepellant->name = "Insect Repellant";
	bugrepellant->strength = 40;
	bugrepellant->message =
		"You spray the insect repellant in the direction of the spider.\n\n";
}

//Set room pointers
void Phasmophobia::doors(Room * right, Room * left,
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
bool Phasmophobia::unlock()
{
	//Print instructions
	std::cout << "The room is locked.\n";
	std::cout << "In order to gain access, you must match the\n"
		<< "scientific name of the phobia to its definition.\n";
	std::cout << "Pick the definition for Phasmophobia.\n\n";

	//Get the user's answer
	int answer = roomMenu->action(1);

	//If the answer is correct
	if (answer == 3)
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
void Phasmophobia::explore()
{
	//Print name of room
	std::cout << "You take a look around the room.\n";
	std::cout << "There is a sign with the name Phasmophobia.\n";
	//If phobia is alive
	if (ghost != NULL)
	{
		//Print description of phobia
		std::cout << "A ghost floats up from the floor.\n";
		std::cout << "Goosebumps appear on your arms!\n";
	}
	//If phobia is dead
	else
	{
		//Print message about dead phobia
		std::cout << "The Ghost tries to break out of the ghost trap.\n";
		std::cout << "Good job defeating the fear of ghosts!\n\n";
	}
	//If the item is still in the room
	if (bugrepellant != NULL)
	{
		//Print description of weapon
		std::cout << "In another corner, there is a mysterious "
			"object.\n";
		std::cout << "Maybe it's something useful!\n";
	}
	//Print message about rooms
	std::cout << "There are three doors leading to other rooms.\n\n";
}

//User picks up weapon from room
Item * Phasmophobia::pickUpItem()
{
	//If the weapon has already been picked up
	if (bugrepellant == NULL)
	{
		std::cout << "There is nothing to pick up in the room.\n\n";
		return NULL;
	}
	//If the weapon is still in the room
	else
	{
		//Print message
		std::cout << "You found bug repellant!\n";

		//Store weapon in temp pointer
		Item * temp;
		temp = bugrepellant;

		//Set weapon to NULL
		bugrepellant = NULL;

		//Return pointer to weapon
		return temp;
	}
}

//User changes to another room
Room * Phasmophobia::changeRoom()
{
	//Print options
	std::cout << "There are doors leading to the following rooms:\n";
	std::cout << "1. Coulrophobia\n";
	std::cout << "2. Anatidaephobia\n";
	std::cout << "3. Thanatophobia\n";
	std::cout << "Which room would you like to move to?\n";
	std::cout << "(Enter 4 if you want to stay in this room.)\n";

	//Get user choice
	int choice = userInput->validateIntAndRange(1, 4);

	//Return pointer to selected room
	switch (choice)
	{
	case 1: return left;
		break;
	case 2: return up;
		break;
	case 3: return right;
		break;
	case 4: return this;
	}
}

//Phonia is defeated
void Phasmophobia::phobiaDefeated()
{
	ghost = NULL;
	defeated = true;
}

//Get functions
std::string Phasmophobia::getName()
{
	return name;
}

Phobia * Phasmophobia::getBoss()
{
	return ghost;
}

Item * Phasmophobia::getWeapon()
{
	return bugrepellant;
}

Room * Phasmophobia::getRight()
{
	return right;
}

Room * Phasmophobia::getLeft()
{
	return left;
}

Room * Phasmophobia::getUp()
{
	return up;
}

Room * Phasmophobia::getDown()
{
	return down;
}

Phasmophobia::~Phasmophobia()
{
	if (ghost != NULL)
	{
		delete ghost;
	}
	if (bugrepellant!= NULL)
	{
		delete bugrepellant;
	}
}