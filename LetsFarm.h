#pragma once
#include <iostream> // input/output library
#include <string> // used to create string variables
#include <cctype> // used to take user input and make every variable uppercase in program.
using namespace std;


// function templates
string welcomeUser(); //returns string
string getChoice(string userName); //takes string as param
int getWaitTime(); //returns int
void choiceConversion(string &usersChoice);
void waitOutput(int countPlants, int countWaters); // takes int params
void waterOutput(int countPlants, int &countWaters); // takes and returns int params
int plantOutput(int countPlants); // takes and returns int param

//Possible splits for more header files below.  Could be done but is unnecessary?...
//Header 1 Welcome & choice functions -  welcomeUser -> getChoice -> choiceConversion
//Header 2 Output & related Functions - waitOutput -> getWaitTime || plantOutput || waterOutput