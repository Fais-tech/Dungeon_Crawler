#include "Loot.h"
#include "global.h"
#include <iostream>
#include <random>
using namespace std;

//Constructor
Loot::Loot()
{
    name = "Scrap";
    description = "Does not seem to be of much use.";
    attack = 0;
    shield = 0;
    heal = 0;
    fiery = 0;
    icy = 0;
}

//Getter Functions
string Loot::getName()
{
    return name;
}

string Loot::getDescription()
{
    return description;
}

int Loot::getAttack()
{
    return attack;
}

int Loot::getShield()
{
    return shield;
}

int Loot::getHeal()
{
    return heal;
}

int Loot::getFiery()
{
    return fiery;
}

int Loot::getIcy()
{
    return icy;
}

//Other Functions
void Loot::generateLoot()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 3);

    int lootType = dist(gen);
    int enchant = dist(gen);

    if (lootType == 1)
    {
        if (enchant == 1)
        {
            name = "Sword";
            description = "An average sword, used to slay creatures.";
            attack = 3 * floorNumber;
        }
        else if (enchant == 2)
        {
            name = "Fiery Sword";
            description = "A fiery sword, will cause damage over time to your foes.";
            attack = 3 * floorNumber;
            fiery = 2 * floorNumber;
        }
        else if (enchant == 3)
        {
            name = "Icy Sword";
            description = "An icy sword, will cause your opponents to lose damage.";
            attack = 3 * floorNumber;
            icy = 2 * floorNumber;
        }
    }
    else if (lootType == 2)
    {
        if (enchant == 1)
        {
            name = "Shield";
            description = "An average shield, will increase your block against enemies.";
            shield = 4 * floorNumber;
        }
        else if (enchant == 2)
        {
            name = "Fiery Shield";
            description = "A fiery shield, will cause those who strike you to take damage.";
            shield = 4 * floorNumber;
            fiery = 2 * floorNumber;
        }
        else if (enchant == 3)
        {
            name = "Icy Shield";
            description = "An icy shield, will cause those who strike you to lose strength.";
            shield = 4 * floorNumber;
            icy = 2 * floorNumber;
        }
    }
    else if (lootType == 3)
    {
        name = "Health Potion";
        heal = 7 * floorNumber;
        description = "Drink instantly to restore " + to_string(heal) + " health points.";
    }
}

//Print Functions
void Loot::printLoot()
{
    cout << "Loot name: " << name << endl;
    cout << "Description: " << description << endl;
    if (attack != 0)
    {
        cout << "Attack Boost: " << attack << endl;
    }

    if (shield != 0)
    {
        cout << "Shield Buff: " << shield << endl;
    }

    if (heal != 0)
    {
        cout << "Healing amount: " << heal << endl;
    }

    if (fiery != 0)
    {
        cout << "Fiery: " << fiery << endl;
    }

    if (icy != 0)
    {
        cout << "Icy: " << icy << endl;  
    } 
}