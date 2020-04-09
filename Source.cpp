/***************************************************************************//**
 * @file
 * @brief Interactive Farming Game
 *
 * @mainpage Program: Lets Farm
 *
 * @section course_section Course Information
 *
 * @authors Brandon Amundson
 *
 * @date February 09, 2020
 *
 * @par Instructor:
 *         Professor Tony Hinton
 *
 * @par Course:
 *         CSC 215 01:30 pm
 *
 * @par Location:
 *         UAT Campus - Room 108
 *
 * @section program_section Program Information
 *
 * @details
 * Interactive Farming Fiction Game.
 *
 *
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   Just run the program, no input needed
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug
 *
 * @todo
 *
 *
 * @par Modifications and Development Timeline:
   @verbatim
   Date          Modification
   ------------  ---------------------------------------------------------------
   Feb 27, 2020  Started with a template file, had a few functions and modified
				 as necessary
   Mar 02, 2020  Wrote the storyline and reworked template file to put all
				 functions going through main as required by the assignment.
				 Added documentation to code and finished the assignment.

   @endverbatim
 *
 ******************************************************************************/
#pragma once
#include "LetsFarm.h"

/***************************************************************************//**
 * @author Brandon Amundson
 *
 * @par Description:
 * Function calls all other functions to welcome the user and get user input to 
 * continue the storyline.  Also calls a function to take string input from console
 * and make it all uppercase to reduce code needed for while loop.
 * 
 * @param[] none
 *
 * @returns 0 - no errors
 ******************************************************************************/
int main()
{
	int countPlants = 0;
	int countWaters = 0;

	string userName = welcomeUser(); // gets user name and outputs intro for program.
	string usersChoice = getChoice(userName); //gets users first choice for game
	choiceConversion(usersChoice); // converts users choice to uppercase string
	while (usersChoice != "QUIT")
	{
		if (usersChoice == "PLANT")
			countPlants = plantOutput(countPlants); // calls plant output function to plant seeds
                                                       // and increment countPlants, stored back into count plants.
		else if (usersChoice == "WATER")
			waterOutput(countPlants, countWaters); // calls water output function and returns when finished.
		else if (usersChoice == "WAIT")
			waitOutput(countPlants, countWaters); // calls wait output function and returns when finished.
		else
			cout << userName << ", I am sorry I do not understand your command" << endl; // used as an invalid entry check.

		usersChoice = getChoice(userName);// gets users next choice
		choiceConversion(usersChoice); // converts users choice to uppercase string
	}

	system("pause");
	return(0);
}