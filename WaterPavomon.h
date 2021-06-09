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
      vector<BattleMove*> listOfSameType;

      for (int i = 0; i < fullList.size(); i++) {
        if (fullList[i] -> pavomonType == this -> type) {
          listOfSameType.push_back(fullList[i]);
        }
      }

      vector<BattleMove*> finalMoves;
      for (int j = 0; j < 4; j++) {
        finalMoves.push_back(listOfSameType[j]);
      }

      return finalMoves;
    }

    int getTotalHp(int level) {
      return this->baseHp + (level * 7);
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
