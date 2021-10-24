#ifndef CAT_HPP
#define CAT_HPP

#include <cstdlib>
#include <iostream>
#include <istream>
#include <sstream>

class Cat {
  private:
  int outputError();

  public:
  Cat();
  ~Cat();
  int readStdIn();
  int readFile(const char* path);
};

#endif  // CAT_HPP
