#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cstdlib>
#include <iostream>

class Convert {
public:
  Convert();
  Convert(const std::string &literal);
  Convert(const Convert &other);
  ~Convert();
  Convert &operator=(const Convert &rhs);
  void print();

private:
  typedef enum { nonDisplayable, displayable, nan, pInf, nInf } e_type;
  std::string _l;
  e_type _t;

  void checkLiteral();

  void printNan();
  void printInf();
  void printDisplayable();
};

#endif  // CONVERT_HPP