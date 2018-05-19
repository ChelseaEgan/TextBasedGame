#include "death.h"
#include "phobia.h"

#include <iostream>

//Runs when phobia is defeated
bool Death::defeated()
{
	//Print message about gem
	std::cout << "You have defeated Death!\n\n";

	//Set flag to true
	phobiaDefeated = true;

	//Does not return a health potion
	return false;
}

//Attack function
int Death::attack()
{
	//Generate a random number to choose a message from array
	int msgNum = rand() % 3;

	//Print message
	std::cout << attackMessages[msgNum] << std::endl;

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
bool Death::defense(int damage)
{
	//If the player's attack was successful
	if (damage > 0)
	{
		//Generate a random number to choose a message from array
		int msgNum = rand() % 3;

		//Print message
		std::cout << defenseMessages[msgNum] << std::endl;

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
int Death::checkWeapon(Item * weapon)
{
	if (weapon->name != effectiveWeapon)
	{
		std::cout << "Death is only vulnerable to the Sword of "
			<< "immortality.\n";
		std::cout << "This weapon will not work.\n\n";
		return 0;
	}
	else
	{
		std::cout << name << " is vulnerable to attacks from this "
			<< "weapon!\n\n";
		return 1;
	}
}