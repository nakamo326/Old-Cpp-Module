#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
}

void HumanB::setWeapon(Weapon &weapon) {
  _weapon = &weapon;
}

void HumanB::attack() {
  if (_weapon != NULL)
    std::cout << _name << " attacks with his " << _weapon->getType()
              << std::endl;
  else
    std::cout << _name << " attacks with martial arts" << std::endl;
}
