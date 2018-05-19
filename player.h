#ifndef PLAYER_H
#define PLAYER_H

#include "inventory.h"
#include "item.h"
#include "menu.h"
#include "inputvalidation.h"
#include "room.h"

#include <iostream>

class Player
{
private:
	//User-defined name
	std::string name;

	//Health points
	int health = 75;
	int maxHealth = 75;

	int strength = 75;

	//Inventory object
	Inventory * bag;

	//Item object to hold weapon
	Item * weapon;

	//Item object to hold health potion
	Item * healthPotion;

	//Room object
	Room * location;

	//Menu object
	Menu * playerMenu;

	//Input Validation object
	InputValidation * userInput;
public:
	//Constructor
	Player(std::string);

	//Destructor
	~Player();

	//Drink a health potion
	void takeHealthPotion();

	//Pick up item
	void pickupItem(Item *);

	//Get item from room
	void roomItem();

	//Choose weapon from inventory
	void chooseItem();

	//Drop item
	void dropItem();

	//Change room
	Room * changeRoom();

	//Get weapon to check effectiveness
	Item * checkWeapon();

	//Fight
	int attack(int);

	//Defense
	bool defense(int);

	//Inventory menu
	void inventoryMenu();

	//Lose health points
	bool loseHealth(int);

	//View inventory
	void viewInventory();

	//Create sword
	void createSword();

	//Get and set functions
	std::string getName() { return name; }
	void setName(std::string n) { name = n; }
	int getHealth() { return health; }
	void setHealth(int h) { health = h; }
	Inventory * getInventory() { return bag; }
	Item * getWeapon() { return weapon; }
	void setWeapon(Item * i) { weapon = i; }
	Room * getLocation() { return location; }
	void setLocation(Room * r) { location = r; }
};

#endif // !PLAYER_H
