#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hp(10), _energy(10), _attackDamage(0) {
  _name = std::string("");
  std::cout << "[ClapTrap] Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hp(10), _energy(10), _attackDamage(0) {
  std::cout << "[ClapTrap] Constructor with name called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "[ClapTrap] Copy constructor called" << std::endl;
  *this = other;
}

ClapTrap::~ClapTrap() {
  std::cout << "[ClapTrap] Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
  std::cout << "[ClapTrap] Assignation operator called" << std::endl;
  if (this == &rhs)
    return *this;
  _name = rhs._name;
  _hp = rhs._hp;
  _energy = rhs._energy;
  _attackDamage = rhs._attackDamage;
  return *this;
}

void ClapTrap::attack(std::string const &target) {
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hp <= amount)
    _hp = 0;
  else
    _hp -= amount;
  std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage!" << std::endl;
  std::cout << _name << "'s hitpoint is " << _hp << " now!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  _hp += amount;
  std::cout << "ClapTrap " << _name << " be repaired!" << std::endl;
  std::cout << _name << "'s hitpoint is " << _hp << " now!" << std::endl;
}