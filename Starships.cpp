#include <iostream>
using std::cout;
using std::endl;
#include "Starships.h"


void Starship::setPhotonTorpedoPower(int a)
{
	attackPower = a;
}

void Galaxy::attack()
{
	cout << "NCC-1701 Fire! -" << attackPower << endl;
};

void Constitution::attack()
{
	cout << "NCC-1701 Fire! - " << attackPower << endl;
};