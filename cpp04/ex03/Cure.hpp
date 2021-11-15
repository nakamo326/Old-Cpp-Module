#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(const Cure &other);
  ~Cure();
  Cure &operator=(const Cure &rhs);
  AMateria *clone() const;
  void use(ICharacter &target);

private:
};

Cure::Cure() {}

Cure::Cure(const Cure &other) { *this = other; }

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

AMateria *Cure::clone() const {}

void Cure::use(ICharacter &target) {}

#endif  // CURE_HPP