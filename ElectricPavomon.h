#ifndef ElectricPavomon_h
#define ElectricPavomon_h

#include <iostream>
#include <string>
#include <vector>
#include "Pavomon.h"

using namespace std;

class ElectricPavomon: public Pavomon, public Character {
  using Pavomon::Pavomon;

  public:
    vector<BattleMove*> getMoves(vector<BattleMove*> fullList) {
      return fullList;
    }
    
    int getTotalHp(int level) {
      return this->baseHp + level;
    }
    int getAttack(int level) {
      return this->baseAttack + level;
    }
    int getDefense(int level) {
      return this->baseDefense + level;
    }
    int getSpAttack(int level) {
      return this->baseSpAttack + level;
    }
    int getSpDefense(int level) {
      return this->baseSpDefense + level;
    }
    int getSpeed(int level) {
      return this->baseSpeed + level;
    }
};

#endif