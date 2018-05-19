#include "coulrophobia.h"
#include "room.h"
#include "menu.h"
#include "inputvalidation.h"
#include "phobia.h"
#include "clown.h"

#include <iostream>

//Constructor
Coulrophobia::Coulrophobia()
{
	//Create Phobia object
	clown = new Clown();

	//Create Item object and initialize
	disinfectant = new Item();
	disinfectant->name = "Disinfectant";
	disinfectant->strength = 40;
	disinfectant->message = "You scrub vigorously with disinfectant.\n\n";
}

//Set room pointers
void Coulrophobia::doors(Room * right, Room * left,
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
bool Coulrophobia::unlock()
{
	//Print instructions
	std::cout << "The room is locked.\n";
	std::cout << "In order to gain access, you must match the\n"
		<< "scientific name of the phobia to its definition.\n";
	std::cout << "Pick the definition for Coulrophobia.\n\n";

	//Get the user's answer
	int answer = roomMenu->action(1);

	//If the answer is correct
	if (answer == 5)
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
void Coulrophobia::explore()
{
	//Print name of room
	std::cout << "You take a look around the room.\n";
	std::cout << "There is a sign with the name Coulrophobia.\n";
	//If phobia is alive
	if (clown != NULL)
	{
		//Print description of phobia
		std::cout << "A clown lurks in the shadows. He whispers to\n"
			<< "you, \"We all float down here!\"\n";
		std::cout << "You think to youself \"Clowns are so creepy!\"\n";
	}
	//If phobia is dead
	else
	{
		//Print message about dead phobia
		std::cout << "The only suggestion that the Clown used to\n"
			<< "be here is a single red balloon.\n";
		std::cout << "Good job defeating the fear of clowns!\n\n";
	}
	//If the item is still in the room
	if (disinfectant != NULL)
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
Item * Coulrophobia::pickUpItem()
{
	//If the weapon has already been picked up
	if (disinfectant == NULL)
	{
		std::cout << "There is nothing to pick up in the room.\n\n";
		return NULL;
	}
	//If the weapon is still in the room
	else
	{
		//Print message
		std::cout << "You found disinfectant!\n";

		//Store weapon in temp pointer
		Item * temp;
		temp = disinfectant;

		//Set weapon to NULL
		disinfectant = NULL;

		//Return pointer to weapon
		return temp;
	}
}

//User changes to another room
Room * Coulrophobia::changeRoom()
{
	//Print options
	std::cout << "There are doors leading to the following rooms:\n";
	std::cout << "1. Arachnophobia\n";
	std::cout << "2. Phasmophobia\n";
	std::cout << "Which room would you like to move to?\n";
	std::cout << "(Enter 3 if you want to stay in this room.)\n";

	//Get user choice
	int choice = userInput->validateIntAndRange(1, 3);

	//Return pointer to selected room
	switch (choice)
	{
	case 1: return up;
		break;
	case 2: return right;
		break;
	case 3: return this;
	}
}

//Phonia is defeated
void Coulrophobia::phobiaDefeated()
{
	clown = NULL;
	defeated = true;
}

//Get functions
std::string Coulrophobia::getName()
{
	return name;
}

Phobia * Coulrophobia::getBoss()
{
	return clown;
}

Item * Coulrophobia::getWeapon()
{
	return disinfectant;
}

Room * Coulrophobia::getRight()
{
	return right;
}

Room * Coulrophobia::getLeft()
{
	return left;
}

Room * Coulrophobia::getUp()
{
	return up;
}

Room * Coulrophobia::getDown()
{
	return down;
}

Coulrophobia::~Coulrophobia()
{
	if (clown != NULL)
	{
		delete clown;
	}
	if (disinfectant != NULL)
	{
		delete disinfectant;
	}
}