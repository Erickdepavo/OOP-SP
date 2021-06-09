#ifndef randomInt_cpp
#define randomInt_cpp

#include <iostream>
#include <random>

int randomInt(int range_from, int range_to) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);
 
    return distr(generator);
};

/*
int main() {
  
  for (int i = 0; i < 10; ++i) {
    std::cout << randomInt(0,4) << std::endl;
  }

  return 0;
}
*/

#endif