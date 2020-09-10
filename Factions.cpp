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
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::cin;
using std::setw;
using std::setfill;

///////////////////////////////////////////////// GENERIC BASE
/* 
base virtual function in abstract base class Factions that can be overriden by derived classes
*/
void Factions::createNewShip(int x)
{
	cout << "Light Speed Cabaple Frigate." << endl;
}

/*
base virtual function in abstract base class Factions that can be overriden by derived classes
*/
std::string Factions::createNewCharacter()
{
	
	cout << "Random Twilek Created" << endl;
	return "hi";
}

/*
base virtual function in abstract base class Factions that can be overriden by derived classes
*/
void Factions::createNewPlanet()
{
	cout << "Random  Planet Created" << endl;
}

/*
get random gray force power
*/
void Factions::getForcePower(int& x)
{
	cout << "Force focus." << endl;
}

/*
Function to create a random enemy encounter
*/
int Factions::enemyCreate()
{
	srand(time(0));
	switch (rand() % 4)
	{
		case 0:
		{
			srand(time(0));
			int j1 = rand() % 100;
			//cout << "case 0: "<<"Jedi Level: " << j1 << " \n";
			enemyNameCreate(); cout << ": Only sith deal in absolutes.\n";
			return j1;
		}

		case 1:
		{
			srand(time(0));
			int j2 = rand() % 70;
			//cout << "case 1 " << "Jedi Level: " << j2 << " \n";
			enemyNameCreate(); cout << ": I have the higher ground! Don't try it!!" << endl;
			return j2;
		}

		case 2:
		{
			srand(time(0));
			int j3 = rand() % 50;
			//cout << "case 2 " << "Jedi Level: " << j3 << " \n";
			enemyNameCreate(); cout << ": Don't give in to hate. That leads to the Dark Side.\n";
			return j3;
		}

		case 3:
		{
			srand(time(0));
			int j4 = rand() % 25;
			//cout << "case 3 " << "Jedi Level: " << j4 << " \n";
			enemyNameCreate(); cout << ": Fear is the path to the dark side.\n";
			return j4;
		}
	}
	return 0;

}

/*
function to create a random enemy name using a for loop and an array.
*/
void Factions::enemyNameCreate()
{
	srand(time(0));

	string suffixArray[10] = { "Skywalker", "Jin", "Kenobi", "Windu", "Tano", "Shan", "Secura", "Unduli" , " " };
	string prefixArray[10] = { "Luke", "", "Anakin", "Bastilla", "Revan", "Malak","Ahsoka", "Mace", "Ayla", "Luminara" };


	for (int i = 0; i < 1; i++)
	{

		cout << prefixArray[(rand() % 10)] << " " << suffixArray[(rand() % 10)];

	}

}

/*
Function definition to pass by value to get lightsaber form
*/
void::Factions::getLightsaberForm(int x)
{
	int temp;
	temp = x; /* save the value of x */
	srand(time(0));
	switch (rand() % x)
	{
	case 0: cout << endl << "Shii-Cho lightsaber form used.\n"; break;
	case 1: cout << endl << "Makashi lightsaber form used.\n"; break;
	case 2: cout << endl << "Soresu lightsaber form used.\n"; break;
	case 3: cout << endl << "Ataru lightsaber form used.\n"; break;
	case 4: cout << endl << "Shien lightsaber form used.\n"; break;
	case 5: cout << endl << "Djem So lightsaber form used.\n"; break;
	case 6: cout << endl << "Niman lightsaber form used.\n"; break;
	case 7: cout << endl << "Juyo lightsaber form used.\n"; break;
	case 8: cout << endl << "Vaapad lightsaber form used.\n"; break;
	}
}






