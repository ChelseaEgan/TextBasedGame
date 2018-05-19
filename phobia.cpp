#include "phobia.h"

#include <iostream>

//Constructor
Phobia::Phobia()
{
	//Create gem
	gem = new Item;
	gem->name = "Gem";
	gem->strength = 0;

	//Create health potion
	healthPotion = new Item;
	healthPotion->name = "Health Potion";
	healthPotion->strength = rand() % 4 + 1;

	phobiaDefeated = false;
}

//Destructor
Phobia::~Phobia()
{
	if (gem != NULL)
	{
		delete gem;
	}

	if (healthPotion != NULL)
	{
		delete healthPotion;
	}
}