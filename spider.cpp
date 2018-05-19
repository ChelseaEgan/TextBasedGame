#include "spider.h"
#include "phobia.h"

#include <iostream>

//Runs when phobia is defeated
bool Spider::defeated()
{
	//Print message about gem
	std::cout << name << " has been defeated!\n";
	std::cout << "You receive a gem!\n\n";

	//Set flag to true
	phobiaDefeated = true;

	//Generate random percentage to see if HP is dropped
	int dropHP = rand() % 2;

	//If dropHP is 1, the player gets a HP
	if (dropHP = 1)
	{
		std::cout << name << " dropped a health potion!\n";
		std::cout << "It has been added to your inventory.\n\n";
		return true;
	}
	else
	{
		return false;
	}
}

//Attack function
int Spider::attack()
{
	//Print message
	std::cout << attackMessages << std::endl;

	//Generate a random number to determine if successful hit
	int chanceHit = rand() % 100;

	//If chanceHit is less than strength
	if (chanceHit < strength)
	{
		//Return a random number between 1 and strength
		//This is the attack power
		return rand() % strength + 1;
	}
	else
	{
		//Hit was unsuccessful
		std::cout << name << "'s attack was "
			<< "unsuccessful!\n\n";
		//The attack does 0 damage
		return 0;
	}
}

//Defense function
bool Spider::defense(int damage)
{
	//If the player's attack was successful
	if (damage > 0)
	{
		//Print message
		std::cout << defenseMessages << std::endl;

		//Calculate health lost
		health -= damage;

		std::cout << "Health of " << name << ": " << health << "\n\n";
	}
	//If the phobia has died
	if (health <= 0)
	{
		phobiaDefeated = true;
	}
	return phobiaDefeated;
}

//Checks if player's weapon is effective
int Spider::checkWeapon(Item * weapon)
{
	if (weapon->name != effectiveWeapon)
	{
		std::cout << "That weapon is not very effective against "
			<< name << std::endl;
		std::cout << "Weapon's strength is reduced to 25%\n\n";
		return 4;
	}
	else
	{
		std::cout << name << " is vulnerable to attacks from this "
			<< "weapon!\n\n";
		return 1;
	}
}