#include "C.hpp"

C::C() {}

C::C(const C &other) { *this = other; }

C::~C() {}

C &C::operator=(const C &rhs) {
  (void)rhs;
  return *this;
}