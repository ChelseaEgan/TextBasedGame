/***************************************************************
** Project Name: Final Project
** Author: Chelsea Egan
** Date: 06/11/2017
** Class Name: Menu
** Description: This is the implementation file for the menu
** class
***************************************************************/
#include "menu.h"
#include <iostream>

/***************************************************************
** Function Name: constructor
** Arguments: none
** Returns: n/a
** Description: Creates the Input Validation object
***************************************************************/
Menu::Menu()
{
	userInput = new InputValidation();
}

/***************************************************************
** Function Name: phobiaMenu
** Arguments: none
** Returns: void
** Description: Prints the menu of all phobias
***************************************************************/
//Prints the phobia menu to the screen
void Menu::phobiaMenu()
{
	std::cout << "   Match the Phobia\n";
	std::cout << "1. Fear of spiders\n";
	std::cout << "2. Fear of ducks\n";
	std::cout << "3. Fear of ghosts\n";
	std::cout << "4. Fear of germs\n";
	std::cout << "5. Fear of clowns\n";
	std::cout << "6. Fear of death\n\n";
}

/***************************************************************
** Function Name: inventoryMenu
** Arguments: none
** Returns: void
** Description: Prints the menu of all options for inventory
***************************************************************/
void Menu::inventoryMenu()
{
	std::cout << "   Inventory Menu\n";
	std::cout << "1. View items\n";
	std::cout << "2. Drop item\n";
	std::cout << "3. Choose item\n";
	std::cout << "4. Put current weapon back in inventory\n";
	std::cout << "5. Create Sword of Immortality (needs 5 gems)\n";
	std::cout << "6. Return to game\n\n";
}

/***************************************************************
** Function Name: fightMenu
** Arguments: none
** Returns: void
** Description: Prints the options during fights
***************************************************************/
void Menu::fightMenu()
{
	std::cout << "   Fight Menu\n";
	std::cout << "1. Attack\n";
	std::cout << "2. Get an item or weapon from your bag\n";
	std::cout << "3. Stop fighting\n\n";
}

/***************************************************************
** Function Name: gameMenu
** Arguments: none
** Returns: void
** Description: Prints the game menu
***************************************************************/
void Menu::gameMenu()
{
	std::cout << "   Game Menu\n";
	std::cout << "1. View my health\n";
	std::cout << "2. View equipped item\n";
	std::cout << "3. Move to another room\n";
	std::cout << "4. View inventory menu\n";
	std::cout << "5. Explore the room\n";
	std::cout << "6. Fight\n";
	std::cout << "7. Pick up item in room\n";
	std::cout << "8. Exit game\n\n";
}

/***************************************************************
** Function Name: action
** Arguments: n/a
** Returns: void
** Description: Based on integer parameter, calls correct menu
** and processes user choice
***************************************************************/
int Menu::action(int menu)
{
	//Display list of phobias
	if (menu == 1)
	{
		phobiaMenu();
		//Get user input and validate it's an integer in range
		choice = userInput->validateIntAndRange(1, 6);
	}
	//Display options for inventory
	else if (menu == 2)
	{
		inventoryMenu();
		//Get user input and validate it's an integer in range
		choice = userInput->validateIntAndRange(1, 6);
	}
	//Display options for fight
	else if (menu == 3)
	{
		fightMenu();
		//Get user input and validate it's an integer in range
		choice = userInput->validateIntAndRange(1, 3);
	}
	//Display game menu
	else if (menu == 4)
	{
		gameMenu();
		//Get user input and validate it's an integer in range
		choice = userInput->validateIntAndRange(1, 8);
	}

	return choice;
}

/***************************************************************
** Function Name: Destructor
** Arguments: n/a
** Returns: n/a
** Description: Deletes storage allocated for the
** InputValidation object
***************************************************************/
Menu::~Menu()
{
	delete userInput;
}