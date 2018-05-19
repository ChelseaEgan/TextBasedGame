#include "room.h"
#include "phobia.h"
#include "game.h"
#include "menu.h"
#include "inputvalidation.h"
#include "inventory.h"

#include <iostream>
#include <ctime>
#include <stdlib.h>

int main()
{
	//Game object
	Game newGame;

	//Start game
	newGame.startGame();

	//Game status
	//1 = user selects quit
	//2 = keep playing
	//3 = user loses
	//4 = user wins (defeats Death)
	int status = 2;

	while (status == 2)
	{
		status = newGame.loop();
	}

	if (status == 3)
	{
		std::cout << "You are overcome by fear!\n";
		std::cout << "You have lost the game.\n\n";
		std::cout << "Hopefully you're braver next time.\n\n";
	}
	else if (status == 4)
	{
		std::cout << "By defeating death, you have overcome all "
			<< "of your fears!\n";
		std::cout << "You have escaped the building and won the "
			<< "game!\n";
		std::cout << "Thanks for playing!!\n";
	}
	else if (status == 1)
	{
		std::cout << "Thanks for playing!\n\n";
	}
	return 0;


}