#include "helperFunctions.h"
#include "global.h"
#include <iostream>
#include <fstream>
using namespace std;


void generateLootLevel(Character& player) //Generates loot and levels player up after combat
{
    int lootChoice = -1;
    Loot loot1;
    Loot loot2;
    Loot loot3;

    loot1.generateLoot();
    loot2.generateLoot();
    loot3.generateLoot();

    player.levelUp();
    while (lootChoice != 1 && lootChoice != 2 && lootChoice != 3)
    {
        cout << "You find some loot on the ground, which would you like to take?" << endl;
        cout << endl << "[1]";
        loot1.printLoot();
        cout << endl << "[2]";
        loot2.printLoot();
        cout << endl << "[3]";
        loot3.printLoot();
        cout << endl;

        cin >> lootChoice;

        if (lootChoice == 1)
        {
            player.addLoot(loot1);
            if (loot1.getHeal() != 0)
            {
                player.heal();
            }
        }
        else if (lootChoice == 2)
        {
            player.addLoot(loot2);
            if (loot2.getHeal() != 0)
            {
                player.heal();
            }
        }
        else if (lootChoice == 3)
        {
            player.addLoot(loot3);
            if (loot3.getHeal() != 0)
            {
                player.heal();
            }
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
}

void generateEndScreen(Character& player)
{
    //Final stat screen
    cout << endl << "Final Stats:" << endl << endl; 
    cout << "Final Floor Number: " << floorNumber << endl;
    player.printCharacter();
    cout << endl << "Final Inventory:" << endl;
    player.printInventory();

    //Run history saving
    fstream runHistory("Run_History.txt", ios::out | ios::app);

    if (runHistory.fail())
    {
        cout << endl << "Your run data could not be saved." << endl;
    }
    else
    {
        cout << "Saving your run!" << endl;
        runHistory << endl << "----------------------" << endl << "Final Stats: " << endl << endl;
        runHistory << "Final Floor Number: " << floorNumber << endl;
        runHistory << "You: " << player.getName() << endl;
        runHistory << "Level: " << player.getLevel() << endl;
        runHistory << "Health: " << player.getHealth() << endl;
        runHistory << "Shield: " << player.getShield() << endl;
        runHistory << "Attack: " << player.getTotalAttack() << endl;
        runHistory << endl << "Final Inventory:" << endl;
        for (int i = 0; i < player.getInventory().size(); i++)
        {
            Loot lootx = player.getInventory()[i];
            runHistory << "[" << i + 1 << "] Loot Name: " << lootx.getName() << endl;
            runHistory << "Description: " << lootx.getDescription() << endl;

            if (lootx.getAttack() != 0)
            {
                runHistory << "Attack Boost: " << lootx.getAttack() << endl;
            }

            if (lootx.getShield() != 0)
            {
                runHistory << "Shield Buff: " << lootx.getShield() << endl;
            }

            if (lootx.getFiery() != 0)
            {
                runHistory << "Fiery: " << lootx.getFiery() << endl;
            }

            if (lootx.getIcy() != 0)
            {
                runHistory << "Icy: " << lootx.getIcy() << endl;
            }
        }
        runHistory << "----------------------" << endl;
    }
}

void generateFloor(Character& player, int floors)
{
    floorNumber++;
    vector<Monster> opponents;
    Monster genMonster;

    //Roll two random monsters for the ecnounter
    genMonster.generateMonster();
    opponents.push_back(genMonster);
    genMonster.generateMonster();
    opponents.push_back(genMonster);

    //Combat
    cout << endl << "You are entering a new floor and ";
    while (player.getHealth() > 0 && (!(opponents.empty())))
    {
        int input = -1;
        cout << "you see " << opponents.size();
        if (opponents.size() < 2)
        {
            cout << " monster!" << endl;
            cout << endl;
        }
        else
        {
            cout << " monsters!" << endl;
            cout << endl;
        }
        for (int i = 0; i < opponents.size(); i++)
        {
            cout << "Monster [" << i+1 << "]" << endl;
            opponents[i].rollIntent();
            opponents[i].printMonster();
            cout << endl;
        }
        player.printCharacter();
        cout << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Attack 2. Defend" << endl;
        cin >> input;
        cout << endl;

        if (input == 1)
        {
            if (opponents.size() > 1)
            {
                cout << "Which monster will you hit?" << endl;
                for (int i = 0; i < opponents.size(); i++)
                {
                    cout << "[" << i+1 << "]" << opponents[i].getName() << " ";
                }
                cout << endl;
                cin >> input;
                if (input > opponents.size() || input <= 0)
                {
                    cout << "Invalid Input.";
                }
                else
                {
                    player.hit(opponents[input-1]); //Player hits desired monster
                    if(opponents[input-1].getHealth() <= 0)
                    {
                        opponents.erase(opponents.begin() + input - 1); //Removes enemy if they die
                    }
                }
            }
            else
            {
                player.hit(opponents[0]); //Player hits the only monster if there is only one
                if(opponents[0].getHealth() <= 0)
                {
                    opponents.pop_back(); //Removes enemy if they die
                }
            }
        }
        else if (input == 2)
        {
            player.defend(); //Player defends from monster before monster action
        }
        else if (input != 1 && input != 2)
        {
            cout << "Invalid Input." << endl;
        }

        if (opponents.empty())
        {
            break;
        }

        if (!(opponents.empty()))
        {
            for (int i = 0; i < opponents.size(); i++)
            {
                if (opponents[i].getIntent() == "Attack")
                {
                    player.getHit(opponents[i]); //Monster hits player if they are alive
                }
                
                if (opponents[i].getIntent() == "Summon")
                {
                    opponents.push_back(opponents[i].summon());
                }
                if (opponents[i].getIntent() == "Grow")
                {
                    opponents[i].grow();
                }
            }
        }
    }

    //Outcomes after combat is finished

    if (player.getHealth() > 0 && floorNumber != floors)
    {
        generateLootLevel(player);
    }
    else if (player.getHealth() > 0 && floorNumber == floors) //If final floor is beaten
    {
        cout << endl << "Congratulations, you beat the game!" << endl;
        generateEndScreen(player);
    }
    else if (player.getHealth() <= 0) //If player dies
    {
        generateEndScreen(player);
    }
}