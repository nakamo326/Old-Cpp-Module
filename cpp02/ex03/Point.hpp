#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

#include "Fixed.hpp"

class Point {
  private:
  const Fixed _x;
  const Fixed _y;

  public:
  Point();
  ~Point();
  Point(const Fixed &obj);
  Point(const float x, const float y);
  Point &operator=(const Point &rhs);
  void print();
  const Fixed get_x() const;
  const Fixed get_y() const;

  static Fixed getCross(const Point v, const Point w, const Point point);
};

#endif  // POINT_HPP