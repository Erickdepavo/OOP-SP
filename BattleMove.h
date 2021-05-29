#ifndef BattleMove_h
#define BattleMove_h

#include <iostream>
#include <string>
#include <vector>

#include "Pavomon.h"

using namespace std;

class BattleMove {
  public:
    string pavomonType;
    string moveName;
    string moveType;
    int value;
    int limit;

    void printBattleMove();

    BattleMove();
    BattleMove(
      string pavomonType,
      string moveName,
      string moveType,
      int value,
      int limit
    );
};

#endif