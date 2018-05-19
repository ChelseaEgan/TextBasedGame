/***************************************************************
** Project Name: Final Project
** Author: Chelsea Egan
** Date: 06/11/2017
** Class Name: InputValidation
** Description: This is the implementation file for the
** InputValidation class
***************************************************************/
#include "inputvalidation.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>

/**************************************************************
** Function name: InputValidation (Default Constructor)
** Arguments: n/a
** Returns: n/a
** Description: Default constructor
***************************************************************/
InputValidation::InputValidation()
{
	for (int i = 0; i < BUFFER; i++)
	{
		holdInput[i] = NULL;
	}
}

/**************************************************************
** Function name: validateInteger
** Arguments: None
** Returns: int holding the user's input as an integer
** Description: Calls functions to test whether the input is an
** integer
***************************************************************/
int InputValidation::validateInteger()
{
	do
	{
		//Set the flag to true
		valid = true;

		//Read in user's input into the char array
		std::cin.getline(holdInput, BUFFER);

		//Call the integerInputValidation function
		//If the input is not a integer
		if (!integerInputValidation(holdInput))
		{
			std::cout << "\n\nThat is not an integer.\n";
			//Set the flag to false
			valid = false;
		}

		//If the flag is still set to true
		if (valid == true)
		{
			//Convert the char array to an int
			intInput = std::atoi(holdInput);
		}

		//If the flag is set to false
		if (valid == false)
		{
			//Prompt user for a new input
			std::cout << "Enter an integer:\n";
		}
	} while (valid == false);
	//Loop while the flag is set to false

	//Once the input is validated, return
	return intInput;
}



/**************************************************************
** Function name: validateIntAndRange
** Arguments: integers holding range
** Returns: int holding the user's input as an integer
** Description: Calls functions to test whether the input is an
** integer and whether it's in range; if it's invalid, loops
** until it receives a valid input
***************************************************************/
int InputValidation::validateIntAndRange(int min, int max)
{
	//Set range variables
	minIntRange = min;
	maxIntRange = max;

	do
	{
		//Set the flag to true
		valid = true;

		//Read in user's input into the char array
		std::cin.getline(holdInput, BUFFER);

		//Call the integerInputValidation function
		//If the input is not a integer
		if (!integerInputValidation(holdInput))
		{
			std::cout << "\n\nThat is not an integer.\n";
			//Set the flag to false
			valid = false;
		}

		//If the flag is still set to true
		if (valid == true)
		{
			//Convert the char array to an int
			intInput = std::atoi(holdInput);

			//Call the intMinMaxValidation function
			//If the input is not within range
			if (!intMinMaxValidation())
			{
				//Print an error message
				std::cout << "That value is not in range.\n";
				//Set the flag to false
				valid = false;
			}
		}

		//If the flag is set to false
		if (valid == false)
		{
			//Prompt user for a new input
			std::cout << "Enter an integer between  "
				<< minIntRange << " and " << maxIntRange
				<< ":\n";
		}
	} while (valid == false);
	//Loop while the flag is set to false

	//Once the input is validated, return
	return intInput;
}

/**************************************************************
** Function name: integerInputValidation
** Arguments: char array for user input
** Returns: boolean value indicating whether input is an integer
** Description: Tests if the input is an integer by checking if
** each character is a digit or, if it's the first char, a +/-
** sign
***************************************************************/
bool InputValidation::integerInputValidation(char *userInput) const
{
	//Test if the first char is not a digit and is not a 
	//negative or positive sign
	if ((!std::isdigit(userInput[0])) &&
		(userInput[0] != '-') &&
		(userInput[0] != '+'))
	{
		return false;
	}
	//If the first char is a digit or +/-, test the rest
	else
	{
		for (int i = 1; i < std::strlen(userInput); i++)
		{
			//If it's not a digit
			if (!std::isdigit(userInput[i]))
			{
				return false;
			}
		}
	}

	return true;
}

