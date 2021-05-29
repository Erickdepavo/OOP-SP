#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Character.h"
#include "BattleMove.cpp"
#include "Pavomon.cpp"
#include "Pavodex.cpp"

/*
#include "ElectricPavomon.h"
#include "FirePavomon.h"
#include "GrassPavomon.h"
#include "NormalPavomon.h"
#include "WaterPavomon.h"
*/

/*
GitHub: https://github.com/Erickdepavo/OOP-SP
*/

using namespace std;

int main() {

    Pavodex pavodex;
    
    for (int i = 0; i < pavodex.getNormalPavomons().size(); i++) {
        pavodex.getNormalPavomons()[i]->printPavomon();
    }

    for (int i = 0; i < pavodex.getMoves().size(); i++) {
        pavodex.getMoves()[i]->printBattleMove();
    }

    //pavodex.printPavomonList();
    //pavodex.printMovesList();

    return 0;
}