///////////////////////////////////////////////// REPUBLIC
/*
Create new galactic republic ship
*/
void rebelAlliance::createNewShip(int x)
{

	int temp;
	temp = x; /* save the value of x */
	srand(time(0));
	switch (rand() % x)
	{
	case 0: cout << endl << "Ship: T-65 X-wing starfighter selected.\n"; break;
	case 1: cout << endl << "Ship: A/SF-01 B-wing heavy assault starfighter selected.\n"; break;
	case 2: cout << endl << "Ship: E-7 E-wing multi-role starfighter selected.\n"; break;
	case 3: cout << endl << "Ship: Rihkxyrk (rik-zerk) assault starfighter selected.\n"; break;
	case 4: cout << endl << "Ship: Starspeeder 3000 selected.\n"; break;
	case 5: cout << endl << "Ship: RZ-1 A-wing interceptor selected.\n"; break;
	case 6: cout << endl << "Ship: Royal N-1 'Naboo' starfighter selected.\n"; break;
	case 7: cout << endl << "Ship: VCX-100 'Ghost' selected.\n"; break;
	case 8: cout << endl << "Ship: YT-1300 Corellian light freighter 'Millennium Falcon' selected.\n"; break;
	}
};

/*
Create new galactic republic character
*/
string rebelAlliance::createNewCharacter()
{	
	srand(time(0));

	string suffixArray[10] = { " Mothma", " Akbar", " Andor", " Antilles", " Erso", " Shan", " Syndulla", " Guerrera" , " Calrissian " };
	string prefixArray[10] = { "Mon", "", "General", "Cassian", "Wedge", "Jyn","Herra", "Mace", "Saw", "Lando" };
	string store1 = "";
	string store2 = "";
	
	store1 = prefixArray[(rand() % 10)];
	store2 = suffixArray[(rand() % 10)];

	return store1 + store2;
};

/*
Create new galactic republic planet
*/
void rebelAlliance::createNewPlanet()
{
	cout << "Tatooine" << endl;
};

/*
get random gray force power
*/
void rebelAlliance::getForcePower(int& x)
{
	cout << "one need not be a jedi to use the force.";
}

/*
Function definition to pass by pointer and swap power levels
*/
void rebelAlliance::swapPowerLevel(int* jedi, int* sith)
{
	int c = *jedi;
	*jedi = *sith;
	*sith = c;
}

/*
Function definition to create a new enemy
*/
int rebelAlliance::enemyCreate()
{
	srand(time(0));
	switch (rand() % 4)
	{
	case 0:
	{
		srand(time(0));
		int j1 = rand() % 100;
		//cout << "case 0: "<<"Jedi Level: " << j1 << " \n";
		enemyNameCreate(); cout << ": Rebel scum.\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
		return j1;
	}

	case 1:
	{
		srand(time(0));
		int j2 = rand() % 70;
		//cout << "case 1 " << "Jedi Level: " << j2 << " \n";
		enemyNameCreate(); cout << ": The empire has done nothing wrong. " << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
		return j2;
	}

	case 2:
	{
		srand(time(0));
		int j3 = rand() % 50;
		//cout << "case 2 " << "Jedi Level: " << j3 << " \n";
		enemyNameCreate(); cout << ": Yesterday you were a child, today a rebel, tomorrow dead.\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
		return j3;
	}

	case 3:
	{
		srand(time(0));
		int j4 = rand() % 25;
		//cout << "case 3 " << "Jedi Level: " << j4 << " \n";
		enemyNameCreate(); cout << ": The emperor has brought peace to the galaxy. Your rebellion disrupts it.\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(2500));
		return j4;
	}
	}
	return 0;

}

/*
Function definition to create enemy name
*/
void rebelAlliance::enemyNameCreate()
{
	srand(time(0));

	string suffixArray[10] = { "Tarkin", "Krennic", "Thrawn", "Palpatine", "Saxon", "Rook", "Pryce", "Unduli" , "Gideon", "Dune" };
	string prefixArray[10] = { "Grand-Moff", "Director", "Grand-Admiral", "Gar", "Bodhi", "Arihnda","Ahsoka", "Moff", "Cara", " " };


	for (int i = 0; i < 1; i++)
	{

		cout << prefixArray[(rand() % 10)] << " " << suffixArray[(rand() % 10)];

	}

}

