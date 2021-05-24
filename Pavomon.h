#include <iostream>
#include <string>
#include <Vector>

using namespace std;

#ifndef Pavomon_h
#define Pavomon_h

class Pavomon{

    protected:
        string ID;
        string name;
        string type;
        string gender;
        int baseHp;
        int baseAttack;
        int baseDefense;
        int baseSpAttack;
        int baseSpDefense;
        int baseSpeed;
    };
#endif