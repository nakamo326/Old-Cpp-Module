#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

class Convert {
public:
  Convert(const std::string &literal);
  Convert(const Convert &other);
  ~Convert();
  Convert &operator=(const Convert &rhs);
  void convert();
  typedef enum { def, nan, pInf, nInf, _char, _int, _float, _double } e_type;

private:
  Convert();

  std::string _l;
  e_type _t;
  double _d;

  bool _overflowC;
  bool _overflowI;
  bool _overflowF;
  bool _overflowD;
  bool _isInf;

  std::stringstream _ss_c;
  std::stringstream _ss_i;
  std::stringstream _ss_f;
  std::stringstream _ss_d;

  Convert::e_type detectType();

  void getValue();
  void printAsChar();
  void printAsInt();
  void printAsFloat();
  void printAsDouble();
  void printNonDisplayable();

  void detectOverflow(double d);

  void output();

  template <typename T>
  void printAll(T n) {
    printChar<T>(n);
    printInt<T>(n);
    printFloat<T>(n);
    printDouble<T>(n);
  }

  template <typename T>
  void printChar(T n) {
    if (n >= 32 && n <= 126)
      _ss_c << "'" << static_cast<char>(n) << "'";
    else if (!_overflowC)
      _ss_c << "Non displayable";
    else
      _ss_c << "impossible";
  }

  template <typename T>
  void printInt(T n) {
    if (!_overflowI)
      _ss_i << static_cast<int>(n);
    else
      _ss_i << "impossible";
  }

  template <typename T>
  void printFloat(T n) {
    int p = std::floor(n) == n ? 1 : 10;
    if (!_overflowF || _isInf)
      _ss_f << std::fixed << std::setprecision(p) << static_cast<float>(n)
            << "f";
    else
      _ss_f << "impossible";
  }

  template <typename T>
  void printDouble(T n) {
    int p = std::floor(n) == n ? 1 : 10;
    if (!_overflowD)
      _ss_d << std::fixed << std::setprecision(p) << static_cast<double>(n);
    else
      _ss_d << "impossible";
  }
};

#endif  // CONVERT_HPP