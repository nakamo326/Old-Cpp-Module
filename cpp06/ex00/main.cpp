
#include <iostream>

#include "convert.hpp"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cout << "usage ./convert [literal]";
    return 1;
  }

  return 0;
}
