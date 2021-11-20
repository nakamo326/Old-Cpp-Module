#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

class Convert {
public:
  Convert();
  Convert(const std::string &literal);
  Convert(const Convert &other);
  ~Convert();
  Convert &operator=(const Convert &rhs);
  void print();
  typedef enum {
    nonDisplayable,
    nan,
    pInf,
    nInf,
    _char,
    _int,
    _float,
    _double
  } e_type;

private:
  std::string _l;
  e_type _t;

  Convert::e_type checkType();
  Convert::e_type checkDisplayable();

  void printNonDisplayable();
  void printChar();
  void printInt();
  void printFloat();
  void printDouble();
  int getPrec(double d);
};

#endif  // CONVERT_HPP