
#include <iostream>

#include "Convert.hpp"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cout << "usage ./convert [literal]" << std::endl;
    return 1;
  }
  Convert c(argv[1]);
  c.output();
  return 0;
}
