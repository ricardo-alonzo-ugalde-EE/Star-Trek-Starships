/*
main file.cpp
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



int main()
{   
    int fact_select = 0;
   


    // Main title sequence
    cout << setw(50) << "Star Wars: Factions" << setw(27) << "`" << endl;
    cout << setfill('`') << setw(77) << "`" << endl;
    cout << setw(50) << "Grand Space Exploration" << setw(27) << "`" << endl; ;
    cout << setfill('`') << setw(77) << "`" << "\n" << endl;
	
    // A vector of Starships Created
    vector<Factions*> ships;

   

	/*
     Adding two types of space objects: galactic and empire objects
    */
	ships.push_back(new galacticRepublic);
	ships.push_back(new galacticEmpire);
	

	/*
    iterating over vector(container) and calling create Starship function.
    So what this does, is it creates objects from subclasses where the 
    create function exists. only used for the create function. Other typ
    */

	for (int i = 0; i < ships.size(); i++) {

		ships[i]->createNewShip(); // this is how you access each item indiviidually just call [i]
        ships[i]->createNewCharacter(); // // this is how you access each item indiviidually just call [i]
        
	}
	
    cout << "Select Faction: " << endl;
    cin >> fact_select;

    if (fact_select == 1)
    {
        cout << "Empire Selected" << endl;
        ships[1]->createNewCharacter();
    }
        
    else
    {
        cout << "Rebel Scum Selected." << endl;
    }
       


    
    
     
    

    //// Sith name declaration
    //cout << "Chose and harness anger through your name: ";
    //cin >> sithApprentice.playerName;
    //cout << "The force is strong with you. A powerful sith you will become!\n" << endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    //cout << "Henceforth you shall be know as...!\n" << endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    //cout << "Darth... ";
    //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    //cout << "... ";
    //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    //cout << sithApprentice.playerName << "!!!!" << endl;
    //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    //cout << "Rise! Darth " << sithApprentice.playerName << "!!!! \n";
    //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    //cout << setfill('`') << setw(77) << "`" << endl;
	

	
}
















/*
	In C++, polymorphism causes a member function to behave
	differently based on the object that calls/invokes it.
	Only Certain functions are need to be subject to Polymorphism?
	*/


//tngEnterprise.setPhotonTorpedoPower(); // derived class overrdes base class function
//birdofPrey.setPhotonTorpedoPower(); // another derived class overrides base class function

///*
//anything a starship can do, an Enterprise can do
//This creates a pointer to the TNG enterprise, but why???
//*/
//Starships *ship1 = &tngEnterprise; 
//
//// anything a starship can do, a Constitution  Class Enterprise can doa moster can do
//Starships *ship2 = &birdofPrey;
///*
//setphotonTorpedo function used by enemy object 
//but pointing to address of galaxy class object?
//*/
//ship1->setPhotonTorpedoPower(); // Polymorphism? this is using 
//ship2->setPhotonTorpedoPower(); // Polymorphism?
