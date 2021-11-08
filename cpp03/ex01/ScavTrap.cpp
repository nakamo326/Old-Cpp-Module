#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
  m_name = std::string("namelss");
  std::cout << "SC4V-TP " << m_name << ": Hey everybody! Check out my package!"
            << std::endl;
  m_level = 1;
  m_hp = 100;
  m_max_hp = 100;
  m_energy = 50;
  m_max_energy = 50;
  m_melee_attack = 20;
  m_ranged_attack = 15;
  m_armor_reduction = 3;
}

ScavTrap::ScavTrap(std::string const &name) : m_name(name) {
  std::cout << "SC4V-TP " << m_name << ": Hey everybody! Check out my package!"
            << std::endl;
  m_level = 1;
  m_hp = 100;
  m_max_hp = 100;
  m_energy = 50;
  m_max_energy = 50;
  m_melee_attack = 20;
  m_ranged_attack = 15;
  m_armor_reduction = 3;
}