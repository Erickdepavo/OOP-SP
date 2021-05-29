#include <iostream>
#include <string>
#include <vector>

#include "BattleMove.h"

using namespace std;

BattleMove::BattleMove() {}
BattleMove::BattleMove(
  string pavomonType,
  string moveName,
  string moveType,
  int value,
  int limit
) {
  this -> pavomonType = pavomonType;
  this -> moveName = moveName;
  this -> moveType = moveType;
  this -> value = value;
  this -> limit = limit;
}

void BattleMove::printBattleMove() {
  cout << "BattleMove:" << endl;
  cout << "pavomonType: " << pavomonType << endl;
  cout << "moveName: " << moveName << endl;
  cout << "moveType: " << moveType << endl;
  cout << "value: " << value << endl;
  cout << "limit: " << limit << endl;
  cout << endl;
}

