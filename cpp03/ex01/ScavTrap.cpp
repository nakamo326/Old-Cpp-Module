#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
  _hp = 100;
  _energy = 50;
  _attackDamage = 20;
  _isGatekeeper = false;
  std::cout << "[ScavTrap] Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
  _name = name;
  _hp = 100;
  _energy = 50;
  _attackDamage = 20;
  _isGatekeeper = false;
  std::cout << "[ScavTrap] Constructor with name called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
  std::cout << "[ScavTrap] Copy constructor called" << std::endl;
  *this = other;
}

ScavTrap::~ScavTrap() {
  std::cout << "[ScavTrap] Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
  std::cout << "[ScavTrap] Assignation operator called" << std::endl;
  if (this == &rhs)
    return *this;
  _name = rhs._name;
  _hp = rhs._hp;
  _energy = rhs._energy;
  _attackDamage = rhs._attackDamage;
  _isGatekeeper = rhs._isGatekeeper;
  return *this;
}

void ScavTrap::guardGate() {
  _isGatekeeper = true;
  std::cout << "[ScavTrap] " << _name << " have enterred in Gate keeper mode."
            << std::endl;
}