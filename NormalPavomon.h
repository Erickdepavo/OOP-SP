#ifndef NormalPavomon_h
#define NormalPavomon_h

#include <iostream>
#include <string>
#include <vector>
#include "Pavomon.h"
#include "randomInt.cpp"

using namespace std;

class NormalPavomon: public Pavomon, public Character {
  using Pavomon::Pavomon;

  public:
    vector<BattleMove*> getMoves(vector<BattleMove*> fullList) {
      vector<BattleMove*> listOfSameType;
      vector<int> listIndexes;

      for (int i = 0; i < fullList.size(); i++) {
        if (fullList[i] -> pavomonType == this -> type) {
          listOfSameType.push_back(fullList[i]);
        }
      }
      for (int i = 0; i < listOfSameType.size(); i++) {
        listIndexes.push_back(i);
      }

      vector<BattleMove*> finalMoves;
      for (int j = 0; j < 4; j++) {
        int i = randomInt(0, listIndexes.size() - 1);
        finalMoves.push_back(listOfSameType[listIndexes[i]]);
        listIndexes.erase(listIndexes.begin() + i);       
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
