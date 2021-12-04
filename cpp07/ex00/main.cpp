#include "whatever.hpp"

int main(void) {
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << GRN "a = " << a << ", b = " << b << NC << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << GRN "c = " << c << ", d = " << d << NC << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
  {
    float e = 3.45;
    float f = 8.67;
    ::testAll(e, f);
  }
  {
    double e = 1234567.2345678;
    double f = 9999.1234;
    ::testAll(e, f);
  }

  return 0;
}