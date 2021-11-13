#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"),
      _name(name),
      _hp(FragTrap::_hp),
      _energy(ScavTrap::_energy),
      _attackDamage(FragTrap::_attackDamage) {
}

DiamondTrap::~DiamondTrap() {
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap's name is " << _name << "." << std::endl;
  std::cout << "ClapTrap's name is " << ClapTrap::_name << "." << std::endl;
}

void DiamondTrap::attack(std::string const &target) {
  ScavTrap::attack(target);
}