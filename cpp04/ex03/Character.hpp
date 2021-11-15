#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character {
public:
  Character();
  Character(const Character &other);
  ~Character();
  Character &operator=(const Character &rhs);

private:
};

Character::Character() {}

Character::Character(const Character &other) { *this = other; }

Character::~Character() {}

Character &Character::operator=(const Character &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

#endif  // CHARACTER_HPP