#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "Color.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  Character();
  Character(const std::string &name);
  Character(const Character &other);
  ~Character();
  Character &operator=(const Character &rhs);
  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

private:
  std::string _name;
  static const size_t _slotNum = 4;
  AMateria *_slot[_slotNum];
};

#endif  // CHARACTER_HPP