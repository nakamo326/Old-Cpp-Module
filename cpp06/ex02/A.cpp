#include "A.hpp"

A::A() {}

A::A(const A &other) { *this = other; }

A::~A() {}

A &A::operator=(const A &rhs) {
  (void)rhs;
  return *this;
}