/*
Function definition to pass by value to get lightsaber form
*/
void rebelAlliance::getLightsaberForm(int x)
{
	int temp;
	temp = x; /* save the value of x */
	srand(time(0));
	switch (rand() % x)
	{
	case 0: cout << endl << "Shii-Cho lightsaber form used.\n"; break;
	case 1: cout << endl << "Makashi lightsaber form used.\n"; break;
	case 2: cout << endl << "Soresu lightsaber form used.\n"; break;
	case 3: cout << endl << "Ataru lightsaber form used.\n"; break;
	case 4: cout << endl << "Shien lightsaber form used.\n"; break;
	case 5: cout << endl << "Djem So lightsaber form used.\n"; break;
	case 6: cout << endl << "Niman lightsaber form used.\n"; break;
	case 7: cout << endl << "Juyo lightsaber form used.\n"; break;
	case 8: cout << endl << "Vaapad lightsaber form used.\n"; break;
	}
}


	
	




///////////////////////////////////////////////// EMPIRE
/*
Create new galactic empire ship
*/
void galacticEmpire::createNewShip(int x)
{
	int temp;
	temp = x; /* save the value of x */
	srand(time(0));
	switch (rand() % x)
	{
	case 0: cout << endl << "Ship: TIE/LN starfighter selected.\n"; break;
	case 1: cout << endl << "Ship: TIE Advanced x1 'Darth Vader' selected.\n"; break;
	case 2: cout << endl << "Ship: TIE/sa bomber selected.\n"; break;
	case 3: cout << endl << "Ship: TIE/IN starfighter 'Tie Interceptor' selected.\n"; break;
	case 4: cout << endl << "Ship: TIE/ad starfighter 'Tie Avenger' selected.\n"; break;
	case 5: cout << endl << "Ship: Predator-class fighter 'Tie Predator selected.\n"; break;
	case 6: cout << endl << "Ship: T.I.E. 'TIE Intruder' selected.\n"; break;
	
	}
};

/*
Create new galactic empire character
*/
string galacticEmpire::createNewCharacter()
{
	srand(time(0));

	string suffixArray[10] = { "Tarkin", "Krennic", "Thrawn", "Palpatine", "Saxon", "Rook", "Pryce", "Unduli" , "Gideon", "Dune"};
	string prefixArray[10] = { "Grand-Moff ", "Director ", "Grand-Admiral ", "Gar ", "Bodhi ", "Arihnda ","Shiev ", "Moff ", "Cara ", " " };
	string store1 = "";
	string store2 = "";
	for (int i = 0; i < 1; i++)
	
	store1 = prefixArray[(rand() % 10)];
	store2 = suffixArray[(rand() % 10)];

	return store1 + store2;

};

/*
Create new galactic empire Planet
*/
void galacticEmpire::createNewPlanet()
{
	cout << "Coruscant" << endl;
};

/*
get force power
*/
void galacticEmpire::getForcePower(int& x)
{
	cout << "one need not be a jedi to use the force.";
}

/*
Function definition to pass by pointer and swap power levels
*/
void galacticEmpire::swapPowerLevel(int* jedi, int* sith)
{
	int c = *jedi;
	*jedi = *sith;
	*sith = c;
}

/*
Function definition to create a new nemy 
*/
int galacticEmpire::enemyCreate()
{
	srand(time(0));
	switch (rand() % 4)
	{
	case 0:
	{
		srand(time(0));
		int j1 = rand() % 100;
		//cout << "case 0: "<<"Jedi Level: " << j1 << " \n";
		enemyNameCreate(); cout << ": Only sith deal in absolutes.\n";
		return j1;
	}

	case 1:
	{
		srand(time(0));
		int j2 = rand() % 70;
		//cout << "case 1 " << "Jedi Level: " << j2 << " \n";
		enemyNameCreate(); cout << ": I have the higher ground! Don't try it!!" << endl;
		return j2;
	}

	case 2:
	{
		srand(time(0));
		int j3 = rand() % 50;
		//cout << "case 2 " << "Jedi Level: " << j3 << " \n";
		enemyNameCreate(); cout << ": Don't give in to hate. That leads to the Dark Side.\n";
		return j3;
	}

	case 3:
	{
		srand(time(0));
		int j4 = rand() % 25;
		//cout << "case 3 " << "Jedi Level: " << j4 << " \n";
		enemyNameCreate(); cout << ": Fear is the path to the dark side.\n";
		return j4;
	}
	}
	return 0;

}

