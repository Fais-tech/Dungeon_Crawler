#ifndef CHARACTER_H
#define CHARACTER_H
#include "Monster.h"
#include "Loot.h"
#include <string>
#include <vector>
using namespace std;

class Character 
{
    public:

    //Setter functions
    void setCharacter(string, int, int, int, int);

    //Getter functions
    string getName();
    int getLevel();
    int getHealth();
    int getShield();
    int getTotalAttack();
    int getTotalShieldValue();
    int getTotalIcyShield();
    int getTotalFieryShield();
    int getTotalIcySword();
    int getTotalFierySword();
    vector<Loot> getInventory();


    //Printer Functions
    void printCharacter();
    void printInventory();

    //Other functions
    void levelUp();
    void addLoot(Loot&);
    void hit(Monster&);
    void defend();
    void getHit(Monster&);
    void heal();
    bool isThereFieryShield();
    bool isThereIcyShield();
    bool isThereFierySword();
    bool isThereIcySword();

    //Constructor
    Character();

    private:
    string name;
    int level;
    int health;
    int shield;
    int attack;
    vector<Loot> inventory;
};

#endif