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
  int value1,
  int value2,
  int limit,
  int fatigue
) {
  this -> pavomonType = pavomonType;
  this -> moveName = moveName;
  this -> moveType = moveType;
  this -> value1 = value1;
  this -> value2 = value2;
  this -> limit = limit;
  this -> fatigue = fatigue;
}

void BattleMove::printBattleMove() {
  cout << "BattleMove:" << endl;
  cout << "pavomonType: " << pavomonType << endl;
  cout << "moveName: " << moveName << endl;
  cout << "moveType: " << moveType << endl;
  cout << "value1: " << value1 << endl;
  cout << "value2: " << value2 << endl;
  cout << "limit: " << limit << endl;
  cout << "fatigue: " << fatigue << endl;
  cout << endl;
}

string BattleMove::getMoveDescription() {
  string output = "";
  if (moveType == "Damage") {
    // Daño al oponente
    output += "Damage " + intToString(value1);
  } else if (moveType == "Heal") {
    // Healing al jugador
    output += "Heal " + intToString(value1);

  } else if (moveType == "Damage+Heal") {
    // Daño al oponente y healing al jugador
    output += "Damage " + intToString(value1);
    output += " Heal " + intToString(value2);

  } else if (moveType == "Damage+Damage") {
    // Daño al oponente y daño al jugador
    output += "Damage " + intToString(value1);
    output += " Self Damage " + intToString(value2);
  }

  //output += ", Limit " + intToString(limit)
  if (fatigue != 0) {
    output += ", Fat. " + intToString(fatigue);
  }
  return output;
}

