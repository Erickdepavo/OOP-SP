#ifndef WaterPavomon_h
#define WaterPavomon_h

#include <iostream>
#include <string>
#include <vector>
#include "Pavomon.h"

using namespace std;

class WaterPavomon: public Pavomon, public Character {
  using Pavomon::Pavomon;

  public:
    vector<BattleMove*> getMoves(vector<BattleMove*> fullList) {
      return fullList;
    }
};

#endif