#ifndef Battle_h
#define Battle_h

#include <iostream>
#include <string>
#include <vector>

#include "BattleMove.h"

using namespace std;

class Battle {
  public:
    string pavomon1ID;
    string pavomon1Type;
    vector<BattleMove*> pavomon1Moves;
    int pavomon1HP;
    int pavomon1Level;

    string pavomon2ID;
    string pavomon2Type;
    vector<BattleMove*> pavomon2Moves;
    int pavomon2HP;
    int pavomon2Level;

    // Crear constructor
    // ...
};

#endif