#ifndef LOOT_H
#define LOOT_H
#include <string>
using namespace std;

class Loot
{
    public:

    //Setter functions
    void generateLoot();

    //Getter functions
    string getName();
    string getDescription();
    int getAttack();
    int getShield();
    int getHeal();
    int getFiery();
    int getIcy();

    //Printing function
    void printLoot();

    //Constructor
    Loot();


    private:
    string name;
    string description;
    int attack;
    int shield;
    int heal;
    int fiery;
    int icy;
};

#endif