/**************************************************************
** Function name: intMinMaxValidation
** Arguments: none
** Returns: boolean value indicating whether input is in range
** Description: Tests if the input is within the required range
***************************************************************/
bool InputValidation::intMinMaxValidation() const
{
	//Test if the integer is within range
	if (intInput < minIntRange || intInput > maxIntRange)
	{
		//If it's not, return false
		return false;
	}
	//Return true if it is within range
	return true;
}

/**************************************************************
** Function name: validatePosInt
** Arguments: None
** Returns: int holding the user's input as an integer
** Description: Calls functions to test whether the input is a
** positive integer
***************************************************************/
int InputValidation::validatePosInt()
{
	do
	{
		//Set the flag to true
		valid = true;

		//Read in user's input into the char array
		std::cin.getline(holdInput, BUFFER);

		//Call the integerInputValidation function
		//If the input is not a integer
		if (!integerInputValidation(holdInput))
		{
			std::cout << "\n\nThat is not an integer.\n";
			//Set the flag to false
			valid = false;
		}

		//If the flag is still set to true
		if (valid == true)
		{
			//Convert the char array to an int
			intInput = std::atoi(holdInput);

			//Test if input is negative
			if (intInput < 0)
			{
				//Print an error message
				std::cout << "That is a negative value.\n";
				//Set the flag to false
				valid = false;
			}
		}

		//If the flag is set to false
		if (valid == false)
		{
			//Prompt user for a new input
			std::cout << "Enter a positive integer:\n";
		}
	} while (valid == false);
	//Loop while the flag is set to false

	//Once the input is validated, return
	return intInput;
}


/**************************************************************
** Function name: validateDoubleAndRange
** Arguments: doubles for minimum and maximum range
** Returns: double holding the user's input as an double
** Description: Calls functions to test whether the input is a
** double and whether it's in range; if it's invalid, loops
** until it receives a valid input
***************************************************************/
double InputValidation::validateDoubleAndRange(double min, double max)
{
	//Set range variables
	minDoubleRange = min;
	maxDoubleRange = max;

	do
	{
		//Set the flag to true
		valid = true;

		//Read in user's input into the char array
		std::cin.getline(holdInput, BUFFER);

		//Call the integerInputValidation function
		//If the input is not a integer
		if (!doubleInputValidation(holdInput))
		{
			std::cout << "\n\nThat is not a double.\n";
			//Set the flag to false
			valid = false;
		}

		//If the flag is still set to true
		if (valid == true)
		{
			//Convert the char array to an int
			doubleInput = std::atof(holdInput);

			//Call the intMinMaxValidation function
			//If the input is not within range
			if (!doubleMinMaxValidation())
			{
				//Print an error message
				std::cout << "That value is not in range.\n";
				//Set the flag to false
				valid = false;
			}
		}

		//If the flag is set to false
		if (valid == false)
		{
			//Prompt user for a new input
			std::cout << std::setprecision(2) << std::fixed;
			std::cout << "Enter a double between  "
				<< minDoubleRange << " and " << maxDoubleRange
				<< ":\n";
		}
	} while (valid == false);
	//Loop while the flag is set to false

	//Once the input is validated, return
	return doubleInput;
}

/**************************************************************
** Function name: doubleInputValidation
** Arguments: char array for user input
** Returns: boolean value indicating whether input is a double
** Description: Tests if the input is a double by checking if
** each character is a digit, '+', '-', or '.'
***************************************************************/
bool InputValidation::doubleInputValidation(char *userInput) const
{
	//Tracks number of decimals to make sure there is only one
	int decimalCounter = 0;

	//Test if the first char is not a digit and is not a 
	//negative or positive sign or a decimal point
	if ((!std::isdigit(userInput[0])) && (userInput[0] != '-')
		&& (userInput[0] != '+')
		&& (userInput[0] != '.'))
	{
		return false;
	}
	//If the first char is a digit or +/- or ., test the rest 
	else
	{
		if (userInput[0] == '.')
		{
			decimalCounter++;
		}

		for (int i = 1; i < std::strlen(userInput); i++)
		{
			//If it's not a digit
			if (!std::isdigit(userInput[i])
				&& (userInput[i] != '.'))
			{
				return false;
			}
			if (userInput[i] == '.')
			{
				decimalCounter++;
			}

			//If too many decimals
			if (decimalCounter > 1)
			{
				return false;
			}
		}
	}

	return true;
}

