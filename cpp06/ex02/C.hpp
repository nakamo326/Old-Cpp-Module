#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base {
public:
  C();
  C(const C &other);
  ~C();
  C &operator=(const C &rhs);
};

#endif  // C_HPP