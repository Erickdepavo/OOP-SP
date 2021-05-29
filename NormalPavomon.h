#ifndef NormalPavomon_h
#define NormalPavomon_h

#include <iostream>
#include <string>
#include <vector>
#include "Pavomon.h"

using namespace std;

class NormalPavomon: public Pavomon, public Character {
  using Pavomon::Pavomon;

  public:
    vector<BattleMove*> getMoves(vector<BattleMove*> fullList) {
      return fullList;
    }
};

#endif
