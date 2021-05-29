#ifndef Character_h
#define Character_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Character {
  public:
    virtual int getTotalHp(int level) = 0;
    virtual int getAttack(int level) = 0;
    virtual int getDefense(int level) = 0;
    virtual int getSpAttack(int level) = 0;
    virtual int getSpDefense(int level) = 0;
    virtual int getSpeed(int level) = 0;
};
#endif
