#ifndef ITEM_H
#define ITEM_H

#include <string>

//Structure to hold items
//Items include weapons, health potions, and gems
struct Item
{
	std::string name;
	int strength;
	std::string message;
};

#endif // !ITEM_H
