#ifndef ROOM_H
#define ROOM_H

#include "inputvalidation.h"
#include "menu.h"
#include "phobia.h"
#include "item.h"

class Room
{
protected:
	//Menu object
	Menu * roomMenu;
	
	//Input Validatiob object
	InputValidation * userInput;

	//Pointer to Phobia
	Phobia * boss;

	//Indicates whether room is locked
	bool locked;

	//Indicates whether phobia has been defeated
	bool defeated;

	//Counter for number of times the user entered the room
	int counter;
public:
	//Constructor
	Room();

	//Set room pointers
	virtual void doors(Room * right = NULL, Room * left = NULL,
		Room * up = NULL, Room * down = NULL) = 0;

	//Run phobia quiz to unlock room
	virtual bool unlock() = 0;

	//Print information of room
	virtual void explore() = 0;

	//User changes to another room
	virtual Room * changeRoom() = 0;

	//User picks up item in room
	virtual Item * pickUpItem() = 0;

	//User enters the room
	int enterRoom();

	//Get and Set functions
	bool getIfLocked();
	bool getIfDefeated();
	int getCounter();
	virtual Phobia * getBoss() = 0;
	virtual std::string getName() = 0;

	//Destructor
	~Room();
};

#endif // !ROOM_H
