/***************************************************************
** Project Name: Final Project
** Author: Chelsea Egan
** Date: 06/11/2017
** Class Name: InputValidation
** Description: Holds the members of the InputValidation class,
** which tests user input for type and range
***************************************************************/
#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <string>

#define S_LENGTH 151

class InputValidation
{
private:

	static const int BUFFER = 256;

	//Holds user input
	char holdInput[BUFFER];

	//Holds user's string
	std::string userString;

	//Holds an integer input
	int intInput;

	//Holds the maximum in a range of integers
	int maxIntRange;

	//Holds the minimum in a range of integers
	int minIntRange;

	//Holds a double input
	double doubleInput;

	//Holds the maximum in a range of doubles
	double maxDoubleRange;

	//Holds the minimum in a range of doubles
	double minDoubleRange;

	//Holds y or n for user input
	char yesOrNo;

	//Stores whether an input is valid
	bool valid;
public:
	//Default Constructor
	InputValidation();

	//Validates input is an integer when range is not needed
	int validateInteger();

	//Validates that the input is an integer in range
	int validateIntAndRange(int, int);

	//Validates the input is an integer
	bool integerInputValidation(char *userInput) const;

	//Validates the input is in range
	bool intMinMaxValidation() const;

	//Validates the input is a positive integer
	int validatePosInt();

	//Validates that the input is a double in range
	double validateDoubleAndRange(double, double);

	//Validates that the input is a double
	bool doubleInputValidation(char *userInput) const;

	//Validates that the double input is in range
	bool doubleMinMaxValidation() const;

	//Validates that the input is a positive double
	double validatePosDouble();

	//Validates a y or n input
	char validateYesOrNo();

	//Validates a string
	std::string validateString();
};

#endif // !INPUTVALIDATION_H
