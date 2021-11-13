#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed z[3];

  z[0] = Point::getCross(a, b, point);
  z[1] = Point::getCross(b, c, point);
  z[2] = Point::getCross(c, a, point);

  if ((z[0] < 0 && z[1] < 0 && z[2] < 0) || (z[0] > 0 && z[1] > 0 && z[2] > 0))
    return true;

  return false;
}
