#include "FragTrap.hpp"

FragTrap::FragTrap() {
  m_hp = 100;
  m_energy = 100;
  m_attack_damage = 30;
  std::cout << "[FragTrap] Default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) {
  m_name = name;
  m_hp = 100;
  m_energy = 100;
  m_attack_damage = 30;
  std::cout << "[FragTrap] Constructor with name called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
  m_name = other.m_name;
  m_hp = other.m_hp;
  m_energy = other.m_energy;
  m_attack_damage = other.m_attack_damage;
  std::cout << "[FragTrap] Copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "[FragTrap] Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  m_name = other.m_name;
  m_hp = other.m_hp;
  m_energy = other.m_energy;
  m_attack_damage = other.m_attack_damage;
  std::cout << "[FragTrap] Assignation operator called" << std::endl;
  return *this;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "[FragTrap] You've earned it." << std::endl;
}
