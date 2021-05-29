#ifndef Pavomon_h
#define Pavomon_h

#include <iostream>
#include <string>
#include <vector>

#include "Character.h"
#include "BattleMove.h"

using namespace std;

class Pavomon {
  public:
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

    virtual vector<BattleMove*> getMoves(vector<BattleMove*> fullList) = 0;

    void printPavomon();

    Pavomon();
    Pavomon(
      string ID,
      string name,
      string type,
      string gender,
      int baseHp,
      int baseAttack,
      int baseDefense,
      int baseSpAttack,
      int baseSpDefense,
      int baseSpeed
    );
};
#endif