#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "inputvalidation.h"
#include "menu.h"
#include "phobia.h"
#include "room.h"
#include "inventory.h"
#include "item.h"

#include <iostream>
#include <vector>

class Game
{
private:
	//Player object
	Player * user;

	//Item object to temporarily hold items
	Item * loot;

	//Room object for user's location
	Room * location;

	//Object to hold current opponent
	Phobia * ai;

	//Menu object
	Menu * gameMenu;

	//InputValidation object
	InputValidation * userInput;
	
	//Vector to hold all rooms in the building
	std::vector <Room *> building;

	//Counts number of times that rooms are entered
	int numRoomsEntered = 0;
public:
	//Constructor
	Game();

	//Destructor
	~Game();

	//Create player
	void createPlayer();

	//Creates all rooms for the building
	void createRooms();

	//Start the beginning of the game
	void startGame();

	//Clear the screen
	void clearScreen();

	//User changes rooms
	void changeRoom();

	//Fight loop
	int fight();

	//Game loop
	int loop();
};

#endif // !GAME_H
