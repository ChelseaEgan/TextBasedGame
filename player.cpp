#include "player.h"

#include <ctime>
#include <stdlib.h>

//Constructor
Player::Player(std::string n)
{
	name = n;
	bag = new Inventory;
	playerMenu = new Menu;
	userInput = new InputValidation;
	location = NULL;
	weapon = NULL;
	healthPotion = NULL;
}

//Destructor
Player::~Player()
{
	delete bag;
	delete playerMenu;
	delete userInput;
}

//View inventory menu
void Player::inventoryMenu()
{
	int choice = playerMenu->action(2);

	if (choice != 6)
	{
		switch (choice)
		{
		case 1: viewInventory();
			break;
		case 2: dropItem();
			break;
		case 3: chooseItem();
			break;
		case 4: bag->add(weapon);
			weapon = NULL;
			break;
		case 5: createSword();
		}
	}
}

//Drink a health potion
void Player::takeHealthPotion()
{
	std::cout << "You drink a health potion.\n\n";

	//Calculate health regained as percentage of max health
	int regain = maxHealth / weapon->strength;

	//Add to health
	health += regain;

	//If health goes over max, set to max
	if (health >= maxHealth)
	{
		std::cout << "You have been restored to full health!\n\n";
		health = maxHealth;
	}
	else
	{
		std::cout << "Your health: " << health << std::endl;
	}
	healthPotion = NULL;
}

//Pick up item
void Player::pickupItem(Item * loot)
{
	//If inventory is full
	while (bag->getSize() >= 10)
	{
		std::cout << "Your inventory is full.\n";
		std::cout << "Please choose an item to drop.\n\n";

		//Dummy parameter to hold dropped item
		Item * dummy;

		//Drop an item
		dummy = bag->remove();
	}
	
	bag->add(loot);
}

//Pick up item from room
void Player::roomItem()
{
	Item * temp = location->pickUpItem();

	if (temp != NULL)
	{
		//If inventory is full
		while (bag->getSize() >= 10)
		{
			std::cout << "Your inventory is full.\n";
			std::cout << "Please choose an item to drop.\n\n";

			//Dummy parameter to hold dropped item
			Item * dummy;

			//Drop an item
			dummy = bag->remove();
		}

		bag->add(temp);
	}
}

//Choose weapon from inventory
void Player::chooseItem()
{
	//Temp pointer to hold item
	Item * temp = bag->remove();

	if (temp != NULL)
	{
		if (weapon != NULL)
		{
			bag->add(weapon);
			weapon = NULL;
		}
		weapon = temp;

		if (weapon->name == "Health Potion")
		{
			takeHealthPotion();
			delete weapon;
			weapon = NULL;
		}
	}
	else
	{
		weapon = NULL;
	}
}

//Drop item
void Player::dropItem()
{
	std::cout << "A dropped item cannot be picked up again.\n";
	std::cout << "Would you still like to drop an item?\n\n";
	char answer = userInput->validateYesOrNo();

	if (answer == 'Y')
	{
		std::cout << "Choose an item to drop:\n\n";

		//Temp pointer to hold dropped item
		Item * temp = bag->remove();

		delete temp;

		temp = NULL;
	}
	else
	{
		std::cout << "Returning to menu...\n\n";
	}
}

//Change room
Room * Player::changeRoom()
{
	location = location->changeRoom();
	return location;
}

//Get weapon's effectiveness
Item * Player::checkWeapon()
{
	//If user does not have a weapon equipped, choose weapon
	if (weapon == NULL)
	{
		std::cout << "You do not have a weapon equipped.\n";
		std::cout << "Choose a weapon to fight with:\n\n";
		chooseItem();
	}
	if (weapon != NULL)
	{	//Ask if user wants to change weapons
		std::cout << "You have the following weapon equipped: "
			<< weapon->name << std::endl;
		std::cout << "Would you like to choose another weapon? (Y/N)\n\n";
		
		char choice = userInput->validateYesOrNo();

		if (choice == 'Y')
		{
			std::cout << "Choose a weapon to fight with:\n\n";
			bag->add(weapon);
			weapon = NULL;
			chooseItem();
		}
		//If user chose a gem or health potion, ask for weapon
		while (weapon->strength == 0)
		{
			std::cout << "That is not a weapon.\n";
			std::cout << "Choose a weapon to fight with:\n\n";
			bag->add(weapon);
			weapon = NULL;
			chooseItem();
		}
	}
	return weapon;
}

//Fight
int Player::attack(int effectiveness)
{
	int tempWeaponStrength = weapon->strength;

	tempWeaponStrength = tempWeaponStrength / effectiveness;

	//Print message
	std::cout << weapon->message << std::endl;

	//Generate a random number to determine if successful hit
	int chanceHit = rand() % 100;

	//If chanceHit is less than strength
	if (chanceHit < strength)
	{
		//Return a random number between 1 and strength
		//This is the attack power
		int ad = rand() % tempWeaponStrength + 1;
		return ad;
	}
	else
	{
		//Hit was unsuccessful
		std::cout << "Your attack was unsuccessful.\n\n";
		//The attack does 0 damage
		return 0;
	}
}

//Defense
bool Player::defense(int damage)
{
	std::cout << "You try to deflect the attack.\n\n";
	//If the phobia's attack was successful
	if (damage > 0)
	{
		loseHealth(damage);
	}
	//If the person has died
	if (health <= 0)
	{
		return true;
	}
	return false;
}

//Lose health points
bool Player::loseHealth(int damage)
{
	health -= damage;

	//Print message
	std::cout << "You lose " << damage << " health points "
		<< "from the attack.\n\n";

	//If the player has died
	if (health <= 0)
	{
		return true;
	}
	return false;
}

//View inventory
void Player::viewInventory()
{
	bag->display();
}

//Create sword
void Player::createSword()
{
	bool successful = bag->getGems();
}