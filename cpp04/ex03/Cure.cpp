
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other) : AMateria(other) {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &rhs) {
  if (this == &rhs)
    return *this;
  return *this;
}

AMateria *Cure::clone() const {
  std::cout << "[Cure] generated a clone." << std::endl;
  return new Cure();
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " BLU << target.getName() << NC "’s wounds *"
            << std::endl;
}
