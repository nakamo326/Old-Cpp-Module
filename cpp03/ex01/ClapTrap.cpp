#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
  m_name = std::string("");
  m_hp = 10;
  m_energy = 10;
  m_attack_damage = 0;
  std::cout << "[ClapTrap] Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
  m_name = name;
  m_hp = 10;
  m_energy = 10;
  m_attack_damage = 0;
  std::cout << "[ClapTrap] Constructor with name called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  m_name = other.m_name;
  m_hp = other.m_hp;
  m_energy = other.m_energy;
  m_attack_damage = other.m_attack_damage;
  std::cout << "[ClapTrap] Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "[ClapTrap] Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  m_name = other.m_name;
  m_hp = other.m_hp;
  m_energy = other.m_energy;
  m_attack_damage = other.m_attack_damage;
  std::cout << "[ClapTrap] Assignation operator called" << std::endl;
  return *this;
}

void ClapTrap::attack(std::string const &target) {
  std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing "
            << m_attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (m_hp <= amount)
    m_hp = 0;
  else
    m_hp -= amount;
  std::cout << "ClapTrap " << m_name << " takes " << amount
            << " points of damage!" << std::endl;
  std::cout << m_name << "'s hitpoint is " << m_hp << " now!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  m_hp += amount;
  std::cout << "ClapTrap " << m_name << " be repaired!" << std::endl;
  std::cout << m_name << "'s hitpoint is " << m_hp << " now!" << std::endl;
}