#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base {
public:
  B();
  B(const B &other);
  ~B();
  B &operator=(const B &rhs);
};

#endif  // B_HPP