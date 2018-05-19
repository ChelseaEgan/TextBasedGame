#ifndef THANATOPHOBIA_H
#define THANATOPHOBIA_H

#include "room.h"

class Thanatophobia : public Room
{
private:
	//Name of room
	std::string name = "Thanatophobia Room";

	//Pointer to Phobia located in room
	Phobia * death;

	//Pointers to adjacent rooms
	Room * right;
	Room * left;
	Room * up;
	Room * down;
public:
	//Constructor
	Thanatophobia();

	//Set room pointers
	void doors(Room * right = NULL, Room * left = NULL,
		Room * up = NULL, Room * down = NULL);

	//Phobia quiz to unlock room
	bool unlock();

	//Print information about room
	void explore();

	//User changes to another room
	Room * changeRoom();

	//Phonia is defeated
	void phobiaDefeated();

	//Get functions
	std::string getName();
	Phobia * getBoss();
	Room * getRight();
	Room * getLeft();
	Room * getUp();
	Room * getDown();

	Item * pickUpItem() { return NULL; }

	//Destructor
	~Thanatophobia();
};

#endif // !THANATOPHOBIA_H