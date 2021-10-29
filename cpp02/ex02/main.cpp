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
  std::cout << "b = " << b << std::endl;
  Fixed c = Fixed(10.0f) / Fixed(4);
  std::cout << "c = " << c << std::endl;
  Fixed d = Fixed(3.34f) + Fixed(4);
  std::cout << "d = " << d << std::endl;
  Fixed e;
  e = Fixed(5) - Fixed(2);
  std::cout << e << std::endl;

  std::cout << Fixed::max(a, b) << std::endl;
  std::cout << Fixed::max(c, d) << std::endl;

  return 0;
}
