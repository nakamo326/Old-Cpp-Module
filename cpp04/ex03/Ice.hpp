#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice &other);
  ~Ice();
  Ice &operator=(const Ice &rhs);
  AMateria *clone() const;
  void use(ICharacter &target);

private:
};

Ice::Ice() {}

Ice::Ice(const Ice &other) { *this = other; }

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

AMateria *Ice::clone() const {}

void Ice::use(ICharacter &target) {}

#endif  // ICE_HPP