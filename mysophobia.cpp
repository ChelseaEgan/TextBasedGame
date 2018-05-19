#include "mysophobia.h"
#include "room.h"
#include "menu.h"
#include "inputvalidation.h"
#include "phobia.h"
#include "germs.h"

#include <iostream>

//Constructor
Mysophobia::Mysophobia()
{
	//Create Phobia object
	germs = new Germs();

	//Create Item object and initialize
	protonpack = new Item();
	protonpack->name = "Proton Pack";
	protonpack->strength = 40;
	protonpack->message = 
		"You fire a stream of highly focused and\nradially polarized protons to try to trap the ghost.\n\n";
}

//Set room pointers
void Mysophobia::doors(Room * right, Room * left,
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
bool Mysophobia::unlock()
{
	//Print instructions
	std::cout << "The room is locked.\n";
	std::cout << "In order to gain access, you must match the\n"
		<< "scientific name of the phobia to its definition.\n";
	std::cout << "Pick the definition for Mysophobia.\n\n";

	//Get the user's answer
	int answer = roomMenu->action(1);

	//If the answer is correct
	if (answer == 4)
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
void Mysophobia::explore()
{
	//Print name of room
	std::cout << "You take a look around the room.\n";
	std::cout << "There is a sign with the name Mysophobia.\n";
	//If phobia is alive
	if (germs != NULL)
	{
		//Print description of phobia
		std::cout << "Every surface in the room is covered in germs.\n";
		std::cout << "You try to avoid touching anything.\n";
	}
	//If phobia is dead
	else
	{
		//Print message about dead phobia
		std::cout << "There are only a few germs left in the room.\n";
		std::cout << "I guess disinfectants really kill only 99% of germs!\n\n";
	}
	//If the item is still in the room
	if (protonpack != NULL)
	{
		//Print description of weapon
		std::cout << "In another corner, there is a mysterious "
			"object.\n";
		std::cout << "Maybe it's something useful!\n";
	}
	//Print message about rooms
	std::cout << "There are two doors leading to other rooms.\n\n";
}

//User picks up weapon from room
Item * Mysophobia::pickUpItem()
{
	//If the weapon has already been picked up
	if (protonpack == NULL)
	{
		std::cout << "There is nothing to pick up in the room.\n\n";
		return NULL;
	}
	//If the weapon is still in the room
	else
	{
		//Print message
		std::cout << "You found a proton pack!\n";

		//Store weapon in temp pointer
		Item * temp;
		temp = protonpack;

		//Set weapon to NULL
		protonpack = NULL;

		//Return pointer to weapon
		return temp;
	}
}

//User changes to another room
Room * Mysophobia::changeRoom()
{
	//Print options
	std::cout << "There are doors leading to the following rooms:\n";
	std::cout << "1. Anatidaephobia\n";
	std::cout << "2. Thanatophobia\n";
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
	case 3: return right;
		break;
	case 4: return this;
	}
}

//Phobia is defeated
void Mysophobia::phobiaDefeated()
{
	germs = NULL;
	defeated = true;
}

//Get functions
std::string Mysophobia::getName()
{
	return name;
}

Phobia * Mysophobia::getBoss()
{
	return germs;
}

Item * Mysophobia::getWeapon()
{
	return protonpack;
}

Room * Mysophobia::getRight()
{
	return right;
}

Room * Mysophobia::getLeft()
{
	return left;
}

Room * Mysophobia::getUp()
{
	return up;
}

Room * Mysophobia::getDown()
{
	return down;
}

Mysophobia::~Mysophobia()
{
	if (germs != NULL)
	{
		delete germs;
	}
	if (protonpack != NULL)
	{
		delete protonpack;
	}
}