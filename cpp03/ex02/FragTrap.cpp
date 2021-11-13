#include "FragTrap.hpp"

FragTrap::FragTrap() {
  _hp = 100;
  _energy = 100;
  _attackDamage = 30;
  std::cout << "[FragTrap] Default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) {
  _name = name;
  _hp = 100;
  _energy = 100;
  _attackDamage = 30;
  std::cout << "[FragTrap] Constructor with name called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
  _name = other._name;
  _hp = other._hp;
  _energy = other._energy;
  _attackDamage = other._attackDamage;
  std::cout << "[FragTrap] Copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "[FragTrap] Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  _name = other._name;
  _hp = other._hp;
  _energy = other._energy;
  _attackDamage = other._attackDamage;
  std::cout << "[FragTrap] Assignation operator called" << std::endl;
  return *this;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "[FragTrap] You've earned it." << std::endl;
}
