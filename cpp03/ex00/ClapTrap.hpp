#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
  private:
  std::string m_name;
  unsigned int m_hp;
  unsigned int m_energy;
  unsigned int m_attack_damage;

  public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &other);
  ~ClapTrap();
  ClapTrap &operator=(const ClapTrap &other);
  void attack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif