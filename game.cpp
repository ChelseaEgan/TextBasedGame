#include "game.h"
#include "anatidaephobia.h"
#include "arachnophobia.h"
#include "coulrophobia.h"
#include "mysophobia.h"
#include "phasmophobia.h"
#include "thanatophobia.h"
#include "room.h"
#include "phobia.h"

#include <vector>
#include <ctime>
#include <stdlib.h>

//Constructor
Game::Game()
{
	//Create objects
	gameMenu = new Menu;
	userInput = new InputValidation;

	//Set variables that hold objects to NULL
	loot = NULL;
	location = NULL;
	ai = NULL;

	//Create building
	createRooms();

	//Seed the rand function
	srand(time(NULL));
}

//Destructor
Game::~Game()
{
	//Delete all allocated storage
	delete gameMenu;
	delete userInput;
	delete user;

	//Pointer to hold each room
	Room * temp;

	for (int i = 0; i < building.size(); i++)
	{
		temp = building[i];
		delete temp;
	}
	building.clear();
}

//Create player object
void Game::createPlayer()
{
	std::cout << "Enter your name:\n";
	std::string name = userInput->validateString();
	user = new Player(name);
}

//Creates all rooms for the building
void Game::createRooms()
{
	Room * germs = new Mysophobia;
	building.push_back(germs);
	Room * duck = new Anatidaephobia;
	building.push_back(duck);
	Room * spider = new Arachnophobia;
	building.push_back(spider);
	Room * clown = new Coulrophobia;
	building.push_back(clown);
	Room * ghost = new Phasmophobia;
	building.push_back(ghost);
	Room * death = new Thanatophobia;
	building.push_back(death);

	//Set pointers to adjacent rooms
	spider->doors(duck, NULL, NULL, clown);
	duck->doors(germs, spider, NULL, ghost);
	germs->doors(NULL, duck, NULL, death);
	clown->doors(ghost, NULL, spider, NULL);
	ghost->doors(death, clown, duck, NULL);
	death->doors(NULL, ghost, germs, NULL);
}

//Start the beginning of the game
void Game::startGame()
{
	std::cout << "\"I must not fear. Fear is the mind-killer.\n"
		<< "Fear is the little-death that brings total obliteration.\n"
		<< "I will face my fear. I will permit it to pass over me \n"
		<< "and through me.And when it has gone past I will turn\n"
		<< "the inner eye to see its path.Where the fear has gone\n"
		<< "there will be nothing.Only I will remain.\"\n"
		<< "-Frank Herbert, Dune\n\n";
	std::cout << "You are standing in front of a building where\n"
		<< "you will have to face your fears.\n\n";
	std::cout << "There are six rooms and in each room you will\n"
		<< "find a phobia to defeat and a weapon.\n\n";
	std::cout << "In order to enter a room, you will need to match\n"
		<< "the scientific name of a phobia to its definition.\n";
	std::cout << "Guess wrong and you lose some health.\n\n";
	std::cout << "Each phobia is susceptible to a specific weapon.\n\n";
	std::cout << "When a phobia is defeated, it drops a gem and\n"
		<< "has a random chance of dropping a health potion.\n\n";
	std::cout << "The final phobia is Death, which can only be\n"
		<< "defeated with the Sword of Immortality.\n";
	std::cout << "You create the Sword with five gems, collected\n"
		<< "by defeating the other phobias.\n\n";
	std::cout << "Once you have beat death, you become immortal,\n"
		<< "have overcome your fears, and can leave the building.\n";
	std::cout << "But be careful - if you die, you lose the game!\n\n";

	clearScreen();

	createPlayer();
	std::cout << "You are a brave adventurer named "
		<< user->getName() << std::endl;
	std::cout << "You have " << user->getHealth() << " health "
		<< "points.\n\n";

	clearScreen();

	//Set location as first room (Mysophobia)
	user->setLocation(building[0]);
	location = building[0];

	ai = location->getBoss();

	bool locked = true;

	do
	{
		locked = location->unlock();
		if (locked)
		{
			user->loseHealth(5);
			clearScreen();
		}
	} while (locked == true);
	
	numRoomsEntered++;
	clearScreen();

	loop();
}

