#ifndef GERMS_H
#define GERMS_H

#include "phobia.h"
#include "item.h"
#include "inputvalidation.h"

#include <iostream>

class Germs : public Phobia
{
private:
	//Name of phobia
	std::string name = "The Germs";

	//Phobia's health points
	int health = 50;
	int maxHealth = 50;

	//Strength of attacks
	int strength = 50;

	//Name of weapon that the phobia is vulnerable to
	std::string effectiveWeapon = "Disinfectant";

	//Messages to use during attacks
	std::string attackMessages =
		"The Germs mutate - maybe it's the next superbug!\n\n";

	//Messages to use during defense
	std::string defenseMessages =
		"The Germs try to resist the cleansing chemicals!\n\n";
public:
	//Constructor
	Germs() {};

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
	~Germs() {};
};

#endif // !GERMS_H