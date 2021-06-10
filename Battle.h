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
    string pavomon1Name;
    vector<BattleMove*> pavomon1Moves;
    vector<int> pavomon1MoveLimits;
    tuple<int, int, int, int, int> pavomon1Stats;
    int pavomon1HP;
    int pavomon1Level;
    int pavomon1Fatigue;

    string pavomon2ID;
    string pavomon2Type;
    string pavomon2Name;
    vector<BattleMove*> pavomon2Moves;
    vector<int> pavomon2MoveLimits;
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
      int pavomon1Level,

      string pavomon2ID, 
      string pavomon2Type, 
      vector <BattleMove*> pavomon2Moves, 
      int pavomon2Level
    );

    void registerAttack(int player, BattleMove &move);
    tuple<int, int, int, int, int> getStats(string ID, string type, int level);
    int getHP(string ID, string type, int level);
    string getName(string ID, string type, int level);
};

#endif