/*
Function definition to create a new enemy name
*/
void galacticEmpire::enemyNameCreate()
{
	srand(time(0));

	string suffixArray[10] = { " Mothma", " Akbar", " Andor", " Antilles", " Erso", " Shan", " Syndulla", " Guerrera" , " Calrissian " };
	string prefixArray[10] = { "Mon", "", "General", "Cassian", "Wedge", "Jyn","Herra", "Mace", "Saw", "Lando" };


	for (int i = 0; i < 1; i++)
	{

		cout << prefixArray[(rand() % 10)] << " " << suffixArray[(rand() % 10)];

	}

}

/*
Function definition to pass by value to get lightsaber form
*/
void galacticEmpire::getLightsaberForm(int x)
{
	int temp;
	temp = x; /* save the value of x */
	srand(time(0));
	switch (rand() % x)
	{
	case 0: cout << endl << "Shii-Cho lightsaber form used.\n"; break;
	case 1: cout << endl << "Makashi lightsaber form used.\n"; break;
	case 2: cout << endl << "Soresu lightsaber form used.\n"; break;
	case 3: cout << endl << "Ataru lightsaber form used.\n"; break;
	case 4: cout << endl << "Shien lightsaber form used.\n"; break;
	case 5: cout << endl << "Djem So lightsaber form used.\n"; break;
	case 6: cout << endl << "Niman lightsaber form used.\n"; break;
	case 7: cout << endl << "Juyo lightsaber form used.\n"; break;
	case 8: cout << endl << "Vaapad lightsaber form used.\n"; break;
	}
}









///////////////////////////////////////////////// JEDI
/*
Create new jedi order ship
*/
void jediOrder::createNewShip(int x)
{
	int temp;
	temp = x; /* save the value of x */
	srand(time(0));
	switch (rand() % x)
	{
	case 0: cout << endl << "Ship: Dynamic-class freighter 'Ebon Hawk' selected.\n"; break;
	case 1: cout << endl << "Ship: Rogue Shadow selected.\n"; break;
	case 2: cout << endl << "Ship: Personal Luxury Yacht 3000 'Spirit of Coreliea' selected.\n"; break;
	case 3: cout << endl << "Ship: Delta 7 'Azure Angel'selected.\n"; break;
	case 4: cout << endl << "Ship: Delta 7 'Obi Wan' selected.\n"; break;
	case 5: cout << endl << "Ship: Grand Master Yoda's Jedi Starfighter selected.\n"; break;

	}
};

/*
create new Jedi Order character
*/
string jediOrder::createNewCharacter()
{
	srand(time(0));

	string suffixArray[10] = { "Skywalker", "Jin", "Kenobi", "Windu", "Tano", "Shan", "Secura", "Unduli" , " " };
	string prefixArray[10] = { "Luke ", "Obi-wan ", "Qui-Gon ", "Bastilla ", "Revan ", "Malak ","Ahsoka ", "Mace ", "Ayla ", "Luminara" };
	string store1 = "";
	string store2 = "";
	
	store1 = prefixArray[(rand() % 10)];
	store2 = suffixArray[(rand() % 10)];

	return store1 + store2;

};

/*
create new Jedi Order Planet
*/
void jediOrder::createNewPlanet()
{
	cout << "Jeddha" << endl;
};

/*
get lightside force power
*/
void jediOrder::getForcePower(int& x)
{
	int temp;
	temp = x; /* save the value of x */
	srand(time(0));
	switch (rand() % temp)
	{
	case 0: cout << endl << "Force push used.\n"; break;
	case 1: cout << endl << "Force aura used.\n"; break;
	case 2: cout << endl << "Force heal used.\n"; break;
	case 3: cout << endl << "Battke meditation used.\n"; break;
	case 4: cout << endl << "Mind trick used.\n"; break;
	case 5: cout << endl << "Force destruction used.\n"; break;
	case 6: cout << endl << "Force drain used.\n"; break;
	case 7: cout << endl << "Force phantom used.\n"; break;
	}
}
/*
Function definition to pass by pointer and swap power levels
*/
void jediOrder::swapPowerLevel(int* jedi, int* sith)
{
	int c = *jedi;
	*jedi = *sith;
	*sith = c;
}

