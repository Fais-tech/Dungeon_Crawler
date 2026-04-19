#include "Character.h"
#include "Monster.h"
#include "Loot.h"
#include "helperFunctions.h"
#include "global.h"
#include <iostream>
using namespace std;

int main()
{
    Character character1;
    int characterChoice = -1;
    int floors = 0;

    //# of floors choice screen
    while (floors <= 0)
    {
        cout << "How many floors would you like to play?" << endl;
        cin >> floors;

        if (!(floors > 0))
        {
            cout << "Invalid Input." << endl;
        }
    }

    //Character choice screen
    while (characterChoice != 1 && characterChoice != 2)
    {
        cout << "Choose your character!" << endl;
        cout << "1. Rogue 2. Warrior" << endl;
        cin >> characterChoice;

        if (characterChoice == 1)
        {
            character1.setCharacter("Rogue", 1, 15, 5, 7);
        }
        else if (characterChoice == 2)
        {
            character1.setCharacter("Warrior", 1, 200, 100, 50);
        }
        else if (characterChoice != 1 && characterChoice != 2)
        {
            cout << "Invalid Input, try again." << endl;
        }
    }

    //Dungeon generation
    for (int i = 0; i < floors; i++)
    {
        if (character1.getHealth() > 0)
        {
            generateFloor(character1, floors);
        }
    }

    return 0;
}