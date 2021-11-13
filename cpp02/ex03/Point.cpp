#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {
}

Point::~Point() {
}

Point::Point(const Fixed &obj) {
  *this = obj;
}

Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y)) {
}

Point &Point::operator=(const Point &rhs) {
  if (this == &rhs)
    return *this;
  const_cast<Fixed &>(_x) = rhs._x;
  const_cast<Fixed &>(_y) = rhs._y;
  return *this;
}

void Point::print() {
  std::cout << "(" << _x << ", " << _y << ")" << std::endl;
}

const Fixed Point::get_x() const {
  return _x;
}

const Fixed Point::get_y() const {
  return _y;
}

Fixed Point::getCross(const Point a, const Point b, const Point point) {
  Fixed v[2], w[2];

  v[0] = b.get_x() - a.get_x();
  v[1] = b.get_y() - a.get_y();

  w[0] = point.get_x() - a.get_x();
  w[1] = point.get_y() - a.get_y();

  return v[0] * w[1] - v[1] * w[0];
}