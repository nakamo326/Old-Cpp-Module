#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
  m_hp = 100;
  m_energy = 50;
  m_attack_damage = 20;
  m_is_gatekeeper = false;
  std::cout << "[ScavTrap] Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
  m_name = name;
  m_hp = 100;
  m_energy = 50;
  m_attack_damage = 20;
  m_is_gatekeeper = false;
  std::cout << "[ScavTrap] Constructor with name called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
  m_name = other.m_name;
  m_hp = other.m_hp;
  m_energy = other.m_energy;
  m_attack_damage = other.m_attack_damage;
  m_is_gatekeeper = other.m_is_gatekeeper;
  std::cout << "[ScavTrap] Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "[ScavTrap] Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  m_name = other.m_name;
  m_hp = other.m_hp;
  m_energy = other.m_energy;
  m_attack_damage = other.m_attack_damage;
  m_is_gatekeeper = other.m_is_gatekeeper;
  std::cout << "[ScavTrap] Assignation operator called" << std::endl;
  return *this;
}

void ScavTrap::guardGate() {
  m_is_gatekeeper = true;
  std::cout << "[ScavTrap] " << m_name << " have enterred in Gate keeper mode."
            << std::endl;
}