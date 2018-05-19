#ifndef ANATIDAEPHOBIA_H
#define ANATIDAEPHOBIA_H

#include "room.h"

class Anatidaephobia : public Room
{
private:
	//Name of room
	std::string name = "Anatidaephobia Room";

	//Pointer to Phobia located in room
	Phobia * duck;

	//Pointer to Item located in room
	Item * jokebook;

	//Pointers to adjacent rooms
	Room * right;
	Room * left;
	Room * up;
	Room * down;
public:
	//Constructor
	Anatidaephobia();

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

	~Anatidaephobia();
};

#endif // !ANATIDAEPHOBIA_H