/*
Function definition to create an enemy
*/
int jediOrder::enemyCreate()
{
	srand(time(0));
	switch (rand() % 4)
	{
	case 0:
	{
		srand(time(0));
		int j1 = rand() % 100;
		//cout << "case 0: "<<"Jedi Level: " << j1 << " \n";
		enemyNameCreate(); cout << ": Peace is a lie, there is only passion.\n";
		return j1;
	}

	case 1:
	{
		srand(time(0));
		int j2 = rand() % 70;
		//cout << "case 1 " << "Jedi Level: " << j2 << " \n";
		enemyNameCreate(); cout << ": Through passion, I gain strength." << endl;
		return j2;
	}

	case 2:
	{
		srand(time(0));
		int j3 = rand() % 50;
		//cout << "case 2 " << "Jedi Level: " << j3 << " \n";
		enemyNameCreate(); cout << ": Through strength, I gain power.\n";
		return j3;
	}

	case 3:
	{
		srand(time(0));
		int j4 = rand() % 25;
		//cout << "case 3 " << "Jedi Level: " << j4 << " \n";
		enemyNameCreate(); cout << ": Through power, I gain victory.\n";
		return j4;
	}
	}
	return 0;

}

/*
Function definition to create enemy name
*/
void jediOrder::enemyNameCreate()
{
	srand(time(0));

	string suffixArray[10] = { "Maul", "Sidius", "Dooku", "Ventress", "Vader", "", "Bane", "Sion" , "Malgus" };
	string prefixArray[5] = { "Darth ", "", "Lord ", "Count ", "Asaj ", };


	for (int i = 0; i < 1; i++)
	{

		cout << prefixArray[(rand() % 5)] << " " << suffixArray[(rand() % 10)];

	}

}

/*
Function definition to pass by value to get lightsaber form
*/
void jediOrder::getLightsaberForm(int x)
{
	int temp;
	temp = x; /* save the value of x */
	srand(time(0));
	switch (rand() % x)
	{
	case 0: cout << endl << "Shii-Cho lightsaber form used.\n"; break;
	case 1: cout << endl << "Makashi lightsaber form used.\n"; break;
	case 2: cout << endl << "Soresu lightsaber form used.\n"; break;
	case 3: cout << endl << "Ataru lightsaber form used.\n"; break;
	case 4: cout << endl << "Shien lightsaber form used.\n"; break;
	case 5: cout << endl << "Djem So lightsaber form used.\n"; break;
	case 6: cout << endl << "Niman lightsaber form used.\n"; break;
	case 7: cout << endl << "Juyo lightsaber form used.\n"; break;
	case 8: cout << endl << "Vaapad lightsaber form used.\n"; break;
	}
}








///////////////////////////////////////////////// SITH
/*
Create new Sith ship
*/
void sithOrder::createNewShip(int x)
{
	int temp;
	temp = x; /* save the value of x */
	srand(time(0));
	switch (rand() % x)
	{
	case 0: cout << endl << "Ship: Scimitar selected.\n"; break;
	case 1: cout << endl << "Ship: TIE Advanced x1 'Darth Vader' selected.\n"; break;
	case 2: cout << endl << "Ship: Lambda-class T-4a shuttle selected.\n"; break;
	case 3: cout << endl << "Ship: Punworcca 116-class interstellar sloop 'Solar Sailer' selected.\n"; break;
	

	}
};

/*
Create new Sith character
*/
string sithOrder::createNewCharacter()
{
	string suffixArray[10] = { "Maul", "Sidius", "Dooku", "Ventress", "Vader", "", "Bane", "Sion" , "Malgus" };
	string prefixArray[10] = { "Darth ", "", "Lord ", "Count ", };
	string store1 = "";
	string store2 = "";

	store1 = prefixArray[(rand() % 4)];
	store2 = suffixArray[(rand() % 10)];

	return store1 + store2;
};

