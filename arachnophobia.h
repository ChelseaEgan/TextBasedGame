#ifndef ARACHNOPHOBIA_H
#define ARACHNOPHOBIA_H

#include "room.h"

class Arachnophobia : public Room
{
private:
	//Name of room
	std::string name = "Arachnophobia Room";

	//Pointer to Phobia located in room
	Phobia * spider;

	//Pointer to Item located in room
	Item * breadcrumbs;

	//Pointers to adjacent rooms
	Room * right;
	Room * left;
	Room * up;
	Room * down;
public:
	//Constructor
	Arachnophobia();

	//Set room pointers
	void doors(Room * right = NULL, Room * left = NULL,
		Room * up = NULL, Room * down = NULL);

	//Phobia quiz to unlock room
	bool unlock();

	//Print information about room
	void explore();

	//User picks up weapon from room
	Item * pickUpItem();

	//User changes to another room
	Room * changeRoom();

	//Phonia is defeated
	void phobiaDefeated();

	//Get functions
	std::string getName();
	Phobia * getBoss();
	Item * getWeapon();
	Room * getRight();
	Room * getLeft();
	Room * getUp();
	Room * getDown();

	~Arachnophobia();
};

#endif // !ARACHNOPHOBIA_H
