#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
  protected:
  std::string _name;
  unsigned int _hp;
  unsigned int _energy;
  unsigned int _attackDamage;

  public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &other);
  virtual ~ClapTrap();
  ClapTrap &operator=(const ClapTrap &rhs);
  void attack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
