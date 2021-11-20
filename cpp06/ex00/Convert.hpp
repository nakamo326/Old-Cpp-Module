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
  Convert();
  Convert(const std::string &literal);
  Convert(const Convert &other);
  ~Convert();
  Convert &operator=(const Convert &rhs);
  void convert();
  typedef enum { def, nan, pInf, nInf, _char, _int, _float, _double } e_type;

private:
  std::string _l;
  e_type _t;
  double _d;

  std::stringstream _ss_c;
  std::stringstream _ss_i;
  std::stringstream _ss_f;
  std::stringstream _ss_d;

  Convert::e_type checkType();
  void getValue();

  void printChar();
  void printInt();
  void printFloat();
  void printDouble();
  void printNonDisplayable();

  void output();

  template <typename T>
  void printAsChar(T n) {
    if (n >= 32 && n <= 126)
      _ss_c << "'" << static_cast<char>(n) << "'";
    else if (n <= std::numeric_limits<char>::max() &&
             n >= std::numeric_limits<char>::min())
      _ss_c << "Non displayable";
    else
      _ss_c << "impossible";
  }

  template <typename T>
  void printAsInt(T n) {
    if (n <= std::numeric_limits<int>::max() &&
        n >= std::numeric_limits<int>::min())
      _ss_i << static_cast<int>(n);
    else
      _ss_i << "impossible";
  }

  template <typename T>
  void printAsFloat(T n) {
    int p = std::floor(n) == n ? 1 : 10;
    _ss_f << std::fixed << std::setprecision(p) << static_cast<float>(n) << "f";
  }

  template <typename T>
  void printAsDouble(T n) {
    int p = std::floor(n) == n ? 1 : 10;
    _ss_d << std::fixed << std::setprecision(p) << static_cast<double>(n);
  }
};

#endif  // CONVERT_HPP