#include <iostream>
#include <string>
#include <vector>

#include "Battle.h"

using namespace std;

Battle::Battle(){}

Battle::Battle(
    string pavomon1ID, 
    string pavomon1Type, 
    vector <BattleMove*> pavomon1Moves, 
    int pavomon1HP,
    int pavomon1Level,

    string pavomon2ID, 
    string pavomon2Type, 
    vector <BattleMove*> pavomon2Moves, 
    int pavomon2HP,
    int pavomon2Level){

    this -> pavomon1ID = pavomon1ID;
    this -> pavomon1Type = pavomon1Type;
    this -> pavomon1Moves = pavomon1Moves;
    this -> pavomon1HP = pavomon1HP;
    this -> pavomon1Level = pavomon1Level;
    
    this -> pavomon2ID = pavomon2ID;
    this -> pavomon2Type = pavomon2Type;
    this -> pavomon2Moves = pavomon2Moves;
    this -> pavomon2HP = pavomon2HP;
    this -> pavomon2Level = pavomon2Level;
    
}