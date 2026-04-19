#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using namespace std; 

class Monster
{
    public:

    //Setter functions
    void setAttack(int);
    void generateMonster();
    void rollIntent();

    //Getter functions
    int getAttack();
    int getHealth();
    string getName();
    string getIntent();

    //Printing function
    void printMonster();

    //Other functions
    void takeDamage(int);
    Monster summon();
    void grow();

    //Constructor
    Monster();

    private:
    string name;
    int health;
    int maxHealth;
    int attack;
    string intent;
};

#endif