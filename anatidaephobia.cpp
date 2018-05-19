#include "anatidaephobia.h"
#include "room.h"
#include "menu.h"
#include "inputvalidation.h"
#include "phobia.h"
#include "duck.h"

#include <iostream>

//Constructor
Anatidaephobia::Anatidaephobia()
{
	//Create Phobia object
	duck = new Duck();

	//Create Item object and initialize
	jokebook = new Item();
	jokebook->name = "Joke Book";
	jokebook->strength = 40;
	jokebook->message = "You tell a very punny joke.\n\n";
}

//Set room pointers
void Anatidaephobia::doors(Room * right, Room * left,
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
bool Anatidaephobia::unlock()
{
	//Print instructions
	std::cout << "The room is locked.\n";
	std::cout << "In order to gain access, you must match the\n"
		<< "scientific name of the phobia to its definition.\n";
	std::cout << "Pick the definition for Anatidaephobia.\n\n";

	//Get the user's answer
	int answer = roomMenu->action(1);

	//If the answer is correct
	if (answer == 2)
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
void Anatidaephobia::explore()
{
	//Print name of room
	std::cout << "You take a look around the room.\n";
	std::cout << "There is a sign with the name Anatidaephobia.\n";
	//If phobia is alive
	if (duck != NULL)
	{
		//Print description of phobia
		std::cout << "A duck quacks menacingly.\n";
		std::cout << "His beady little eyes make you shiver!\n";
	}
	//If phobia is dead
	else
	{
		//Print message about dead phobia
		std::cout << "The Duck tries to get to its feet, but it's "
			<< "stomach drags on the ground.\n";
		std::cout << "Good job defeating the fear of ducks!\n\n";
	}
	//If the item is still in the room
	if (jokebook != NULL)
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
Item * Anatidaephobia::pickUpItem()
{
	//If the weapon has already been picked up
	if (jokebook== NULL)
	{
		std::cout << "There is nothing to pick up in the room.\n\n";
		return NULL;
	}
	//If the weapon is still in the room
	else
	{
		//Print message
		std::cout << "You found a joke book!\n";

		//Store weapon in temp pointer
		Item * temp;
		temp = jokebook;

		//Set weapon to NULL
		jokebook = NULL;

		//Return pointer to weapon
		return temp;
	}
}

//User changes to another room
Room * Anatidaephobia::changeRoom()
{
	//Print options
	std::cout << "There are doors leading to the following rooms:\n";
	std::cout << "1. Arachnophobia\n";
	std::cout << "2. Phasmophobia\n";
	std::cout << "3. Mysophobia\n";
	std::cout << "Which room would you like to move to?\n";
	std::cout << "(Enter 4 if you want to stay in this room.)\n";

	//Get user choice
	int choice = userInput->validateIntAndRange(1, 4);

	//Return pointer to selected room
	switch (choice)
	{
	case 1: return left;
		break;
	case 2: return down;
		break;
	case 3: return right;
		break;
	case 4: return this;
	}
}

//Phonia is defeated
void Anatidaephobia::phobiaDefeated()
{
	duck = NULL;
	defeated = true;
}

//Get functions
std::string Anatidaephobia::getName()
{
	return name;
}

Phobia * Anatidaephobia::getBoss()
{
	return duck;
}

Item * Anatidaephobia::getWeapon()
{
	return jokebook;
}

Room * Anatidaephobia::getRight()
{
	return right;
}

Room * Anatidaephobia::getLeft()
{
	return left;
}

Room * Anatidaephobia::getUp()
{
	return up;
}

Room * Anatidaephobia::getDown()
{
	return down;
}

Anatidaephobia::~Anatidaephobia()
{
	if (duck != NULL)
	{
		delete duck;
	}
	if (jokebook != NULL)
	{
		delete jokebook;
	}
}