#include "inventory.h"

//Constructor
Inventory::Inventory()
{
	//Set head to NULL indicating inventory is empty
	head = NULL;

	//Initialize size as zero
	size = 0;

	//Create InputValidation object
	userInput = new InputValidation;
}

//Destructor
Inventory::~Inventory()
{
	//Call clear function to delete all items in inventory
	clear();

	//Delete InputValidation object
	delete userInput;
}

//Add new item to inventory
void Inventory::add(Item * newItem)
{
	//If inventory is empty
	if (isEmpty())
	{
		//Create new node at head of list
		head = new ItemNode(newItem, NULL);
		size++;
	}
	//If inventory is not empty
	else
	{
		//Traverse inventory to end
		ItemNode * nodePtr = head;
		while (nodePtr->next != NULL)
		{
			nodePtr = nodePtr->next;
		}
		//Create new node at end of list
		nodePtr->next = new ItemNode(newItem, NULL);
		
		//Increment size counter
		size++;
	}
}

//Remove item from inventory
Item * Inventory::remove()
{
	//If inventory is empty
	if (isEmpty())
	{
		//Print message and return NULL
		std::cout << "Your inventory is empty!\n";
		std::cout << "Try to find items in rooms or by defeating "
			<< "phobias.\n\n";
		return NULL;
	}
	else
	{
		//Display the list
		display();

		//Provide option to exit menu
		std::cout << size + 1 << ". Exit menu\n\n";

		//Prompt user for choice
		std::cout << "Which item would you like to pick?\n\n";

		//Get user choice
		int choice = userInput->validateIntAndRange(1, size + 1);

		//Traverse list to choice
		if (choice != size + 1)
		{
			//Counter to mark position in list
			int counter = 1;

			//Pointer to traverse list
			ItemNode * nodePtr = head;
			ItemNode * previousNodePtr = NULL;

			while (counter < choice)
			{
				previousNodePtr = nodePtr;
				nodePtr = nodePtr->next;
				counter++;
			}

			//If the node is not empty
			if (nodePtr != NULL)
			{
				if (nodePtr == head)
				{
					head = head->next;
				}
				else
				{
					//Unlink node
					previousNodePtr->next = nodePtr->next;
				}

				//Print message
				std::cout << "You have chosen the "
					<< nodePtr->loot->name;
				std::cout << std::endl << std::endl;

				//Store item in order to return
				Item * tempPtr = nodePtr->loot;

				//Delete item
				delete nodePtr;

				//Decrement size
				size--;

				return tempPtr;
			}
			//If the node is empty
			else
			{
				//Print error message and return NULL
				std::cout << "There is no item in that slot.\n\n";
				return NULL;
			}
		}
		//If user chose to exit menu
		if (choice == size + 1)
		{
			std::cout << "Returning to game...\n\n";
			return NULL;
		}
	}
}

//Display all items in inventory
void Inventory::display()
{
	//Pointer to traverse list
	ItemNode * nodePtr = head;

	//Counter to indicate position in list
	int counter = 1;

	std::cout << "Inventory:\n";

	//Traverse until end
	while (nodePtr)
	{
		std::cout << counter;
		std::cout << ". ";
		std::cout << nodePtr->loot->name;
		std::cout << std::endl;

		//Move to next node
		nodePtr = nodePtr->next;
		//Increment counter
		counter++;
	}
}

//Check if inventory is empty
bool Inventory::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Get size of inventory
int Inventory::getSize()
{
	return size;
}

//Check if there are five gems and remove from inventory
//Used to create sword of immortality
bool Inventory::getGems()
{
	//Pointer to traverse list
	ItemNode * nodePtr = head;

	//Gems counter
	int gemsCounter = 0;

	//Position of gems
	int positionArray[5];
	
	//Current position counter
	int posCounter = 1;

	//Traverse list
	while (nodePtr)
	{
		if (nodePtr->loot->name == "gem")
		{
			gemsCounter++;
			positionArray[gemsCounter - 1] = posCounter;
		}

		//Move to next node
		nodePtr = nodePtr->next;

		//Increment position
		posCounter++;
	}

	//If there are not enough gems (need 5)
	if (gemsCounter < 5)
	{
		std::cout << "There are not enough gems to create the\n"
			<< "Sword of Immortality.\n";
		std::cout << "You can get more gems by defeating phobias.\n\n";

		return false;
	}
	//If there are at least 5 gems
	else
	{
		//Pointer to traverse list
		ItemNode * nodePtr = head;

		//Remove gems from inventory
		for (int index = 0; index < 5; index++)
		{
			int counter = 1;

			//Find gem node
			while (counter < positionArray[index])
			{
				nodePtr = nodePtr->next;
				counter++;
			}

			//Delete gem
			delete nodePtr->loot;

			//Set loot to NULL indicating gem was deleted
			nodePtr->loot = NULL;

			//Return to head of list
			nodePtr = head;
		}

		ItemNode * previousNodePtr;

		while (nodePtr)
		{
			//Determine if the first node was a gem
			if (head->loot == NULL)
			{
				//Link head to next node in inventory
				nodePtr = head;
				head = head->next;

				//Delete the old head
				delete nodePtr;

				nodePtr = head;
			}

			//If not the head, move to next item
			else
			{
				nodePtr = head;

				//Skip nodes that did not hold a gem
				while (nodePtr != NULL && nodePtr->loot != NULL)
				{
					previousNodePtr = nodePtr;
					nodePtr = nodePtr->next;
				}


				//If node used to contain a gem and is now NULL
				if (nodePtr && nodePtr->loot == NULL)
				{
					//Link previous node to node after nodePtr
					previousNodePtr->next = nodePtr->next;

					//Delete nodePtr with a NULL item
					delete nodePtr;

					//Decrement size
					size--;

					//Move to next node
					nodePtr = previousNodePtr->next;
				}				
			}
		}
		createSword();
		return true;
	}
}

//Create the Sword of Immortality
void Inventory::createSword()
{
	//If inventory is full
	while (size >= 10)
	{
		std::cout << "Your inventory is full.\n";
		std::cout << "Please choose an item to drop.\n\n";

		//Dummy parameter to hold dropped item
		Item * dummy;

		//Drop an item
		dummy = remove();
	}

	//Create new Item to hold Sword of Immortality
	Item * sword;

	sword = new Item;
	sword->name = "Sword of Immortality";
	sword->strength = 60;
	sword->message = 
		"You swing the Sword of Immortality in a glowing arc.\n\n";
	
	add(sword);

	std::cout << "You have created the Sword of Immortality!\n";
	std::cout << "This is the only weapon that can defeat Death!\n";
	std::cout << "Use this weapon in your fight against death and\n"
		<< "defeat him to escape.\n\n";
}
//Clear inventory
void Inventory::clear()
{
	//Pointer to traverse list
	ItemNode * nodePtr = head;

	//While list is not empty
	while (nodePtr)
	{
		//Pointer to store node to be deleted
		ItemNode * garbage = nodePtr;

		//Move to next node
		nodePtr = nodePtr->next;

		//Delete item in node
		delete garbage->loot;

		//Delete node
		delete garbage;
	}
}