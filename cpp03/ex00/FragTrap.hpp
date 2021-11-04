#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

class FragTrap {
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
  FragTrap(std::string const &name);
  ~FragTrap();
  FragTrap(const FragTrap &rhs);
  FragTrap &operator=(const FragTrap &rhs);
  void rangedAttack(std::string const &target);
  void meleeAttack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void vaulthunter_dot_exe(std::string const &target);
};

#endif  // FRAGTRAP_HPP