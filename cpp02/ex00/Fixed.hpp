#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
  private:
  int m_num;
  static const int m_bp = 8;

  public:
  Fixed();
  Fixed(const Fixed &obj);
  ~Fixed();
  Fixed &operator=(const Fixed &rhs);
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif