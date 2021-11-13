#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : _hp(FragTrap::_hp),
      _energy(ScavTrap::_energy),
      _attackDamage(FragTrap::_attackDamage) {
  _name = std::string("");
  std::cout << "[DiamondTrap] Default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"),
      _name(name),
      _hp(FragTrap::_hp),
      _energy(ScavTrap::_energy),
      _attackDamage(FragTrap::_attackDamage) {
  std::cout << "[DiamondTrap] Constructor with name called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
  std::cout << "[DiamondTrap] Copy constructor called" << std::endl;
  *this = other;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "[DiamondTrap] Destructor called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
  std::cout << "[DiamondTrap] Assignation operator called" << std::endl;
  if (this == &rhs)
    return *this;
  _name = rhs._name;
  _hp = rhs._hp;
  _energy = rhs._energy;
  _attackDamage = rhs._attackDamage;
  return *this;
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap's name is " << _name << "." << std::endl;
  std::cout << "ClapTrap's name is " << ClapTrap::_name << "." << std::endl;
}

void DiamondTrap::attack(std::string const &target) {
  ScavTrap::attack(target);
}
