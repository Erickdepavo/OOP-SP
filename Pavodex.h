#ifndef Pavodex_h
#define Pavodex_h

#include <iostream>
#include <string>
#include <vector>

#include "NormalPavomon.h"
#include "GrassPavomon.h"
#include "WaterPavomon.h"
#include "FirePavomon.h"
#include "ElectricPavomon.h"
#include "BattleMove.h"

using namespace std;

class Pavodex {
  public:
    void printPavomonList();
    void printMovesList();

    vector<NormalPavomon*> getNormalPavomons();
    vector<GrassPavomon*> getGrassPavomons();
    vector<WaterPavomon*> getWaterPavomons();
    vector<FirePavomon*> getFirePavomons();
    vector<ElectricPavomon*> getElectricPavomons();

    vector<BattleMove*> getMoves();

    Pavodex();

  private:
    vector<NormalPavomon*> normalList;
    vector<GrassPavomon*> grassList;
    vector<WaterPavomon*> waterList;
    vector<FirePavomon*> fireList;
    vector<ElectricPavomon*> electricList;

    vector<BattleMove*> movesList;

    string readFileIntoString(const string& path);
    void readPavomons();
    void readMoves();
};
#endif