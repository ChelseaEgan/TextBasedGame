#ifndef SPIDER_H
#define SPIDER_H

#include "phobia.h"
#include "item.h"
#include "inputvalidation.h"

#include <iostream>

class Spider : public Phobia
{
private:
	//Name of phobia
	std::string name = "The Spider";

	//Phobia's health points
	int health = 50;
	int maxHealth = 50;

	//Strength of attacks
	int strength = 50;

	//Name of weapon that Death is vulnerable to
	std::string effectiveWeapon = "Insect Repellant";

	//Messages to use during attacks
	std::string attackMessages = 
		"The Spider tries to sink its fangs into your chest!\n\n";

	//Messages to use during defense
	std::string defenseMessages = 
		"The Spider skitters away trying to avoid the poisonous spray!\n\n";
public:
	//Constructor
	Spider() {};

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
	~Spider() {};
};

#endif // !SPIDER_H