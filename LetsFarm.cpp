/***************************************************************************//**
 * @file 
 * 
 * @brief This file contains all the functions required for this interactive 
 * fiction game.  
 * 
 *
 * @author Brandon Amundson
 * 
 ******************************************************************************/
#pragma once
#include "LetsFarm.h"

/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function gets players name from console and returns it to main as a string.
 * Also outputs introduction.
 *
 * @param[] none
 *
 * @returns playersName - string entered from console, used as players name.
 ******************************************************************************/
string welcomeUser()
{
	string playersName;
	cout << "Welcome to a gardening adventure!" << endl;
	cout << "What is your name? ";
	cin >> playersName;
	cout << endl << playersName << " get ready to garden!\n" << endl;
	cout << playersName << ", You are in your garden. You look around and see a barren plot of land. ";
	cout << "Let's make this plot look beautiful.\n" << endl;

	return playersName;
}

/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function that outputs user's name from prior function and gets input on what
 * user would like to do.
 *
 * @param[in] userName - used in outputting question asking what the user would
 *                       like to do.
 *
 * @returns usersChoice - choice choosen by user to be used elsewhere in program.
 ******************************************************************************/
string getChoice(string userName)
{
	string usersChoice;
	cout << endl << userName << ", What would you like to do?" << endl;
	cout << "Plant, Water, Wait, or Quit? ";
	cin >> usersChoice;
	return usersChoice;
}

/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function that gets user input for an integer between 1 and 10.  Has some error
 * checking for a valid answer.
 *
 * @param[] none
 *
 * @returns choice - user input integer between 1 and 10.
 ******************************************************************************/
int getWaitTime()
{
	int choice = 0;
	cout << "\n\nEnter a number between 1 and 10. " << endl;
	cin >> choice;
	if (choice < 1 || choice > 10)
	{
		cout << "Invalid entry, please try again.";
		getWaitTime();
	}
	else
		return choice;
}

/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function that takes the usersChoice and makes each character uppercase.
 *
 * @param[in, out] usersChoice - user input choice, returned once all letters
 *                               are converted to uppercase.
 *
 * @returns none
 ******************************************************************************/
void choiceConversion(string &usersChoice)
{
	for (unsigned int i = 0; i < usersChoice.length(); i++)
		usersChoice[i] = toupper(usersChoice[i]);
}

/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function provides various output paths based on prior inputs.
 * 
 *
 * @param[in] countPlants - used for different outputs based on if user has ever
 *                          chosen plant as their option.
 * @param[in] countWaters - used for different outputs based on if user has ever
 *                          chosen water as their option.
 *
 * @returns none
 ******************************************************************************/
void waitOutput(int countPlants, int countWaters)
{
	int choice = 0;
	if (countPlants > 0 && countWaters > 0)
	{
		choice = getWaitTime();
		cout << "\nYou watch for " << choice << " year(s) as your plants grow bigger.";
	}
	else if (countPlants > 0 && countWaters == 0)
	{
		cout << "\nYou stare at the seeds you planted as if you hope they will magically grow without water.";
	}
	else if (countWaters > 0 && countPlants == 0)
	{
		choice = getWaitTime();
		cout << "\nYou wait " << choice << " hour(s) while the mud dries.";
	}
	else
		cout << "\nYou haven't planted anything.  You continue to look at your barren plot of land.\n";
}

/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function provides various output paths based on prior inputs.
 *
 * @param[in] countPlants - used for different outputs based on if user has ever
 *                          chosen plant as their option.
 *
 * @param[in, out] countWaters - used for different outputs based on if user
 *                               has ever chosen water as their option.
 *                               Incremented each function call.
 *
 * @returns none
 ******************************************************************************/
void waterOutput(int countPlants, int &countWaters)
{
	if (countPlants > 0)
	{
		cout << "\nYou water your garden. Slowly, you watch as your plants start to sprout" << endl;
		countWaters++;
	}
	else
	{
		cout << "\nCongratulations, you just made some mud.  Try to plant seeds first.\n" << "Have fun doing that with the muddy mess you created.\n\n";
		countWaters++;
	}
}

/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function that outputs seed planting and increments function call counter.
 *
 * @param[in] countPlants - used for different outputs based on if user has ever
 *                          chosen plant as their option.  Incremented each time
 *                          the function is called.
 *
 * @returns countPlants variable once incremented.
 ******************************************************************************/
int plantOutput(int countPlants)
{
	cout << endl << "You plant some seeds. ";
	cout << "These will need some water if it is ever going to grow." << endl;
	countPlants++;
	return countPlants;
}
