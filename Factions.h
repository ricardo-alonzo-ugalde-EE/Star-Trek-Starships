/*
Declarations.cpp
Ricard Alonzo Ugalde
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
Final Project
*/

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
using std::cout;
using std::endl;
using std::string;


/*
abstact base clase
*/
class Factions 
{
public:
	
	
	
	/*
	base virtual function that can be overriden by derived classes
	
	*/
public:
	virtual void createNewShip(int x) = 0; // pure virtual function that ccreates ships 
	virtual string createNewCharacter() = 0; // pure virtual function that creates a new character
	virtual void createNewPlanet() = 0; // pure virtual function taht creates a new character
	virtual void getForcePower(int& x) = 0; // pure virtual function that gets a new force power
	virtual void swapPowerLevel(int* x, int* y) = 0; // pure virtual functions that is used to train
	virtual int enemyCreate() = 0; // pure virtual function that creates a new enemy
	virtual void enemyNameCreate() = 0; // pure virtual function 
	virtual void getLightsaberForm(int x) = 0; // pure virtual function that calls the lightsaber forms
	
};

class rebelAlliance : public Factions
{
public:
	
	void createNewShip(int x); // function that creates a new republic ship
	string createNewCharacter(); // generates a randon rebel name 
	void createNewPlanet();	// calls a planet name 
	void getForcePower(int& x); // some rebels may e able to use force powers in a future version
	void swapPowerLevel(int* x, int* y); // this function allows the character to power up via training
	int enemyCreate(); // creates an empire enemy. rebels fight empire only for now
	void enemyNameCreate(); // Function to pas by pointer to generate a random name
	void getLightsaberForm(int x); // some rebels may use lightsabers wihtout being jedi
	
		
};

class jediOrder : public Factions
{
public:

	void createNewShip(int x); // function that creates a new republic ship
	string createNewCharacter(); // function that creates a new character
	void createNewPlanet(); // creates a new jedi order planet
	void getForcePower(int& x); // calls a force power to use duuring combat
	void swapPowerLevel(int* x, int* y); // train with Grandmaster Yoda for a chance to improve.
	int enemyCreate(); // creates a sith only enemy. may fight empire at some point
	void enemyNameCreate(); // Function to pas by pointer to generate a random name
	void getLightsaberForm(int x);
	


};

class galacticEmpire : public Factions
{
public:
	void createNewShip(int x); // function that creats a new galactic empire ship
	string createNewCharacter(); // function that creates a new character
	void createNewPlanet(); // function that creates a new Jedi Planet
	void getForcePower(int& x); // some empire soldiers may be force sensitive
	void swapPowerLevel(int* x, int* y); // follow Thrawn's orders and train
	int enemyCreate(); // create an enemy from the rebel alliance
	void enemyNameCreate(); // Function to pas by pointer to generate a random  name
	void getLightsaberForm(int x); // some empire members may use lightsabers
	

	
};

class sithOrder : public Factions, public galacticEmpire
{
public:
	void createNewShip(int x); // function that creats a new galactic empire ship
	string createNewCharacter(); // function that creates a new character
	void createNewPlanet(); // cretes a new sith planet
	void getForcePower(int& x); // calls on the dark side of the force to channel a force power
	void swapPowerLevel(int* x, int* y); // commit an atrocious act to gain strength
	int enemyCreate(); // creates a jedi enemy
	void enemyNameCreate(); // Function to pas by pointer to generate a random Jedi name
	void getLightsaberForm(int x); // requests all forms and randomly selects one
	
	



};