/*
Create new Sith Planet
*/
void sithOrder::createNewPlanet()
{
	cout << "Korriban" << endl;
};

/*
get random darkside force power
*/
void sithOrder::getForcePower(int& x)
{
	int temp;
	temp = x; /* save the value of x */
	srand(time(0));
	switch (rand() % temp)
	{
	case 0: cout << endl << "Force lightning used.\n"; break;
	case 1: cout << endl << "Force scream used.\n"; break;
	case 2: cout << endl << "Force choke used.\n"; break;
	case 3: cout << endl << "Alter reality used.\n"; break;
	case 4: cout << endl << "Drain aura used.\n"; break;
	case 5: cout << endl << "Force destruction used.\n"; break;
	case 6: cout << endl << "Force drain used.\n"; break;
	case 7: cout << endl << "Force phantom used.\n"; break;
	}
}

/*
Function definition to pass by pointer and swap power levels
*/
void sithOrder::swapPowerLevel(int* jedi, int* sith)
{
	int c = *jedi;
	*jedi = *sith;
	*sith = c;
}

/*
Function definition to create a new enemy
*/
int sithOrder::enemyCreate()
{
	srand(time(0));
	switch (rand() % 4)
	{
	case 0:
	{
		srand(time(0));
		int j1 = rand() % 100;
		//cout << "case 0: "<<"Jedi Level: " << j1 << " \n";
		enemyNameCreate(); cout << ": Only sith deal in absolutes.\n";
		return j1;
	}

	case 1:
	{
		srand(time(0));
		int j2 = rand() % 70;
		//cout << "case 1 " << "Jedi Level: " << j2 << " \n";
		enemyNameCreate(); cout << ": I have the higher ground! Don't try it!!!" << endl;
		return j2;
	}

	case 2:
	{
		srand(time(0));
		int j3 = rand() % 50;
		//cout << "case 2 " << "Jedi Level: " << j3 << " \n";
		enemyNameCreate(); cout << ": Don't give in to hate. That leads to the Dark Side.\n";
		return j3;
	}

	case 3:
	{
		srand(time(0));
		int j4 = rand() % 25;
		//cout << "case 3 " << "Jedi Level: " << j4 << " \n";
		enemyNameCreate(); cout << ": Fear is the path to the dark side.\n";
		return j4;
	}
	}
	return 0;

}

/*
Function definition to create a new enemy name
*/
void sithOrder::enemyNameCreate()
{
	srand(time(0));

	string suffixArray[10] = { "Skywalker", "Jin", "Kenobi", "Windu", "Tano", "Shan", "Secura", "Unduli" , " " };
	string prefixArray[10] = { "Luke", "", "Anakin", "Bastilla", "Revan", "Malak","Ahsoka", "Mace", "Ayla", "Luminara" };


	for (int i = 0; i < 1; i++)
	{

		cout << prefixArray[(rand() % 10)] << " " << suffixArray[(rand() % 10)];

	}

}

/*
Function definition to pass by value to get lightsaber form
*/
void sithOrder::getLightsaberForm(int x)
{
	int temp;
	temp = x; /* save the value of x */
	srand(time(0));
	switch (rand() % x)
	{
	case 0: cout << endl << "Shii-Cho lightsaber form used.\n"; break;
	case 1: cout << endl << "Makashi lightsaber form used.\n"; break;
	case 2: cout << endl << "Soresu lightsaber form used.\n"; break;
	case 3: cout << endl << "Ataru lightsaber form used.\n"; break;
	case 4: cout << endl << "Shien lightsaber form used.\n"; break;
	case 5: cout << endl << "Djem So lightsaber form used.\n"; break;
	case 6: cout << endl << "Niman lightsaber form used.\n"; break;
	case 7: cout << endl << "Juyo lightsaber form used.\n"; break;
	case 8: cout << endl << "Vaapad lightsaber form used.\n"; break;
	}
}

