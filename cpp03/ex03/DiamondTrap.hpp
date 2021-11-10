#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
  private:
  std::string name;
  unsigned int m_hp;
  unsigned int m_energy;
  unsigned int m_attack_damage;

  public:
  DiamondTrap(/* args */);
  ~DiamondTrap();
};

DiamondTrap::DiamondTrap(/* args */) {
}

DiamondTrap::~DiamondTrap() {
}

#endif