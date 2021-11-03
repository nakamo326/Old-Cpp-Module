#include <iostream>

#include "Fixed.hpp"

int main(void) {
  Fixed a;

  std::cout << "a = " << a << std::endl;
  std::cout << "pre-increment : " << ++a << std::endl;
  std::cout << "after pre-inc : " << a << std::endl;
  std::cout << "post-increment: " << a++ << std::endl;
  std::cout << "after post-inc: " << a << std::endl;
  std::cout << "pre-decrement : " << --a << std::endl;
  std::cout << "after pre-dec : " << a << std::endl;
  std::cout << "post-decrement: " << a-- << std::endl;
  std::cout << "after post-dec: " << a << std::endl;

  Fixed const b(Fixed(5.05f) * Fixed(2));
  std::cout << "b(Fixed(5.05f) * Fixed(2)) = " << b << std::endl;
  Fixed c = Fixed(10.0f) / Fixed(4);
  std::cout << "c: Fixed(10.0f) / Fixed(4) = " << c << std::endl;
  Fixed d = Fixed(3.34f) + Fixed(4);
  std::cout << "d: Fixed(3.34f) + Fixed(4) = " << d << std::endl;
  Fixed e;
  e = Fixed(5) - Fixed(2);
  std::cout << "e: Fixed(5) - Fixed(2) = " << e << std::endl;

  std::cout << "Fixed::max(a, b) = " << Fixed::max(a, b) << std::endl;
  std::cout << "Fixed::max(c, d) = " << Fixed::max(c, d) << std::endl;
  std::cout << "Fixed::min(a, b) = " << Fixed::min(a, b) << std::endl;
  std::cout << "Fixed::min(c, d) = " << Fixed::min(c, d) << std::endl;

  std::cout << "====check overflow====" << std::endl;
  // 2^(23 + 8) - 1
  std::cout << std::fixed << Fixed(8388607) << std::endl;
  std::cout << std::fixed << Fixed(8388608) << std::endl;

  // 2^(10 + 8) * 2^(10 + 8)
  std::cout << Fixed(1024) * Fixed(1024) << std::endl;

  std::cout << Fixed(0.1f) * Fixed(0.1f) << std::endl;
  std::cout << Fixed(4096) / Fixed(0.125f) << std::endl;
  return 0;
}
