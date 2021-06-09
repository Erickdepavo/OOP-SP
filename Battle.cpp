#include <iostream>
#include <string>
#include <vector>

#include "Battle.h"

using namespace std;

Battle::Battle(){}

Battle::Battle(
    Pavodex &pavodex,

    string pavomon1ID, 
    string pavomon1Type, 
    vector <BattleMove*> pavomon1Moves,
    int pavomon1Level,

    string pavomon2ID, 
    string pavomon2Type, 
    vector <BattleMove*> pavomon2Moves, 
    int pavomon2Level
) {
    this -> pavodex = &pavodex;

    this -> pavomon1ID = pavomon1ID;
    this -> pavomon1Type = pavomon1Type;
    this -> pavomon1Moves = pavomon1Moves;
    this -> pavomon1Level = pavomon1Level;
    this -> pavomon1Fatigue = 0;
    
    this -> pavomon2ID = pavomon2ID;
    this -> pavomon2Type = pavomon2Type;
    this -> pavomon2Moves = pavomon2Moves;
    this -> pavomon2Level = pavomon2Level;
    this -> pavomon2Fatigue = 0;

    this -> pavomon1HP = getHP(pavomon1ID, pavomon1Type, pavomon1Level);
    this -> pavomon2HP = getHP(pavomon2ID, pavomon2Type, pavomon2Level);

    this -> pavomon1Stats = getStats(pavomon1ID, pavomon1Type, pavomon1Level);
    this -> pavomon2Stats = getStats(pavomon2ID, pavomon2Type, pavomon2Level);

    for (int i = 0; i < pavomon1Moves.size(); i++) {
        pavomon1MoveLimits.push_back(pavomon1Moves[i] -> limit);
    }
    for (int i = 0; i < pavomon2Moves.size(); i++) {
        pavomon2MoveLimits.push_back(pavomon2Moves[i] -> limit);
    }
}

tuple<int, int, int, int, int> Battle::getStats(string ID, string type, int level) {
    if (type == "Normal") {
        for (int i = 0; i < pavodex -> getNormalPavomons().size(); i++) {
            if (pavodex -> getNormalPavomons()[i] -> ID == ID) {
                return make_tuple(
                    pavodex -> getNormalPavomons()[i] -> getAttack(level),
                    pavodex -> getNormalPavomons()[i] -> getDefense(level),
                    pavodex -> getNormalPavomons()[i] -> getSpAttack(level),
                    pavodex -> getNormalPavomons()[i] -> getSpDefense(level),
                    pavodex -> getNormalPavomons()[i] -> getSpeed(level)
                );
            }
        }
    } else if (type == "Fire") {
        for (int i = 0; i < pavodex -> getFirePavomons().size(); i++) {
            if (pavodex -> getFirePavomons()[i] -> ID == ID) {
                return make_tuple(
                    pavodex -> getFirePavomons()[i] -> getAttack(level),
                    pavodex -> getFirePavomons()[i] -> getDefense(level),
                    pavodex -> getFirePavomons()[i] -> getSpAttack(level),
                    pavodex -> getFirePavomons()[i] -> getSpDefense(level),
                    pavodex -> getFirePavomons()[i] -> getSpeed(level)
                );
            }
        }
    } else if (type == "Grass") {
        for (int i = 0; i < pavodex -> getGrassPavomons().size(); i++) {
            if (pavodex -> getGrassPavomons()[i] -> ID == ID) {
                return make_tuple(
                    pavodex -> getGrassPavomons()[i] -> getAttack(level),
                    pavodex -> getGrassPavomons()[i] -> getDefense(level),
                    pavodex -> getGrassPavomons()[i] -> getSpAttack(level),
                    pavodex -> getGrassPavomons()[i] -> getSpDefense(level),
                    pavodex -> getGrassPavomons()[i] -> getSpeed(level)
                );
            }
        }
    } else if (type == "Water") {
        for (int i = 0; i < pavodex -> getWaterPavomons().size(); i++) {
            if (pavodex -> getWaterPavomons()[i] -> ID == ID) {
                return make_tuple(
                    pavodex -> getWaterPavomons()[i] -> getAttack(level),
                    pavodex -> getWaterPavomons()[i] -> getDefense(level),
                    pavodex -> getWaterPavomons()[i] -> getSpAttack(level),
                    pavodex -> getWaterPavomons()[i] -> getSpDefense(level),
                    pavodex -> getWaterPavomons()[i] -> getSpeed(level)
                );
            }
        }
    } else if (type == "Electric") {
        for (int i = 0; i < pavodex -> getElectricPavomons().size(); i++) {
            if (pavodex -> getElectricPavomons()[i] -> ID == ID) {
                return make_tuple(
                    pavodex -> getElectricPavomons()[i] -> getAttack(level),
                    pavodex -> getElectricPavomons()[i] -> getDefense(level),
                    pavodex -> getElectricPavomons()[i] -> getSpAttack(level),
                    pavodex -> getElectricPavomons()[i] -> getSpDefense(level),
                    pavodex -> getElectricPavomons()[i] -> getSpeed(level)
                );
            }
        }
    }
    return make_tuple(0,0,0,0,0);
}

