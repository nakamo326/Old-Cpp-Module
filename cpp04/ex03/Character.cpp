#include "Character.hpp"

Character::Character() : _name("nameless") {
  for (size_t i = 0; i < _slotNum; i++) {
    _slot[i] = NULL;
  }
  std::cout << "[Character] Character named " BLU << _name
            << NC " was generated." << std::endl;
}

Character::Character(const std::string &name) : _name(name) {
  for (size_t i = 0; i < _slotNum; i++) {
    _slot[i] = NULL;
  }
  std::cout << "[Character] Character named " BLU << _name
            << NC " was generated." << std::endl;
}

Character::Character(const Character &other) {
  std::cout << "[Character] Copy constructor called." << std::endl;
  *this = other;
}

Character::~Character() {}

Character &Character::operator=(const Character &rhs) {
  std::cout << "[Character] Assignation to " BLU << _name << NC " from " BLU
            << rhs._name << NC "." << std::endl;
  if (this == &rhs)
    return *this;
  _name = rhs._name;
  for (size_t i = 0; i < _slotNum; i++) {
    _slot[i] = rhs._slot[i];
  }
  return *this;
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
  if (m == NULL) {
    std::cout << BLU "[" << _name << "] " NC
              << "this is NULL materia...I can't equip it." << std::endl;
    return;
  }
  for (size_t i = 0; i < _slotNum; i++) {
    if (_slot[i] == NULL) {
      _slot[i] = m;
      std::cout << "[Character] " BLU << _name << NC " equipped " GRN
                << m->getType() << NC " materia." << std::endl;
      return;
    }
  }
  std::cout << RED "[Character] " << _name << "'s materia slots are full!!" NC
            << std::endl;
}

void Character::unequip(int idx) {
  if (_slot[idx] == NULL) {
    std::cout << "[Character] " BLU << _name << NC "'s materia slot " << idx
              << " is empty!" << std::endl;
    return;
  }
  std::string type = _slot[idx]->getType();
  _slot[idx] = NULL;
  std::cout << "[Character] " BLU << _name << NC " unequipped slot " << idx
            << " " GRN << type << NC " materia." << std::endl;
}

void Character::use(int idx, ICharacter &target) {
  (void)idx;
  (void)target;
}
