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
  typedef enum { nonDisplayable, displayable, nan, pInf, nInf } e_type;

private:
  std::string _l;
  e_type _t;

  Convert::e_type checkLiteral();
  Convert::e_type checkDisplayable();

  bool isDigits();

  void printNan();
  void printInf();
  void printDisplayable();
  void printNonDisplayable();
};

#endif  // CONVERT_HPP