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
  Fixed(int num);
  Fixed(float num);
  Fixed(const Fixed &other);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  // Assignation operator overload
  Fixed &operator=(const Fixed &other);

  // comparison operator overload
  bool operator>(const Fixed &a) const;
  bool operator<(const Fixed &a) const;
  bool operator>=(const Fixed &a) const;
  bool operator<=(const Fixed &a) const;
  bool operator==(const Fixed &a) const;
  bool operator!=(const Fixed &a) const;

  // arithmetic operator overload
  Fixed operator+(const Fixed &a) const;
  Fixed operator-(const Fixed &a) const;
  Fixed operator*(const Fixed &a) const;
  Fixed operator/(const Fixed &a) const;

  // increment, decrement operator overload
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  // min, max
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &stream, const Fixed &value);

#endif