#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed z[3];
  // point + 二つの点から　ベクトルを二つ求める。
  // a1b2 -a2b1
  // abp
  z[0] = Point::getCross(a, b, point);
  // bcp
  z[1] = Point::getCross(b, c, point);
  // cap
  z[2] = Point::getCross(c, a, point);

  if ((z[0] < 0 && z[1] < 0 && z[2] < 0) || (z[0] > 0 && z[1] > 0 && z[2] > 0))
    return true;

  return false;
}
