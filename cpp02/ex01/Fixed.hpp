#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
  private:
  int m_num;
  static const int m_bp = 8;

  public:
  Fixed();
  Fixed(const int num);
  Fixed(const float num);
  Fixed(const Fixed &obj);
  ~Fixed();
  Fixed &operator=(const Fixed &rhs);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &value);

#endif