int Battle::getHP(string ID, string type, int level) {
    if (type == "Normal") {
        for (int i = 0; i < pavodex -> getNormalPavomons().size(); i++) {
            if (pavodex -> getNormalPavomons()[i] -> ID == ID) {
                return pavodex -> getNormalPavomons()[i] -> getTotalHp(level);
            }
        }
    } else if (type == "Fire") {
        for (int i = 0; i < pavodex -> getFirePavomons().size(); i++) {
            if (pavodex -> getFirePavomons()[i] -> ID == ID) {
                return pavodex -> getFirePavomons()[i] -> getTotalHp(level);
            }
        }
    } else if (type == "Grass") {
        for (int i = 0; i < pavodex -> getGrassPavomons().size(); i++) {
            if (pavodex -> getGrassPavomons()[i] -> ID == ID) {
                return pavodex -> getGrassPavomons()[i] -> getTotalHp(level);
            }
        }
    } else if (type == "Water") {
        for (int i = 0; i < pavodex -> getWaterPavomons().size(); i++) {
            if (pavodex -> getWaterPavomons()[i] -> ID == ID) {
                return pavodex -> getWaterPavomons()[i] -> getTotalHp(level);
            }
        }
    } else if (type == "Electric") {
        for (int i = 0; i < pavodex -> getElectricPavomons().size(); i++) {
            if (pavodex -> getElectricPavomons()[i] -> ID == ID) {
                return pavodex -> getElectricPavomons()[i] -> getTotalHp(level);
            }
        }
    }
    return 0;
}

