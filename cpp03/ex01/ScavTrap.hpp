#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class ScavTrap {
  private:
  std::string m_name;
  int m_level;
  int m_hp;
  int m_max_hp;
  int m_energy;
  int m_max_energy;
  int m_melee_attack;
  int m_ranged_attack;
  int m_armor_reduction;

  public:
  ScavTrap();
  ~ScavTrap();
  ScavTrap(std::string const &name);
  ScavTrap(const ScavTrap &rhs);
  ScavTrap &operator=(const ScavTrap &rhs);
  void rangedAttack(std::string const &target);
  void meleeAttack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void challengeNewcomer();
};

#endif  // SCAVTRAP_HPP