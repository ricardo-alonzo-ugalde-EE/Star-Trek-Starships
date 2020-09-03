#include <iostream>
using std::cout;
using std::endl;
#include "Starships.h"


int main()
{
	
	Galaxy Enterprise; // ninja object
	Constitution the_enterprise; //monster object

	Starship* ship1 = &Enterprise; // anything a enemy can do, a ninja can do
	Starship* ship2 = &the_enterprise; // ahything an enemy can do , a moster can do

	ship1->setPhotonTorpedoPower(130);
	ship2->setPhotonTorpedoPower(50);


	Enterprise.attack();
	the_enterprise.attack();

}