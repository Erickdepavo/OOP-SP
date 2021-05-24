#include <iostream>
#include <string>
#include <Vector>

using namespace std;

#ifndef Pavomon_h
#define Pavomon_h

class Pavomon{

    protected:
        string ID;
        string baseName;
        string baseType;
        string gender;
        int baseLevel;
        int baseHp;
        int baseAttack;
        int baseDefense;
        int baseSpAttack;
        int baseSpDefense;
        int baseSpeed;
    };
#endif