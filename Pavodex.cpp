#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Pavodex.h"

using namespace std;

string Pavodex::readFileIntoString(const string& path) {
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

Pavodex::Pavodex() {
  this->readPavomons();
  this->readMoves();
}

void Pavodex::readPavomons() {
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

  getline(sstream, ID); // Skip first line

  while (getline(sstream, ID, ',')) {
    getline(sstream, name, ',') ;
    getline(sstream, type, ',') ;
    getline(sstream, gender, ',');
    getline(sstream, baseHp, ',');
    getline(sstream, baseAttack, ',');
    getline(sstream, baseDefense, ',');
    getline(sstream, baseSpAttack, ',');
    getline(sstream, baseSpDefense, ',');
    getline(sstream, baseSpeed);

    if (type == "Normal") {
      normalList.push_back(new NormalPavomon(ID, name, type, gender, stoi(baseHp), stoi(baseAttack), stoi(baseDefense), stoi(baseSpAttack), stoi(baseSpDefense), stoi(baseSpeed)));
    } else if (type == "Grass") {
      grassList.push_back(new GrassPavomon(ID, name, type, gender, stoi(baseHp), stoi(baseAttack), stoi(baseDefense), stoi(baseSpAttack), stoi(baseSpDefense), stoi(baseSpeed)));
    } else if (type == "Water") {
      waterList.push_back(new WaterPavomon(ID, name, type, gender, stoi(baseHp), stoi(baseAttack), stoi(baseDefense), stoi(baseSpAttack), stoi(baseSpDefense), stoi(baseSpeed)));
    } else if (type == "Fire") {
      fireList.push_back(new FirePavomon(ID, name, type, gender, stoi(baseHp), stoi(baseAttack), stoi(baseDefense), stoi(baseSpAttack), stoi(baseSpDefense), stoi(baseSpeed)));
    } else if (type == "Electric") {
      electricList.push_back(new ElectricPavomon(ID, name, type, gender, stoi(baseHp), stoi(baseAttack), stoi(baseDefense), stoi(baseSpAttack), stoi(baseSpDefense), stoi(baseSpeed)));
    }
  }
}

void Pavodex::readMoves() {
  string filename("moves.csv");
  string file_contents;

  file_contents = readFileIntoString(filename);
  istringstream sstream(file_contents);

  string pavomonType;
  string moveName;
  string moveType;
  string value1;
  string value2;
  string limit;
  string fatigue;

  getline(sstream, pavomonType); // Skip first line

  while (getline(sstream, pavomonType, ',')) {
    getline(sstream, moveName, ',') ;
    getline(sstream, moveType, ',') ;
    getline(sstream, value1, ',');
    getline(sstream, value2, ',');
    getline(sstream, limit, ',');
    getline(sstream, fatigue);

    movesList.push_back(new BattleMove(pavomonType, moveName, moveType, stoi(value1), stoi(value2), stoi(limit), stoi(fatigue)));
  }
}

vector<NormalPavomon*> Pavodex::getNormalPavomons() {
  return this -> normalList;
}
vector<GrassPavomon*> Pavodex::getGrassPavomons(){
  return this -> grassList;
}
vector<WaterPavomon*> Pavodex::getWaterPavomons(){
  return this -> waterList;
}
vector<FirePavomon*> Pavodex::getFirePavomons(){
  return this -> fireList;
}
vector<ElectricPavomon*> Pavodex::getElectricPavomons(){
  return this -> electricList;
}
vector<BattleMove*> Pavodex::getMoves() {
  return this -> movesList;
}

void Pavodex::printPavomonList() {
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

  getline(sstream, ID); // Skip first line

  while (getline(sstream, ID, ',')) {
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

void Pavodex::printMovesList() {
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

  getline(sstream, pavomonType); // Skip first line

  while (getline(sstream, pavomonType, ',')) {
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
