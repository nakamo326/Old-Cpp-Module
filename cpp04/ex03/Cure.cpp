
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other) { *this = other; }

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &rhs) {
  if (this == &rhs)
    return *this;
  return *this;
}

AMateria *Cure::clone() const {
  std::cout << "[Cure] generated a clone." << std::endl;
  AMateria *ret = new Cure();
  return ret;
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
