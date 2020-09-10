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
	but why???
	*/
public:
	virtual void createNewShip(int x) = 0; // pure virtual function that ccreates ships 
	virtual string createNewCharacter() = 0; // pure virtual function that creates a new character
	virtual void createNewPlanet() = 0; // pure virtual function taht creates a new character
	virtual void getForcePower(int& x) = 0;
	virtual void swapPowerLevel(int* x, int* y) = 0;
	virtual int enemyCreate() = 0;
	virtual void enemyNameCreate() = 0; // Function to pas by pointer to generate a random Jedi name
	virtual void getLightsaberForm(int x) = 0;
	
};

class rebelAlliance : public Factions
{
public:
	
	void createNewShip(int x); // function that creates a new republic ship
	string createNewCharacter();
	void createNewPlanet();
	void getForcePower(int& x);
	void swapPowerLevel(int* x, int* y);
	int enemyCreate();
	void enemyNameCreate(); // Function to pas by pointer to generate a random name
	void getLightsaberForm(int x);
	
		
};

class jediOrder : public Factions
{
public:

	void createNewShip(int x); // function that creates a new republic ship
	string createNewCharacter(); // function that creates a new character
	void createNewPlanet();
	void getForcePower(int& x);
	void swapPowerLevel(int* x, int* y);
	int enemyCreate();
	void enemyNameCreate(); // Function to pas by pointer to generate a random name
	void getLightsaberForm(int x);
	


};

class galacticEmpire : public Factions
{
public:
	void createNewShip(int x); // function that creats a new galactic empire ship
	string createNewCharacter(); // function that creates a new character
	void createNewPlanet(); // function that creates a new Jedi Planet
	void getForcePower(int& x);
	void swapPowerLevel(int* x, int* y);
	int enemyCreate();
	void enemyNameCreate(); // Function to pas by pointer to generate a random  name
	void getLightsaberForm(int x);
	

	
};

class sithOrder : public Factions, public galacticEmpire
{
public:
	void createNewShip(int x); // function that creats a new galactic empire ship
	string createNewCharacter(); // function that creates a new character
	void createNewPlanet();
	void getForcePower(int& x);
	void swapPowerLevel(int* x, int* y);
	int enemyCreate();
	void enemyNameCreate(); // Function to pas by pointer to generate a random Jedi name
	void getLightsaberForm(int x);
	
	



};
