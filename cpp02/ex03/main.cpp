#include "Point.hpp"
#include "bsp.cpp"

int main() {
  Point a(0, 0);
  Point b(3, 5);
  Point c(5, 2);
  Point x(3, 3);

  a.print();
  b.print();
  c.print();
  x.print();
  std::cout << bsp(a, b, c, x) << std::endl;
  std::cout << bsp(a, b, c, a) << std::endl;
  return 0;
}
