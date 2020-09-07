/*
Declarations.cpp
Ricard Alonzo Ugalde
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
Final Project
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;


/*
Features sub classes can inherit from Starship base class
warp drive
long range scanner
transporter
photon torpedos
*/
class Factions // Base class
{
	
	/*
	base virtual function that can be overriden by derived classes
	but why???
	*/
public:
	virtual void createNewShip() = 0; // pure virtual function that ccreates ships 
	virtual void createNewCharacter() = 0; // pure virtual function that creates a new character
	

};

class galacticRepublic : public Factions
{
public:
	
	void createNewShip(); // function that creates a new republic ship
	void createNewCharacter(); // function that creates a new character
	
	
};

class galacticEmpire : public Factions
{
public:
	void createNewShip(); // function that creats a new galactic empire ship
	void createNewCharacter(); // function that creates a new character
	
};
