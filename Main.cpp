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
#include <chrono>
#include <thread>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::cin;
using std::setw;
using std::setfill;



int main()
{   
    
    // Relevant variables
    srand(time(0));
    std::vector < int > enemyRound;
    vector<Factions*> swGalaxy; // vector pointer that points to the base class factions 
    int fact_select = 0;
    bool playerAlive = true;
    string playerName = "";
    int enemiesDefeated = 0;
    int enemieCount = 1;
    int enemySkill = 0;
    int playerSkill = rand() % 500;
    int playerSkillSwap = rand() % 1000;
    int force_select = 0;
    char switcharoo; // used to switch player level
    int saberForm;
    int fallenEnemies = 0;
    int shipSelect;
    
    
    
     //sithApprentice.playerSkillSwap = rand() % 1000
   

    // Main title sequence
    cout << setw(50) << "Star Wars: Factions" << setw(27) << "`" << endl;
    cout << setfill('`') << setw(77) << "`" << endl;
    cout << setw(52) << "Grand Space Exploration" << setw(25) << "`" << endl; ;
    cout << setfill('`') << setw(77) << "`" << "\n" << endl;
	
     
    /*
     Adding all class objects to container 
    */
    swGalaxy.push_back(new rebelAlliance);
    swGalaxy.push_back(new galacticEmpire);
    swGalaxy.push_back(new jediOrder);
    swGalaxy.push_back(new sithOrder);

    
  
    cout << "\nSelect Faction: " << endl;
    cout << "(Rebel Alliance  = 1) " << endl;
    cout << "(Galactic Empire = 2) " << endl;
    cout << "(Jedi Order      = 3) " << endl;
    cout << "(Sith Order      = 4)\n" << endl;
    cin >> fact_select;

    if (fact_select == 1)
    {
        ////////// create a for loop that calls all empire objects
        playerName = swGalaxy[0]->createNewCharacter();
        cout << "Rebel Alliance Selected" << endl;
        cout << "\nSelect Ship: " << endl;
        cout << "\n(Enter 1-9) " << endl;
        cin >> shipSelect;
        swGalaxy[0]->createNewShip(shipSelect);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "Rebel hero: " << playerName << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "starting planet: "; swGalaxy[0]->createNewPlanet(); cout << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        while (playerAlive && enemiesDefeated < enemieCount)
        {
            /*
            use pass by pointer to offer switch power levels after every round!
            */
            cout << setfill('`') << setw(77) << "`" << endl;
            cout << "General Organa: There are things that you cannot solve by jumping in an X-wing and blowing something up.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            cout << "(Train with the Rebel Alliance for a chance at a greater level y/n?)";
            cin >> switcharoo;
            if (switcharoo == 'y' || switcharoo == 'Y')
            {
                swGalaxy[0]->swapPowerLevel(&playerSkill, &playerSkillSwap);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                if (playerSkillSwap <= playerSkill)
                {
                    cout << "General Organa: We have everything we need.\n" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    cout << "(Training successful)" << endl;
                }
                else
                {
                    cout << "General Organa: Hope.\n" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    cout << "(Training failed.)" << endl;
                }
                
            }
            else
            {
                cout << "General Organa: No matter how much we fought, I’ve always hated watching you leave.\n" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }


            /*
            Creates a random jedi and a counter using a ranged based for loop and vector to keep track
            of rounds fought against the jedi.
            */
            cout << setfill('`') << setw(77) << "`" << endl;
            enemySkill = swGalaxy[0]->enemyCreate();
            cout << "Enemy Level: " << enemySkill << "\n";
            for (int a : enemyRound) // range based for loop to print the number of fallen Jedi
            {
                cout << "Round:" << a << "\n" << endl;
            }


            /*
            The idea is to have a text based battle and maybe improve on it in later itterations
            to add more winning conditions, mulptiple enemies at once, and the ability to train
            the sith before going into battle. This game is based  "Fallout Shelter" by Bethesda
            */
            if (enemySkill > 20)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                swGalaxy[0]->enemyNameCreate(); cout << ", a High ranking imperial leader has entered the battlefield." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                cout << endl << playerName << ":" << "You and the Empire will fall. The galaxy will be free again." << endl;
                
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << "Blaster fire erupts!!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                cout << "pew..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1550));
                cout << "...pew" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                cout << "pew pew pew.." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                if (enemySkill >= playerSkill || enemySkill >= playerSkillSwap)
                {
                    cout << playerName << ": I'm hit!!" << endl;
                }
                else
                {
                    cout << playerName << ": I got 'em!" << endl;
                }
                //cout << endl << "enter a number 1-8 to channel the Dark Side of the Force:" << endl;
                //cin >> force_select;
                //swGalaxy[3]->getForcePower(force_select);
                //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                //cout << endl << "enter a number 1-9 to select a lightsaber form:" << endl;
                //cin >> saberForm;
                //swGalaxy[0]->getLightsaberForm(saberForm);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            }

            else if (enemySkill >= 11 && enemySkill <= 20)
            {
                swGalaxy[0]->enemyNameCreate(); cout << ", an empire trooper has entered the battlefield." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                cout << endl << playerName << ":" << "Your fight is not with me, join us!!" << endl;
                
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << "Blaster fire erupts!!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                cout << "pew..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1550));
                cout << "...pew" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                cout << "pew pew pew.." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                if (enemySkill >= playerSkill || enemySkill >= playerSkillSwap)
                {
                    cout << playerName << ": I'm hit!!" << endl;
                }
                else
                {
                    cout << playerName << ": I got 'em!" << endl;
                }
                /*std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-8 to channel the Dark Side of the Force:" << endl;
                cin >> force_select;
                swGalaxy[3]->getForcePower(force_select);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-9 to select a lightsaber form:" << endl;
                cin >> saberForm;
                swGalaxy[0]->getLightsaberForm(saberForm);*/
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }

            else if (enemySkill <= 10)
            {
                swGalaxy[0]->enemyNameCreate(); cout << ", an orphaned imperial recruit has entered the battlefield." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                cout << endl << playerName << ":" << "We are not the enemy. The empire killed your parents!!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << "Blaster fire erupts!!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                cout << "pew..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1550));
                cout << "...pew" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                cout << "pew pew pew.." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                if (enemySkill >= playerSkill || enemySkill >= playerSkillSwap)
                {
                    cout << playerName << ": I'm hit!!" << endl;
                }
                else
                {
                    cout << playerName << ": I got 'em!" << endl;
                }
                /*std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-8 to channel the Dark Side of the Force:" << endl;
                cin >> force_select;
                swGalaxy[3]->getForcePower(force_select);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-9 to select a lightsaber form:" << endl;
                cin >> saberForm;
                swGalaxy[0]->getLightsaberForm(saberForm);*/
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }


            /*
            Death Condition if Jedi is more powerful than siith
            */
            if (playerSkill < enemySkill)
            {
                playerAlive = false;
                cout << "You have died." << endl;
                cout << setfill('`') << setw(77) << "`" << endl;
            }

            /*
            Updates defeated jedi counter and the vector keeping track of all wins
            */
            else
            {
                if (playerSkill - enemySkill > 20)
                {
                    cout << "Empire soldier defeated." << endl;
                    cout << playerName << ": For the Republic!" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                    //sithApprentice.playerScore = sithApprentice.playerScore +1;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;
                }

                else if (playerSkill - enemySkill > 10)
                {
                    cout << "Enemy defeated." << endl;
                   // cout << playerName << ": The jedi code is laughable." << endl;
                    //cout << playerName << ": You are one with your force now jedi!" << endl;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;

                }

                else if (playerSkill - enemySkill > 0)
                {
                    cout << "enemy defeated." << endl;
                    cout << playerName << ": We fight to survive" << endl;
                    //cout << playerName << ": A dead enemy is a good enemy!!" << endl;
                    //sithApprentice.playerScore = sithApprentice.playerScore * 2;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;

                }

                else
                {
                    cout << playerName << ": I've defeated the enemy. Barely. I need akolto tank immeditely" << endl;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;

                }

                enemiesDefeated++;
            }

            cout << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        /*
        Winning condition of the amount of jedi defeated equals the random number of jedi generated
        */
        if (enemiesDefeated == enemieCount)
        {
            cout << playerName << ": The Empire's reign of terror will be no more. Long live the Republic." << endl;

        }

        /*
        Losing condtion if encountered a more powerful jedi
        */
        else
        {
            cout << playerName << ": Where I fall other rebels shall stand. The rebellion is forever." << endl;
        }

        cout << enemiesDefeated << " imperials have fallen." << endl << endl;
    }
        
    else if (fact_select == 2)
    {   
        playerName = swGalaxy[1]->createNewCharacter();
        cout << "Galactic Empire Selected." << endl;
        cout << "\nSelect ship: " << endl;
        cout << "\n(Enter 1-6) " << endl;
        cin >> shipSelect;
        swGalaxy[1]->createNewShip(shipSelect);
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        cout << "Empire defender: " << playerName << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        cout << "starting planet: "; swGalaxy[1]->createNewPlanet(); cout << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));

        while (playerAlive && enemiesDefeated < enemieCount)
        {
            /*
            use pass by pointer to offer switch power levels after every round!
            */
            std::this_thread::sleep_for(std::chrono::milliseconds(2500));
            cout << "Grand Admiral Thrawn: I rule the Empire now. Not some long-dead Emperor. The only treason is defiance of my orders.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            cout << "(Follow Thrawn's order's and train y/n?)";
            cin >> switcharoo;
            if (switcharoo == 'y' || switcharoo == 'Y')
            {
                swGalaxy[1]->swapPowerLevel(&playerSkill, &playerSkillSwap);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                if (playerSkillSwap <= playerSkill)
                {
                    cout << "What about you, Commander? Why do *you* seek higher rank?\n" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                    cout << "(Training successful)" << endl;
                }
                else
                {
                    cout << "Thrawn: People of authority love capes.\n" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                    cout << "(Training failed.)" << endl;
                }
            }
            else
            {
                cout << "Grand Admiral Thrawn: There are problems that must be solved. Some cannot be solved by anyone except me\n" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }


            /*
            Creates a random jedi and a counter using a ranged based for loop and vector to keep track
            of rounds fought against the jedi.
            */
            cout << setfill('`') << setw(77) << "`" << endl;
            enemySkill = swGalaxy[1]->enemyCreate();
            cout << "Enemy Level: " << enemySkill << "\n";
            for (int a : enemyRound) // range based for loop to print the number of fallen Jedi
            {
                cout << "Round:" << a << "\n" << endl;
            }


            /*
            The idea is to have a text based battle and maybe improve on it in later itterations
            to add more winning conditions, mulptiple enemies at once, and the ability to train
            the sith before going into battle. This game is based  "Fallout Shelter" by Bethesda
            */
            if (enemySkill > 20)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << setfill('`') << setw(77) << "`" << endl;
                swGalaxy[1]->enemyNameCreate(); cout << ", a rebellion leader has entered the battlefield." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << playerName << ": Nothing personal, Thrawn's orders." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << "Blaster fire erupts!!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << "pew..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2550));
                cout << "...pew" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << "pew pew pew.." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                if (enemySkill >= playerSkill || enemySkill >= playerSkillSwap)
                {
                   cout  << playerName <<": I'm hit!!" << endl;
                }
                else
                {
                    cout << playerName << ": I got 'em!" << endl;
                }
                /*cout << endl << "enter a number 1-8 to channel the Dark Side of the Force:" << endl;
                cin >> force_select;
                swGalaxy[3]->getForcePower(force_select);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-9 to select a lightsaber form:" << endl;
                cin >> saberForm;
                swGalaxy[0]->getLightsaberForm(saberForm);*/
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            }

            else if (enemySkill >= 11 && enemySkill <= 20)
            {
                cout << setfill('`') << setw(77) << "`" << endl;
                swGalaxy[1]->enemyNameCreate(); cout << ", a  rebel soldier  has entered the battlefield." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << endl << playerName << ": Nothing personal, Thrawn's orders." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << "Blaster fire erupts!!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << "pew..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2550));
                cout << "...pew" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << "pew pew pew.." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                if (enemySkill >= playerSkill || enemySkill >= playerSkillSwap)
                {
                    cout << playerName << ": I'm hit!!" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                }
                else
                {
                    cout << playerName << ": I got 'em!" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                }
               /* std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-8 to channel the Dark Side of the Force:" << endl;
                cin >> force_select;
                swGalaxy[3]->getForcePower(force_select);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-9 to select a lightsaber form:" << endl;
                cin >> saberForm;
                swGalaxy[0]->getLightsaberForm(saberForm);*/
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }

            else if (enemySkill <= 10)
            {
                cout << setfill('`') << setw(77) << "`" << endl;
                swGalaxy[1]->enemyNameCreate(); cout << ", a rebel sympathizer entered the battlefield." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << playerName <<  ": Nothing personal, Thrawn's orders." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << "Blaster fire erupts!!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << "pew..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2550));
                cout << "...pew" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                cout << "pew pew pew.." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                if (enemySkill >= playerSkill || enemySkill >= playerSkillSwap)
                {
                    cout << playerName << ": I'm hit!!" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                }
                else
                {
                    cout << playerName << ": I got 'em!" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                }
                /*std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-8 to channel the Dark Side of the Force:" << endl;
                cin >> force_select;
                swGalaxy[3]->getForcePower(force_select);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-9 to select a lightsaber form:" << endl;
                cin >> saberForm;
                swGalaxy[0]->getLightsaberForm(saberForm);*/
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }


            /*
            Death Condition if rebel is more powerful than imperial
            */
            if (playerSkill < enemySkill)
            {
                playerAlive = false;
                cout << "You have died." << endl;
                cout << setfill('`') << setw(77) << "`" << endl;
            }

            /*
            Updates defeated jedi counter and the vector keeping track of all wins
            */
            else
            {
                if (playerSkill - enemySkill > 20)
                {
                    cout << "Rebel defeated." << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                    cout << playerName << ": Thrawn will be proud." << endl;
                    
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                    //sithApprentice.playerScore = sithApprentice.playerScore +1;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;
                }

                else if (playerSkill - enemySkill > 10)
                {
                    cout << "Enemy defeated." << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                    cout << playerName << ": For the Empire!" << endl;
                    //cout << playerName << ": You are one with your force now jedi!" << endl;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;

                }

                else if (playerSkill - enemySkill > 0)
                {
                    cout << "enemy defeated." << endl;
                    cout << playerName << ": Rebel scum." << endl;
                    cout << playerName << ": A dead enemy is a good enemy!!" << endl;
                    //sithApprentice.playerScore = sithApprentice.playerScore * 2;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;

                }

                else
                {
                    cout << playerName << ": I've defeated the enemy. Barely. I need akolto tank immeditely" << endl;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;

                }

                enemiesDefeated++;
            }

            cout << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        /*
        Winning condition of the amount of jedi defeated equals the random number of jedi generated
        */
        if (enemiesDefeated == enemieCount)
        {
            cout << playerName << ": The Rebel Alliance will be eradicated." << endl;

        }

        /*
        Losing condtion if encountered a more powerful rebel
        */
        else
        {
            cout << playerName << ": Inform the admiral I have failed." << endl;
        }

        cout << enemiesDefeated << " Rebels have fallen." << endl << endl;
    }
     
    else if (fact_select == 3)
    {
        playerName = swGalaxy[2]->createNewCharacter();
        cout << "Jedi Order Selected." << endl;
        cout << "\nSelect ship: " << endl;
        cout << "\n(Enter 1-6) " << endl;
        cin >> shipSelect;
        swGalaxy[2]->createNewShip(shipSelect);
        cout << "Jedi Order Member: " << playerName << endl;
        cout << "starting planet: "; swGalaxy[2]->createNewPlanet(); cout << endl;

        while (playerAlive && enemiesDefeated < enemieCount)
        {
            /*
            use pass by pointer to offer switch power levels after every round!
            */
            cout << "Grand Master Yoda: To be Jedi is to face the truth, and choose.\n";
            cout << "(Learn the ways of the force for chance at greater level y/n?)\n";
            cin >> switcharoo;
            if (switcharoo == 'y' || switcharoo == 'Y')
            {
                swGalaxy[2]->swapPowerLevel(&playerSkill, &playerSkillSwap);
               
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                if (playerSkillSwap <= playerSkill)
                {
                    cout << "Grand Master Yoda: Always pass on what you have learned.\n" << endl;
                    cout << "(Training successful)" << endl;
                }
                else
                {
                    cout << "Grand Master Yoda: Control, control, you must learn control.\n" << endl;
                    cout << "(Training failed.)" << endl;
                }
            }
            else
            {
                cout << "Grand Master Yoda: Adventure. Excitement. A Jedi craves not these things..\n" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }


            /*
            Creates a random jedi and a counter using a ranged based for loop and vector to keep track
            of rounds fought against the jedi.
            */
            cout << setfill('`') << setw(77) << "`" << endl;
            enemySkill = swGalaxy[2]->enemyCreate();
            cout << "Enemy Level: " << enemySkill << "\n";
            for (int a : enemyRound) // range based for loop to print the number of fallen Jedi
            {
                cout << "Round:" << a << "\n" << endl;
            }


            /*
            The idea is to have a text based battle and maybe improve on it in later itterations
            to add more winning conditions, mulptiple enemies at once, and the ability to train
            the sith before going into battle. This game is based  "Fallout Shelter" by Bethesda
            */
            if (enemySkill > 20)
            {
                swGalaxy[2]->enemyNameCreate(); cout << ", a Sith Lord has entered the battlefield." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << playerName << ": There is no emotion, there is peace" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-8 to channel the Light Side of the Force:" << endl;
                cin >> force_select;
                swGalaxy[2]->getForcePower(force_select);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-9 to select a lightsaber form:" << endl;
                cin >> saberForm;
                swGalaxy[2]->getLightsaberForm(saberForm);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            }

            else if (enemySkill >= 11 && enemySkill <= 20)
            {
                swGalaxy[2]->enemyNameCreate(); cout << ", a Sith Marauder has entered the battlefield." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << playerName << ": There is no ignorance, there is knowledge." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-8 to channel the Light Side of the Force:" << endl;
                cin >> force_select;
                swGalaxy[2]->getForcePower(force_select);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-9 to select a lightsaber form:" << endl;
                cin >> saberForm;
                swGalaxy[2]->getLightsaberForm(saberForm);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }

            else if (enemySkill <= 10)
            {
                swGalaxy[2]->enemyNameCreate(); cout << ", a sith Acolyte has entered the battlefield." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << playerName << ": There is no death, there is only the Force." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-8 to channel the Light Side of the Force:" << endl;
                cin >> force_select;
                swGalaxy[2]->getForcePower(force_select);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-9 to select a lightsaber form:" << endl;
                cin >> saberForm;
                swGalaxy[2]->getLightsaberForm(saberForm);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }


            /*
            Death Condition if Jedi is more powerful than siith
            */
            if (playerSkill < enemySkill)
            {
                playerAlive = false;
                cout << "You have died." << endl;
                cout << setfill('`') << setw(77) << "`" << endl;
            }

            /*
            Updates defeated jedi counter and the vector keeping track of all wins
            */
            else
            {
                if (playerSkill - enemySkill > 20)
                {
                    cout << "Sith  defeated." << endl;
                    cout << playerName << ": There is no chaos, there is harmony." << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                    //sithApprentice.playerScore = sithApprentice.playerScore +1;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;
                }

                else if (playerSkill - enemySkill > 10)
                {
                    cout << "Sith defeated." << endl;
                    cout << playerName << ": There is no ignorance, there is knowledge." << endl;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;

                }

                else if (playerSkill - enemySkill > 0)
                {
                    cout << "enemy defeated." << endl;
                    cout << playerName << ": I must meditate." << endl;
                    //sithApprentice.playerScore = sithApprentice.playerScore * 2;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;

                }

                else
                {
                    cout << playerName << ": There is no chaos, there is harmony. I need a kolto tank immeditely" << endl;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;

                }

                enemiesDefeated++;
            }

            cout << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        /*
        Winning condition of the amount of jedi defeated equals the random number of jedi generated
        */
        if (enemiesDefeated == enemieCount)
        {
            cout << playerName << ": No. Try not. Do, or do not. There is no try." << endl;

        }

        /*
        Losing condtion if encountered a more powerful jedi
        */
        else
        {
            cout << playerName << ": I must be one with the force. " << endl;
            cout << "(Player died.) " << endl;
        }

        cout << enemiesDefeated << " Sith have fallen." << endl << endl;
    }

    else if (fact_select == 4)
    {
        playerName = swGalaxy[3]->createNewCharacter();
        cout << "Sith Order Selected." << endl;
        cout << "\nSelect ship: " << endl;
        cout << "\n(Enter 1-4) " << endl;
        cin >> shipSelect;
        swGalaxy[3]->createNewShip(shipSelect);
        cout << "Sith Order Member: " << playerName << endl;
        cout << "starting planet: "; swGalaxy[3]->createNewPlanet(); cout << endl;

        while (playerAlive && enemiesDefeated < enemieCount)
        {
            //string name = swGalaxy[3]->createNewCharacter();
            /*
            use pass by pointer to offer switch power levels after every round!
            */
            cout << "Darth Sidius: I offer you the chance at unlimitted power. Will you accept?\n";
            cout << "(Kill your childhoold friend to absorb their force aura y/n?)";
            cin >> switcharoo;
            if (switcharoo == 'y' || switcharoo == 'Y')
            {
                cout << playerSkill << endl;
                cout << playerSkillSwap << endl;
                swGalaxy[3]->swapPowerLevel(&playerSkill, &playerSkillSwap);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                if (playerSkillSwap <= playerSkill)
                {
                    cout << "Darth Sidius: Unlimitted powaaa!!!.\n" << endl;
                    cout << "(Training successful)" << endl;
                }
                else
                {
                    cout << "Darth Sidius: This turn of events is unfortunate. We must accelerate our plans.\n" << endl;
                    cout << "(Training failed.)" << endl;
                }
            }
            else
            {
                cout << "Darth Sidius: The Republic will be reorganized into the first Galactic Empire.\n" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }


            /*
            Creates a random jedi and a counter using a ranged based for loop and vector to keep track
            of rounds fought against the jedi.
            */
            cout << setfill('`') << setw(77) << "`" << endl;
            enemySkill = swGalaxy[3]->enemyCreate();
            cout << "Enemy Level: " << enemySkill << "\n";
            for (int a : enemyRound) // range based for loop to print the number of fallen Jedi
            {
                cout << "Round:" << a << "\n" << endl;
            }


            /*
            The idea is to have a text based battle and maybe improve on it in later itterations
            to add more winning conditions, mulptiple enemies at once, and the ability to train
            the sith before going into battle. This game is based  "Fallout Shelter" by Bethesda
            */
            if (enemySkill > 20)
            {
                swGalaxy[3]->enemyNameCreate(); cout << ", a Jedi Master has entered the battlefield." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << playerName << ": A Jedi Master! Finally a worthy opponent." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-8 to channel the Dark Side of the Force:" << endl;
                cin >> force_select;
                swGalaxy[3]->getForcePower(force_select);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-9 to select a lightsaber form:" << endl;
                cin >> saberForm;
                swGalaxy[0]->getLightsaberForm(saberForm);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));

            }

            else if (enemySkill >= 11 && enemySkill <= 20)
            {
                swGalaxy[0]->enemyNameCreate(); cout << ", a Jedi knight has entered the battlefield." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << playerName << ": A Jedi Knight?! Prove your worth Jedi!!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-8 to channel the Dark Side of the Force:" << endl;
                cin >> force_select;
                swGalaxy[3]->getForcePower(force_select);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-9 to select a lightsaber form:" << endl;
                cin >> saberForm;
                swGalaxy[0]->getLightsaberForm(saberForm);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }

            else if (enemySkill <= 10)
            {
                swGalaxy[0]->enemyNameCreate(); cout << ", a padawan has entered the battlefield." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << playerName << ": You'll die in vain for your fragile order padawan." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-8 to channel the Dark Side of the Force:" << endl;
                cin >> force_select;
                swGalaxy[3]->getForcePower(force_select);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                cout << endl << "enter a number 1-9 to select a lightsaber form:" << endl;
                cin >> saberForm;
                swGalaxy[0]->getLightsaberForm(saberForm);
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            }


            /*
            Death Condition if Jedi is more powerful than siith
            */
            if (playerSkill < enemySkill)
            {
                playerAlive = false;
                cout << "You have died." << endl;
                cout << setfill('`') << setw(77) << "`" << endl;
            }

            /*
            Updates defeated jedi counter and the vector keeping track of all wins
            */
            else
            {
                if (playerSkill - enemySkill > 20)
                {
                    cout << "Jedi defeated." << endl;
                    cout << playerName << ": Unlimitted powa!!!" << endl;
                    cout << playerName << ": Do it!!" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                    //sithApprentice.playerScore = sithApprentice.playerScore +1;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;
                }

                else if (playerSkill - enemySkill > 10)
                {
                    cout << "Enemy defeated." << endl;
                    cout << playerName << ": The jedi code is laughable." << endl;
                    cout << playerName << ": You are one with your force now jedi!" << endl;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;

                }

                else if (playerSkill - enemySkill > 0)
                {
                    cout << "enemy defeated." << endl;
                    cout << playerName << ": Worthless." << endl;
                    cout << playerName << ": A dead enemy is a good enemy!!" << endl;
                    //sithApprentice.playerScore = sithApprentice.playerScore * 2;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;

                }

                else
                {
                    cout << playerName << ": I've defeated the enemy. Barely. I need akolto tank immeditely" << endl;
                    fallenEnemies++;
                    enemyRound.push_back(fallenEnemies); // vector store fallen Jedi
                    cout << setfill('`') << setw(77) << "`" << endl;

                }

                enemiesDefeated++;
            }

            cout << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        /*
        Winning condition of the amount of jedi defeated equals the random number of jedi generated
        */
        if (enemiesDefeated == enemieCount)
        {
            cout << playerName << ": The Jedi will be eradicated." << endl;

        }

        /*
        Losing condtion if encountered a more powerful jedi
        */
        else
        {
            cout << playerName << ": I've failed master." << endl;
        }

        cout << enemiesDefeated << " Jedi have fallen." << endl << endl;
    }

    else
    {
        return -1;
    }

   


    









    return 0;
}
    
     
    

  
	
















