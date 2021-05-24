#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Pavomon.h"
#include "BattleMove.h"
#include "electricPavomon.h"
#include "firePavomon.h"
#include "grassPavomon.h"
#include "normalPavomon.h"
#include "waterPavomon.h"

/*
GitHub: https://github.com/Erickdepavo/OOP-SP
*/

using namespace std;

string readFileIntoString(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

void readPavomons() {

    string filename("pavodex.csv");
    string file_contents;

    file_contents = readFileIntoString(filename);
    istringstream sstream(file_contents);

    string ID;
    string name;
    string type;
    string gender;
    string baseHp;
    string baseAttack;
    string baseDefense;
    string baseSpAttack;
    string baseSpDefense;
    string baseSpeed;

    cout << endl << "PAVOMONS" << endl;
    cout << "ID\tNombre\t\tTipo\t\tGénero\t\tHP\tATA\tDEF\tSPA\tSPD\tVelocidad" << endl;

    int count = 0;

    while (getline(sstream, ID, ',')) {
        if (count == 0) {
            count++;
            getline(sstream, name);
            continue;
        }

        cout << ID << "\t"; 

        getline(sstream, name, ',') ;
        cout << name << "  \t"; 

        getline(sstream, type, ',') ;
        cout << type << "    \t"; 

        getline(sstream, gender, ',');
        cout << gender << "\t\t";

        getline(sstream, baseHp, ',');
        cout << baseHp << "\t";

        getline(sstream, baseAttack, ',');
        cout << baseAttack << "\t";

        getline(sstream, baseDefense, ',');
        cout << baseDefense << "\t";

        getline(sstream, baseSpAttack, ',');
        cout << baseSpAttack << "\t";

        getline(sstream, baseSpDefense, ',');
        cout << baseSpDefense << "\t";

        getline(sstream, baseSpeed);
        cout << baseSpeed;

        cout << endl;
    }
}

void readMoves() {

    string filename("moves.csv");
    string file_contents;

    file_contents = readFileIntoString(filename);
    istringstream sstream(file_contents);

    string pavomonType;
    string moveName;
    string moveType;
    string value;
    string limit;

    cout << endl << "MOVIMIENTOS" << endl;
    cout << "Tipo\t\tNombre\t\tEstilo\tDaño\tLímite de usos" << endl;

    int count = 0;

    while (getline(sstream, pavomonType, ',')) {
        if (count == 0) {
            count++;
            getline(sstream, moveName);
            continue;
        }

        cout << pavomonType << "    \t"; ; 

        getline(sstream, moveName, ',') ;
        cout << moveName << "   \t"; 

        getline(sstream, moveType, ',') ;
        cout << moveType << "\t"; 

        getline(sstream, value, ',');
        cout << value << "\t";

        getline(sstream, limit);
        cout << limit;

        cout << endl;
    }
}


int main() {

    vector<Pavomon> pavomons;
    vector<BattleMove> moves;

    readPavomons();
    readMoves();

    return 0;
}