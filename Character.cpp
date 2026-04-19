#include "Character.h"
#include "global.h"
#include <iostream>
using namespace std;

//Constructor
Character::Character()
{
    name = "Uknown";
    level = 0;
    health = 1;
    shield = 0;
    attack = 1;
}

//Getter Functions
string Character::getName()
{
    return name;
}

int Character::getLevel()
{
    return level;
}

int Character::getHealth()
{
    return health;
}

int Character::getShield()
{
    return shield;
}

int Character::getTotalAttack()
{
    int totalAttack = attack;

    for (int i = 0; i < inventory.size(); i++)
    {
        totalAttack = totalAttack + inventory[i].getAttack();
    }

    return totalAttack;
}

int Character::getTotalShieldValue()
{
    int totalShieldValue = 5 * floorNumber;

    for (int i = 0; i < inventory.size(); i++)
    {
        totalShieldValue = totalShieldValue + inventory[i].getShield();
    }

    return totalShieldValue;
}

int Character::getTotalIcyShield()
{
    int totalIcy = 0;

    for (int i = 0; i < inventory.size(); i++)
    {
        if(inventory[i].getName() == "Icy Shield")
        {
            totalIcy = totalIcy + inventory[i].getIcy();
        }
    }

    return totalIcy;
}

int Character::getTotalFieryShield()
{
    int totalFiery = 0;

    for (int i = 0; i < inventory.size(); i++)
    {
        if(inventory[i].getName() == "Fiery Shield")
        {
            totalFiery = totalFiery + inventory[i].getFiery();
        }
    }

    return totalFiery;
}

int Character::getTotalIcySword()
{
    int totalIcy = 0;

    for (int i = 0; i < inventory.size(); i++)
    {
        if(inventory[i].getName() == "Icy Sword")
        {
            totalIcy = totalIcy + inventory[i].getIcy();
        }
    }

    return totalIcy;
}

int Character::getTotalFierySword()
{
    int totalFiery = 0;

    for (int i = 0; i < inventory.size(); i++)
    {
        if(inventory[i].getName() == "Fiery Sword")
        {
            totalFiery = totalFiery + inventory[i].getFiery();
        }
    }

    return totalFiery;
}

vector<Loot> Character::getInventory()
{
    return inventory;
}

//Setter Functions
void Character::setCharacter(string n, int xp, int hp, int shld, int str)
{
    name = n;
    level = xp;
    health = hp;
    shield = shld;
    attack = str;
}

//Other Functions
void Character::addLoot(Loot& treasure)
{
    inventory.push_back(treasure);
}

void Character::levelUp()
{
    level++;
    health = health + (5 * floorNumber);
    attack = attack + (5 * floorNumber);
    cout << "You level up! You gain " << 5 * floorNumber << " health and " << 5 * floorNumber << " attack!" << endl;
    cout << "You can also shield for 5 more!" << endl;
}

void Character::heal()
{
    Loot potion = inventory.back();
    cout << "You drank the health potion, restoring " << potion.getHeal() << " hit points!" << endl;
    health = health + potion.getHeal();
    inventory.pop_back();
}

bool Character::isThereFieryShield()
{
    bool result = false;
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].getFiery() > 0)
        {
            if(inventory[i].getName() == "Fiery Shield")
            {
                result = true;
            }
        }
    }
    return result;
}

bool Character::isThereIcyShield()
{
    bool result = false;
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].getIcy() > 0)
        {
            if(inventory[i].getName() == "Icy Shield")
            {
                result = true;
            }  
        }
    }
    return result;
}

bool Character::isThereFierySword()
{
    bool result = false;
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].getFiery() > 0)
        {
            if(inventory[i].getName() == "Fiery Sword")
            {
                result = true;
            }
        }
    }
    return result;
}

bool Character::isThereIcySword()
{
    bool result = false;
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].getIcy() > 0)
        {
            if(inventory[i].getName() == "Icy Sword")
            {
                result = true;
            }  
        }
    }
    return result;
}

void Character::hit(Monster& opponent)
{
    cout << "You have hit " << opponent.getName() << " for " << getTotalAttack() << " hit points!" << endl;
    opponent.takeDamage(getTotalAttack());

    if (opponent.getHealth() > 0)
    {
        if (isThereFierySword() == true)
        {
            opponent.takeDamage(getTotalFierySword());
            cout << opponent.getName() << " takes " << getTotalFierySword() << " fire damage!" << endl;
        }

        if (isThereIcySword() == true)
        {
            opponent.setAttack(opponent.getAttack() - getTotalIcySword());
            cout << opponent.getName() << "'s damage is reduced by " << getTotalIcySword() << " points due to ice!" << endl;
        }
    }
}

void Character::defend()
{
    shield = shield + getTotalShieldValue();

    cout << "You shielded for " << getTotalShieldValue() << " points!" << endl;
}

void Character::getHit(Monster& opponent)
{
    int attack = opponent.getAttack();
    cout << opponent.getName() << " attacks for " << attack << " points!" << endl;
    if (shield - attack >= 0)
    {
        cout << "Your shield took " << attack << " points of damage!" << endl;
        shield = shield - attack;
        
    }
    else if (shield - attack < 0)
    {
        attack = attack - shield;
        shield = 0;
        health = health - attack;

        cout << "You were struck directly for " << attack << " hit points!" << endl;
    }

    if (isThereIcyShield() == true)
    {
        opponent.setAttack(opponent.getAttack() - getTotalIcyShield());
        cout << opponent.getName() << "'s damage is reduced by " << getTotalIcyShield() << " points due to ice!" << endl;
    }
    if (isThereFieryShield() == true)
    {
        opponent.takeDamage(getTotalFieryShield());
        cout << opponent.getName() << " takes " << getTotalFieryShield() << " fire damage!" << endl;
    }

    if (health <= 0)
    {
        health = 0;
        cout << endl << "---GAME OVER---" << endl;
        cout << opponent.getName() << " has slain you!" << endl;
    }
}

//Printer functions
void Character::printCharacter()
{
    cout << "You: " << name << endl;
    cout << "HP: " << health << " | Attack: " << getTotalAttack() << endl;
    cout << "Shield: " << shield << " | Shield Power: " << getTotalShieldValue() << endl;
}

void Character::printInventory()
{
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << "[" << i + 1 << "] ";
        inventory[i].printLoot();
    }
}