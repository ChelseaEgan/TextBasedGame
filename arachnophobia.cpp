#include "arachnophobia.h"
#include "room.h"
#include "menu.h"
#include "inputvalidation.h"
#include "phobia.h"
#include "spider.h"

#include <iostream>

//Constructor
Arachnophobia::Arachnophobia()
{
	//Create Phobia object
	spider = new Spider();

	//Create Item object and initialize
	breadcrumbs = new Item();
	breadcrumbs->name = "Breadcrumbs";
	breadcrumbs->strength = 40;
	breadcrumbs->message = "You scatter fresh breadcrumbs.\n\n";
}

//Set room pointers
void Arachnophobia::doors(Room * right, Room * left,
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
bool Arachnophobia::unlock()
{
	//Print instructions
	std::cout << "The room is locked.\n";
	std::cout << "In order to gain access, you must match the\n"
		<< "scientific name of the phobia to its definition.\n";
	std::cout << "Pick the definition for Arachnophobia.\n\n";

	//Get the user's answer
	int answer = roomMenu->action(1);

	//If the answer is correct
	if (answer == 1)
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
void Arachnophobia::explore()
{
	//Print name of room
	std::cout << "You take a look around the room.\n";
	std::cout << "There is a sign with the name Arachnophobia.\n";
	//If spider is alive
	if (spider != NULL)
	{
		//Print description of spider
		std::cout << "In the back corner, a large, hairy spider "
			<< "lurks menacingly.\n";
		std::cout << "\"Ew I hate spiders!\"\n";
	}
	//If spider is dead
	else
	{
		//Print message about dead spider
		std::cout << "The shriveled body of the spider lies in "
			<< "the corner.\n";
		std::cout << "Good job defeating the fear of spiders!\n";
	}
	//If the item is still in the room
	if (breadcrumbs != NULL)
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
Item * Arachnophobia::pickUpItem()
{
	//If the weapon has already been picked up
	if (breadcrumbs == NULL)
	{
		std::cout << "There is nothing to pick up in the room.\n\n";
		return NULL;
	}
	//If the weapon is still in the room
	else
	{
		//Print message
		std::cout << "You found breadcrumbs!\n";

		//Store weapon in temp pointer
		Item * temp;
		temp = breadcrumbs;

		//Set weapon to NULL
		breadcrumbs = NULL;

		//Return pointer to weapon
		return temp;
	}
}

//User changes to another room
Room * Arachnophobia::changeRoom()
{
	//Print options
	std::cout << "There are doors leading to the following rooms:\n";
	std::cout << "1. Anatidaephobia\n";
	std::cout << "2. Coulrophobia\n";
	std::cout << "Which room would you like to move to?\n";
	std::cout << "(Enter 3 if you want to stay in this room.)\n";

	//Get user choice
	int choice = userInput->validateIntAndRange(1, 3);
	
	//Return pointer to selected room
	switch (choice)
	{
	case 1: return right;
		break;
	case 2: return down;
		break;
	case 3: return this;
	}
}

//Phonia is defeated
void Arachnophobia::phobiaDefeated()
{
	spider = NULL;
	defeated = true;
}

//Get functions
std::string Arachnophobia::getName()
{
	return name;
}

Phobia * Arachnophobia::getBoss()
{
	return spider;
}

Item * Arachnophobia::getWeapon()
{
	return breadcrumbs;
}

Room * Arachnophobia::getRight()
{
	return right;
}

Room * Arachnophobia::getLeft()
{
	return left;
}

Room * Arachnophobia::getUp()
{
	return up;
}

Room * Arachnophobia::getDown()
{
	return down;
}

Arachnophobia::~Arachnophobia()
{
	if (spider != NULL)
	{
		delete spider;
	}
	if (breadcrumbs != NULL)
	{
		delete breadcrumbs;
	}
}