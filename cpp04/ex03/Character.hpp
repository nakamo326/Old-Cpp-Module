#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character {
public:
  Character();
  Character(const Character &other);
  ~Character();
  Character &operator=(const Character &rhs);
  std::string const &getName() const;

private:
  std::string _name;
};

Character::Character() {}

Character::Character(const Character &other) { *this = other; }

Character::~Character() {}

Character &Character::operator=(const Character &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

std::string const &Character::getName() const {}

#endif  // CHARACTER_HPP