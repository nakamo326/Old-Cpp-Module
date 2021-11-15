#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) { *this = other; }

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &rhs) {
  if (this == &rhs)
    return *this;
  return *this;
}

// test
AMateria *Ice::clone() const {
  std::cout << "[Ice] generated a clone." << std::endl;
  return new Ice();
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}