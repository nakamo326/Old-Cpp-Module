#ifndef CAT_HPP
#define CAT_HPP

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

class Cat {
  private:
  int outputError(const std::string& msg);

  public:
  Cat();
  ~Cat();
  int readStdIn();
  int readFile(const char* path);
};

#endif  // CAT_HPP
