#ifndef Character_h
#define Character_h

#include <iostream>
#include <string>
#include <vector>

#include "Pavomon.h"

using namespace std;

class Character /*public Pavomon*/ {
  public:
    //Pavomon getPavomon();
    //int getLevel();
    //void setLevel(int level);

    int getTotalHp(int level);
    int getAttack(int level);
    int getDefense(int level);
    int getSpAttack(int level);
    int getSpDefense(int level);
    int getSpeed(int level);

    //Character();
    //Character(/*Pavomon pavomon,*/ int level);

  //private:
    //Pavomon pavomon;
    //int level;
};
#endif
