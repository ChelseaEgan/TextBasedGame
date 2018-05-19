#ifndef DEATH_H
#define DEATH_H

#include "phobia.h"
#include "item.h"
#include "inputvalidation.h"

#include <iostream>

class Death : public Phobia
{
private:
	//Name of phobia
	std::string name = "Death";

	//Phobia's health points
	int health = 100;
	int maxHealth = 100;

	//Strength of attacks
	int strength = 75;

	//Name of weapon that Death is vulnerable to
	std::string effectiveWeapon = "Sword of Immortality";

	//Messages to use during attacks
	std::string attackMessages[3] = {
		"Death cackles while swinging it's scythe towards your neck!\n",
		"An icy shiver runs up your spine as Death charges!\n",
		"You desperately try to evade Death's rapid blows!\n"
	};

	//Messages to use during defense
	std::string defenseMessages[3] = {
		"The sound of metal on metal rings out as Death tries to deflect your attacks!\n",
		"Death shuffles backward as you fight to gain ground!\n",
		"Is that fear you see in Death's empty eye sockets?\n"
	};
public:
	//Constructor
	Death() {};

	//Runs when phobia is defeated
	bool defeated();

	//Attack function
	int attack();

	//Defense function
	bool defense(int);

	//Checks if player's weapon is effective
	int checkWeapon(Item *);

	//Get and set functions
	std::string getName() { return name; }
	void setName(std::string n) { name = n; }
	int getHealth() { return health; }
	void setHealth(int h) { health = h; }
	int getStrength() { return strength; }
	void setStrength(int s) { strength = s; }
	std::string getWeapon() { return effectiveWeapon; }
	void setWeapon(std::string w) { effectiveWeapon = w; }

	//Destructor
	~Death() {};
};

#endif // !DEATH_H