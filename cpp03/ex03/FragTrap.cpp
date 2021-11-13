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
  std::cout << "[FragTrap] Copy constructor called" << std::endl;
  *this = other;
}

FragTrap::~FragTrap() {
  std::cout << "[FragTrap] Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
  std::cout << "[FragTrap] Assignation operator called" << std::endl;
  if (this == &rhs)
    return *this;
  _name = rhs._name;
  _hp = rhs._hp;
  _energy = rhs._energy;
  _attackDamage = rhs._attackDamage;
  return *this;
}

void FragTrap::attack(std::string const &target) {
  std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
  if (_hp <= amount)
    _hp = 0;
  else
    _hp -= amount;
  std::cout << "FragTrap " << _name << " takes " << amount
            << " points of damage!" << std::endl;
  std::cout << _name << "'s hitpoint is " << _hp << " now!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
  _hp += amount;
  std::cout << "FragTrap " << _name << " be repaired!" << std::endl;
  std::cout << _name << "'s hitpoint is " << _hp << " now!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "[FragTrap] Heyyah!" << std::endl;
}
