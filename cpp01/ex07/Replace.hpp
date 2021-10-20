#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

class Replace {
  private:
  const char* m_filepath;
  const char* m_search;
  const char* m_replacement;
  std::string m_file_contents;

  bool read_file();
  bool output_file();
  void replace_string();

  public:
  Replace(const char* argv[]);
  ~Replace();
  int sed();
};

#endif