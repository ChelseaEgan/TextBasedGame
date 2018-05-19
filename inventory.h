#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"
#include "inputvalidation.h"

#include <iostream>

class Inventory
{
protected:
	//Node to hold each item in inventory
	struct ItemNode
	{
		//Pointer to the item
		Item * loot;

		//Pointer to next node in list
		ItemNode * next;

		//Constructor
		ItemNode(Item * newItem = NULL, ItemNode * nextPtr = NULL)
		{
			loot = newItem;
			next = nextPtr;
		}
	};
private:
	//Pointer to head of list
	ItemNode * head;

	//Current size of list
	int size;

	//Max size of list
	const int maxSize = 10;

	//InputValidation object
	InputValidation * userInput;
public:
	//Constructor
	Inventory();

	//Destructor
	~Inventory();

	//Add new item to inventory
	void add(Item * newItem);

	//Remove item from inventory
	Item * remove();

	//Display all items in inventory
	void display();

	//Check if inventory is empty
	bool isEmpty();

	//Get size of inventory
	int getSize();

	//Get five gems
	bool getGems();

	//Create sword of immortality
	void createSword();

	//Clear inventory
	void clear();
};

#endif // !INVENTORY_H
