#ifndef Battle_h
#define Battle_h

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "Pavodex.h"
#include "BattleMove.h"

using namespace std;

class Battle {
  public:
    Pavodex *pavodex;

    string pavomon1ID;
    string pavomon1Type;
    vector<BattleMove*> pavomon1Moves;
    tuple<int, int, int, int, int> pavomon1Stats;
    int pavomon1HP;
    int pavomon1Level;
    int pavomon1Fatigue;

    string pavomon2ID;
    string pavomon2Type;
    vector<BattleMove*> pavomon2Moves;
    tuple<int, int, int, int, int> pavomon2Stats;
    int pavomon2HP;
    int pavomon2Level;
    int pavomon2Fatigue;

    Battle();
    Battle(
      Pavodex &pavodex,

      string pavomon1ID, 
      string pavomon1Type, 
      vector <BattleMove*> pavomon1Moves, 
      int pavomon1HP,
      int pavomon1Level,
      int pavomon1Fatigue,

      string pavomon2ID, 
      string pavomon2Type, 
      vector <BattleMove*> pavomon2Moves, 
      int pavomon2HP,
      int pavomon2Level,
      int pavomon2Fatigue
    );

    void registerAttack(int player, BattleMove &move);
    tuple<int, int, int, int, int> getStats(string ID, string type, int level);
};

#endif