/**************************************************************
** Function name: doubleMinMaxValidation
** Arguments: none
** Returns: boolean value indicating whether input is in range
** Description: Tests if the input is within the required range
***************************************************************/
bool InputValidation::doubleMinMaxValidation() const
{
	//Test if the integer is within range
	if (doubleInput < minDoubleRange ||
		doubleInput > maxDoubleRange)
	{
		//If it's not, return false
		return false;
	}
	//Return true if it is within range
	return true;
}

/**************************************************************
** Function name: validatePosDouble
** Arguments: None
** Returns: double holding the user's input as an double
** Description: Calls functions to test whether the input is a
** positive double
***************************************************************/
double InputValidation::validatePosDouble()
{
	do
	{
		//Set the flag to true
		valid = true;

		//Read in user's input into the char array
		std::cin.getline(holdInput, BUFFER);

		//Call the integerInputValidation function
		//If the input is not a integer
		if (!doubleInputValidation(holdInput))
		{
			std::cout << "\n\nThat is not a double.\n";
			//Set the flag to false
			valid = false;
		}

		//If the flag is still set to true
		if (valid == true)
		{
			//Convert the char array to an int
			doubleInput = std::atof(holdInput);

			//Test if double is positive
			if (doubleInput < 0)
			{
				//Print an error message
				std::cout << "That is not a positive value.\n";
				//Set the flag to false
				valid = false;
			}
		}

		//If the flag is set to false
		if (valid == false)
		{
			//Prompt user for a new input
			std::cout << "Enter a positive double:\n";
		}
	} while (valid == false);
	//Loop while the flag is set to false

	//Once the input is validated, return
	return doubleInput;
}

/**************************************************************
** Function name: validateYesOrNo
** Arguments: None
** Returns: char holding Y for Yes or N for No
** Description: Validates the user entered y, Y, n, or N
***************************************************************/
char InputValidation::validateYesOrNo()
{
	do
	{
		//Set the flag to true
		valid = true;

		//Read in user's input into the char array
		std::cin.getline(holdInput, BUFFER);

		//If the input is longer than one character
		if (holdInput[1] != NULL)
		{
			valid = false;
			std::cout << "\n\nThat is an invalid input.\n";
			std::cout << "Enter Y for yes or N for no:\n";
		}
		else
		{
			//Store the character as an uppercase letter
			yesOrNo = toupper(holdInput[0]);

			if (yesOrNo == 'Y')
			{
				return yesOrNo;
			}
			else if (yesOrNo == 'N')
			{
				return yesOrNo;
			}
			//Input was neither Y nor N
			else
			{
				valid = false;
				std::cout << "\n\nThat is an invalid input.\n";
				std::cout << "Enter Y for yes or N for no:\n";
			}
		}
	} while (valid == false);
}

/**************************************************************
** Function name: validateString
** Arguments: None
** Returns: String - user string
** Description: Validates the user did not enter an empty string
** or a string that starts with a space
***************************************************************/
std::string InputValidation::validateString()
{
	do
	{
		//Set the flag to true
		valid = true;

		//Read in user's input into the string
		getline(std::cin, userString);

		//If the input is empty or starts with a space
		if (userString[0] == NULL || userString[0] == ' ')
		{
			valid = false;
			std::cout << "\n\nThat is an invalid input.\n";
			std::cout << "Enter a string (up to " << S_LENGTH - 1
				<< " characters):\n";
		}
		//If the input is too long
		else if (userString.size() > (S_LENGTH - 1))
		{
			valid = false;
			std::cout << "\n\nThat string is too long.\n";
			std::cout << "Enter a string (up to " << S_LENGTH - 1
				<< " characters):\n";
		}
		//Input is valid
		else
		{
			return userString;
		}
	} while (valid == false);
}