#include "AMateria.hpp"

AMateria::AMateria() {
}

AMateria::AMateria(std::string const &type) {
}

AMateria::AMateria(const AMateria &other) {
  *this = other;
}

AMateria::~AMateria() {
}

AMateria &AMateria::operator=(const AMateria &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

std::string const &AMateria::getType() const {
}

void AMateria::use(ICharacter &target) {
}
