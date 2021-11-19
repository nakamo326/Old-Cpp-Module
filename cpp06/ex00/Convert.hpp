#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

class Convert {
public:
  Convert();
  Convert(const std::string &literal);
  Convert(const Convert &other);
  ~Convert();
  Convert &operator=(const Convert &rhs);
  void print();

private:
  typedef enum { displayable, nan, pInf, nInf } e_type;
  std::string _l;
  e_type _t;

  void checkLiteral();

  void printNan();
  void printInf();
  void printDisplayable();

  void outputFloat();
  void outputDouble();
};

#endif  // CONVERT_HPP