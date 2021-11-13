#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
  private:
  std::string _name;
  unsigned int _hp;
  unsigned int _energy;
  unsigned int _attackDamage;

  public:
  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap &other);
  ~DiamondTrap();
  DiamondTrap &operator=(const DiamondTrap &rhs);
  void attack(std::string const &target);
  void whoAmI();
};

#endif
