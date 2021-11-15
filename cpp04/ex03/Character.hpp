#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  Character();
  Character(const Character &other);
  ~Character();
  Character &operator=(const Character &rhs);
  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

private:
  std::string _name;
};

#endif  // CHARACTER_HPP