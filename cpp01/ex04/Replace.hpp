#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Replace {
  private:
  std::string readFile(const char* path);
  std::string replace(std::string contents, std::string search,
                      std::string replacement);

  public:
  Replace();
  ~Replace();
  void sed(const char* path, std::string search, std::string replacement);
};

#endif