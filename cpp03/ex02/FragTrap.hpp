#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
  public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap &other);
  ~FragTrap();
  FragTrap &operator=(const FragTrap &rhs);
  void attack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void highFivesGuys(void);
};

#endif
