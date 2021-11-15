#include "Character.hpp"

Character::Character() {}

Character::Character(const Character &other) { *this = other; }

Character::~Character() {}

Character &Character::operator=(const Character &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

std::string const &Character::getName() const {}

void Character::equip(AMateria *m) {}

void Character::unequip(int idx) {}

void Character::use(int idx, ICharacter &target) {}
