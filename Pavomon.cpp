#include <iostream>
#include <string>
#include <vector>

#include "Pavomon.h"

using namespace std;

Pavomon::Pavomon() {}
Pavomon::Pavomon(
  string ID,
  string name,
  string type,
  string gender,
  int baseHp,
  int baseAttack,
  int baseDefense,
  int baseSpAttack,
  int baseSpDefense,
  int baseSpeed
) {
  this -> ID = ID;
  this -> name = name;
  this -> type = type;
  this -> gender = gender;
  this -> baseHp = baseHp;
  this -> baseAttack = baseAttack;
  this -> baseDefense = baseDefense;
  this -> baseSpAttack = baseSpAttack;
  this -> baseSpDefense = baseSpDefense;
  this -> baseSpeed = baseSpeed;
}

vector<BattleMove*> Pavomon::getMoves(vector<BattleMove*> fullList) {
  return fullList;
}

void Pavomon::printPavomon() {
  cout << "Pavomon:" << endl;
  cout << "ID: " << ID << endl;
  cout << "name: " << name << endl;
  cout << "type: " << type << endl;
  cout << "gender: " << gender << endl;
  cout << "baseHp: " << baseHp << endl;
  cout << "baseAttack: " << baseAttack << endl;
  cout << "baseDefense: " << baseDefense << endl;
  cout << "baseSpAttack: " << baseSpAttack << endl;
  cout << "baseSpDefense: " << baseSpDefense << endl;
  cout << "baseSpeed: " << baseSpeed << endl;
  cout << endl;
}