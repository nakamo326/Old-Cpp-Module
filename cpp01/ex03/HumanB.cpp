#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL) {
}

HumanB::HumanB(std::string name, Weapon &weapon)
    : m_name(name), m_weapon(&weapon) {
}

void HumanB::setWeapon(Weapon &weapon) {
  m_weapon = &weapon;
}

void HumanB::attack() {
  if (m_weapon != NULL)
    std::cout << m_name << " attacks with his " << m_weapon->getType()
              << std::endl;
  else
    std::cout << m_name << " attacks with martial arts" << std::endl;
}
