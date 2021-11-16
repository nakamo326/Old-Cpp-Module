#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria(other) {}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &rhs) {
  if (this == &rhs)
    return *this;
  return *this;
}

AMateria *Ice::clone() const {
  std::cout << "[Ice] generated a clone." << std::endl;
  return new Ice();
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " BLU << target.getName() << NC " *"
            << std::endl;
}