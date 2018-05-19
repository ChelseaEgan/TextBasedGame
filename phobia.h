#ifndef PHOBIA_H
#define PHOBIA_H

#include "inputvalidation.h"
#include "menu.h"
#include "item.h"

#include <iostream>

class Phobia
{
protected:
	//Flag indicating if defeated
	bool phobiaDefeated;

	//Gem that is dropped when phobia is defeated
	Item * gem;

	//Health Potion (HP) that is dropped when phobia is defeated
	Item * healthPotion;
public:
	//Constructor
	Phobia();

	//Runs when phobia is defeated
	virtual bool defeated() = 0;

	//Attack function
	virtual int attack() = 0;

	//Defense function
	virtual bool defense(int) = 0;

	//Checks if player's weapon is effective
	virtual int checkWeapon(Item *) = 0;

	//Get and set functions
	Item * getGem() { return gem; }
	void setGem(Item * g) { gem = g; }
	Item * getHP() { return healthPotion; }
	void setHP(Item * hp) { healthPotion = hp; }
	virtual std::string getName() = 0;
	virtual int getHealth() = 0;
	
	//Destructor
	~Phobia();
};

#endif // !PHOBIA_H