void Battle::registerAttack(int player, BattleMove &move) {

    int *playerHP;
    int *opponentHP;

    int *playerLevel;
    int *opponentLevel;

    tuple<int, int, int, int, int> *playerStats;
    tuple<int, int, int, int, int> *opponentStats;

    int *playerFatigue;
    int *opponentFatigue;

    string *playerID;
    string *opponentID;

    string *playerType;
    string *opponentType; 

    if (player == 1) {
        playerHP = &pavomon1HP;
        opponentHP = &pavomon2HP;

        playerLevel = &pavomon1Level;
        opponentLevel = &pavomon2Level;

        playerStats = &pavomon1Stats;
        opponentStats = &pavomon2Stats;

        playerFatigue = &pavomon1Fatigue;
        opponentFatigue = &pavomon2Fatigue;

        playerID = &pavomon1ID;
        opponentID = &pavomon2ID;

        playerType = &pavomon1Type;
        opponentType = &pavomon2Type;
    } else {
        playerHP = &pavomon2HP;
        opponentHP = &pavomon1HP;

        playerLevel = &pavomon2Level;
        opponentLevel = &pavomon1Level;

        playerStats = &pavomon2Stats;
        opponentStats = &pavomon1Stats;

        playerFatigue = &pavomon2Fatigue;
        opponentFatigue = &pavomon1Fatigue;

        playerID = &pavomon2ID;
        opponentID = &pavomon1ID;

        playerType = &pavomon2Type;
        opponentType = &pavomon1Type;
    }

    /*
    Fórmulas:
        damageToOpponent = (Damage * Attack / 100) - (0.2 * (Defense - 100)) + (0.1 * (SpAttack - 100)) - (0.1 * (SpDefense - 100))
        healToPlayer = Heal + Level
    */

    // Aplicar el movimiento
    if (move.moveType == "Damage") {
        // Daño al oponente
        double damageToOpponent = (move.value1 * get<0>(*playerStats) / 100) - (0.2 * (get<1>(*opponentStats) - 100)) + (0.1 * (get<2>(*playerStats) - 100)) - (0.1 * (get<3>(*opponentStats) - 100));
        if (damageToOpponent < 1) { damageToOpponent = 1; }

        *opponentHP = *opponentHP - damageToOpponent;

        if (player == 1) {
            cout << "Attack dealt " << damageToOpponent << " damage to opponent!" << endl;
        } else {
            cout << "Attack dealt " << damageToOpponent << " damage to player!" << endl;
        }

    } else if (move.moveType == "Heal") {
        // Healing al jugador
        int healToPlayer = move.value1 + *playerLevel;
        if (healToPlayer < 1) { healToPlayer = 1; }

        *playerHP = *playerHP + healToPlayer;

        if (player == 1) {
            cout << "Heal gave " << healToPlayer << " HP to player!" << endl;
        } else {
            cout << "Heal gave " << healToPlayer << " HP to opponent!" << endl;
        }

    } else if (move.moveType == "Damage+Heal") {
        // Daño al oponente y healing al jugador
        double damageToOpponent = (move.value1 * get<0>(*playerStats) / 100) - (0.2 * (get<1>(*opponentStats) - 100)) + (0.1 * (get<2>(*playerStats) - 100)) - (0.1 * (get<3>(*opponentStats) - 100));
        int healToPlayer = move.value2 + *playerLevel;
        if (damageToOpponent < 1) { damageToOpponent = 1; }
        if (healToPlayer < 1) { healToPlayer = 1; }

        *opponentHP = *opponentHP - damageToOpponent;
        *playerHP = *playerHP + healToPlayer;

        if (player == 1) {
            cout << "Attack dealt " << damageToOpponent << " damage to opponent!" << endl;
            cout << "Heal gave " << healToPlayer << " HP to player!" << endl;
        } else {
            cout << "Attack dealt " << damageToOpponent << " damage to player!" << endl;
            cout << "Heal gave " << healToPlayer << " HP to opponent!" << endl;
        }

    } else if (move.moveType == "Damage+Damage") {
        // Daño al oponente y daño al jugador
        double damageToOpponent = (move.value1 * get<0>(*playerStats) / 100) - (0.2 * (get<1>(*opponentStats) - 100)) + (0.1 * (get<2>(*playerStats) - 100)) - (0.1 * (get<3>(*opponentStats) - 100));
        double damageToPlayer = (move.value2 * get<0>(*playerStats) / 100) - (0.2 * (get<1>(*playerStats) - 100)) + (0.1 * (get<2>(*playerStats) - 100)) - (0.1 * (get<3>(*playerStats) - 100));

        if (damageToOpponent < 1) { damageToOpponent = 1; }
        if (damageToPlayer < 1) { damageToPlayer = 1; }

        *opponentHP = *opponentHP - damageToOpponent;
        *playerHP = *playerHP - damageToPlayer;

        if (player == 1) {
            cout << "Attack dealt " << damageToOpponent << " damage to opponent!" << endl;
            cout << "Attack dealt " << damageToPlayer << " damage to player!" << endl;
        } else {
            cout << "Attack dealt " << damageToOpponent << " damage to player!" << endl;
            cout << "Attack dealt " << damageToPlayer << " damage to opponent!" << endl;
        }
    }

    // Aplicar el la fatiga al jugador (si existe)
    if (move.fatigue > 0) {
        *playerFatigue = *playerFatigue + move.fatigue;
    } else if (move.fatigue < 0) {
        *opponentFatigue = *opponentFatigue - move.fatigue;
    }

    // Checar que las HP no puedan irse más arriba de su máximo
    int maxPlayerHP = getHP(*playerID,*playerType,*playerLevel);
    if (*playerHP > maxPlayerHP) {
        *playerHP = maxPlayerHP;
    }
    int maxOpponentHP = getHP(*opponentID,*opponentType,*opponentLevel);
    if (*opponentHP > maxOpponentHP) {
        *opponentHP = maxOpponentHP;
    }
    
}