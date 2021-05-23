#include <iostream>
#include <string>
#include <Vector>

using namespace std;

#ifndef Pavomon_h
#define Pavomon_h

class Pavomon{

    protected:
        string name;
        string type;
        int hp;
        int attack;
        int defense;
        int spAttack;
        int spDefense;
        int speed;
        string gender;
    };
#endif