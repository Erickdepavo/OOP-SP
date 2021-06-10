#ifndef intToString_cpp
#define intToString_cpp

#include <iostream>
#include <string>
#include <sstream>

std::string intToString(int number) {
  std::ostringstream oss;
  oss << number;
  return oss.str();
}

#endif
