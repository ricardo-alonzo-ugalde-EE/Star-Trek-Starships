/*
Implementation.cpp
Ricard Alonzo Ugalde
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
Final Project
*/

#include <iostream>
#include <vector>
#include "Factions.h"
#include <iomanip>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::cin;
using std::setw;
using std::setfill;


// base virtual function that can be overriden by derived classes
void Factions::createNewShip()
{
	cout << "Light Speed Cabaple Frigate." << endl;
}

void Factions::createNewCharacter()
{
	cout << "Random Twilek Created" << endl;
}


void galacticRepublic::createNewShip()
{
	cout << "Naboo Starfighter Created" << endl;
};

void galacticRepublic::createNewCharacter()
{
	cout << "Luke Skywalker" << endl;
};


void galacticEmpire::createNewShip()
{
	cout << "Tie Fighter Created" << endl;
};

void galacticEmpire::createNewCharacter()
{
	cout << "Anakin Skywalker" << endl;
};