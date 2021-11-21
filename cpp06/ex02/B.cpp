#include "B.hpp"

B::B() {}

B::B(const B &other) { *this = other; }

B::~B() {}

B &B::operator=(const B &rhs) {
  (void)rhs;
  return *this;
}
