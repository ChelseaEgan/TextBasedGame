/***************************************************************
** Project Name: Final Project
** Author: Chelsea Egan
** Date: 06/11/2017
** Class Name: Menu
** Description: Holds the members of the menu class, which
** displays a menu and calls functions based on user input
***************************************************************/
#ifndef MENU_H
#define MENU_H
#include "inputvalidation.h"

class Menu
{
private:
	//Holds the user's input
	int choice;

	//Input validation object
	InputValidation *userInput;

public:
	//Constructor
	Menu();

	//Prints the phobia menu to the screen
	void phobiaMenu();

	//Prints the inventory menu to the screen
	void inventoryMenu();

	//Prints the fight menu to the screen
	void fightMenu();

	//Prints the game menu to the screen
	void gameMenu();

	//Processes the user's input and returns selection
	int action(int);

	//Destructor
	~Menu();
};

#endif // !MENU_H