#include "AMateria.hpp"

AMateria::AMateria() : _type("none") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other) { *this = other; }

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &rhs) {
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  return *this;
}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) {
  (void)target;
  std::cout << "I guess this func should be virtual." << std::endl;
}
