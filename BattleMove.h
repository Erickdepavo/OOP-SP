#ifndef BattleMove_h
#define BattleMove_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BattleMove {
  public:
    string pavomonType;
    string moveName;
    string moveType;
    int value1;
    int value2;
    int limit;
    int fatigue;

    void printBattleMove();

    BattleMove();
    BattleMove(
      string pavomonType,
      string moveName,
      string moveType,
      int value1,
      int value2,
      int limit,
      int fatigue
    );
};

#endif