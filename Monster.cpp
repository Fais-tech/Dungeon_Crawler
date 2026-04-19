#include "Monster.h"
#include "global.h"
#include "Character.h"
#include <iostream>
#include <random>
using namespace std;

//Constructor
Monster::Monster()
{
    name = "Unknown";
    health = 1;
    maxHealth = 1;
    attack = 1;
    intent = "Unknown";
}

//Getter functions
int Monster::getAttack()
{
    return attack;
}

int Monster::getHealth()
{
    return health;
}

string Monster::getName()
{
    return name;
}

string Monster::getIntent()
{
    return intent;
}

//Setter Functions
void Monster::setAttack(int atk)
{
    attack = atk;
    if (attack < 0)
    {
        attack = 0;
    }
}

void Monster::generateMonster()
{
    static mt19937 gen(random_device{}());
    uniform_int_distribution<> dist(1, 3);

    int choice = dist(gen);
    int variance = dist(gen);

    if (choice == 1)
    {
        name = "Goblin";
        health = 3 * (3 * floorNumber) - (variance * floorNumber);
        maxHealth = health;
        attack = 6 * (3 * floorNumber);
    }

    if (choice == 2)
    {
        name = "Slime";
        health = 6 * (3 * floorNumber) - (variance * floorNumber);
        maxHealth = health;
        attack = 2 * (3* floorNumber);
    }

    if (choice == 3)
    {
        name = "Necromancer";
        health = 3 * (3 * floorNumber) - (variance * floorNumber);
        maxHealth = health;
        attack = 1 * (3 * floorNumber);
    }
}

void Monster::rollIntent() //Controls the decison-making of the monsters
{
    if (name == "Goblin")
    {
        intent = "Attack";
    }

    if (name == "Slime")
    {
        if (health != maxHealth)
        {
            intent = "Attack";
        }
        else
        {
            intent = "Grow";
        }
    }

    if (name == "Necromancer")
    {
        if (health >= maxHealth / 2)
        {
            intent = "Attack";
        }
        else
        {
            intent = "Summon";
        }
    }

    if (name == "Bones")
    {
        intent = "Attack";
    }
}

//Other functions

void Monster::takeDamage(int dmg)
{
    health = health - dmg;

    if (health <= 0)
    {
        attack = 0;
        health = 0;
        cout << name << " has been vanquished!" << endl;
    }
}

Monster Monster::summon()
{
    Monster* bone = new Monster;
    bone->name = "Bones";
    bone->health = 2 * (3 * floorNumber);
    bone->maxHealth = 2 * (3 * floorNumber);
    bone->attack = 2 * (3 * floorNumber);
    bone->intent = "Stunned";

    cout << this->name << " summons a Bones!" << endl;
    return *bone;
}

void Monster::grow()
{
    attack = attack + (1 * floorNumber);
    health = health + (3 * floorNumber);
    maxHealth = maxHealth + (3 * floorNumber);

    cout << this->name << " grows in size and strength!" << endl;
}

//Print Functions
void Monster::printMonster()
{
    cout << "Monster: " << name << endl;
    cout << "HP: " << health << "/" << maxHealth << " | Attack Dmg: " << attack << endl;
    cout << "Intent: " << intent << endl;
}