//Clear screen
void Game::clearScreen()
{
	std::cout << "\n\nPress enter to continue...";
	std::cin.get();
	std::cin.clear();

	for (int i = 0; i < 60; i++)
	{
		std::cout << std::endl;
	}
}

//User changes rooms
void Game::changeRoom()
{
	//Get user's choice for next room
	location = user->changeRoom();
	ai = location->getBoss();

	if (location->getIfLocked())
	{
		bool locked = true;
		char choice;

		do
		{
			locked = location->unlock();

			if (locked)
			{
				user->loseHealth(5);
				clearScreen();
			}
		} while (locked == true);
	}

	numRoomsEntered++;
	clearScreen();

	if (numRoomsEntered == 12)
	{
		std::cout << "You have changed rooms too many times!\n\n";
		std::cout << "Each room you enter again will cause you\n"
			<< "to lose 5 health points.\n\n";
		clearScreen();
	}
	if (numRoomsEntered > 12)
	{
		std::cout << "You have lost 5 health points due to entering\n"
			<< "rooms too often.";
		user->loseHealth(5);
		clearScreen();
	}
}

//Fight loop
int Game::fight()
{
	int choice = 1;
	int gameStatus = 2;
	do
	{
		//Status of game
		//1 = phobia defeated
		//2 = keep playing
		//3 - Player died
		//4 - Death died

		Item * playerWeapon = user->checkWeapon();

		if (playerWeapon != NULL)
		{
			int effectiveness = ai->checkWeapon(playerWeapon);

			//User attacks and damage is stored
			int attack = user->attack(effectiveness);

			//User does not have a weapon
			if (attack == -1)
			{
				return 2;
			}

			//Phobia defends and get whether it died
			bool died = ai->defense(attack);

			//If the phobia died
			if (died)
			{
				if (ai->getName() == "Death")
				{
					return 4;
				}
				else
				{
					//Get if phobia drops a health potion
					bool hp = ai->defeated();

					//If a health potion was dropped
					if (hp)
					{
						std::cout << "You got a health potion!\n\n";
						loot = new Item;
						loot->name = "Health Potion";
						loot->strength = rand() % 50 + 25;
						user->pickupItem(loot);
						loot = NULL;
						clearScreen();
					}

					std::cout << "You got a gem!\n\n";
					loot = new Item;
					loot->name = "Gem";
					loot->strength = 0;
					user->pickupItem(loot);
					loot = NULL;
					clearScreen();

					return 2;
				}
			}
			//Phobia still alive
			else
			{
				died = false;

				//Phobia attacks the user
				attack = ai->attack();

				//User defends against attack
				died = user->defense(attack);

				//If the user died
				if (died)
				{
					return 3;
				}
			}
		}
		//Both phobia and user are still alive
		gameStatus = 2;

		choice = gameMenu->action(3);
		if (choice == 2)
		{
			user->inventoryMenu();
		}
	} while (choice == 1);

	return gameStatus;
}

//Game loop
int Game::loop()
{
	//Game status
	//1 = user selects quit
	//2 = keep playing
	//3 = user loses
	//4 = user wins
	int gameStatus = 2;

	//Display menu
	int choice = gameMenu->action(4);

	//Based on choice
	switch (choice)
	{
		//Display health points for user
	case 1: std::cout << "Your health points: " << user->getHealth()
		<< std::endl;
		clearScreen();
		break;
		//View equipped item
	case 2: 
		if (user->getWeapon() == NULL)
		{
			std::cout << "You do not have a weapon equipped.\n\n";
			clearScreen();
		}
		else
		{
			std::cout << "Equipped: " << user->getWeapon()->name << std::endl;
			clearScreen();
		}
		break;
		//Move to another room
	case 3: changeRoom();
		break;
		//View inventory menu
	case 4: user->inventoryMenu();
		break;
		//Explore room
	case 5: user->getLocation()->explore();
		clearScreen();
		break;
		//Fight
	case 6: gameStatus = fight();
		break;
		//Pick up item
	case 7: user->roomItem();
		clearScreen();
		break;
	case 8: gameStatus = 1;
	}

	if (user->getHealth() <= 0)
	{
		gameStatus = 3;
	}
	return gameStatus;
}