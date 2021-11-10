#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanB {
  private:
  std::string _name;
  Weapon *_weapon;

  public:
  HumanB(std::string mane);
  HumanB(std::string name, Weapon &weapon);
  void setWeapon(Weapon &weapon);
  void attack();
};

#endif