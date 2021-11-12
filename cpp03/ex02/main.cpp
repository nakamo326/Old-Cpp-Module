#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ClapTrap crap("CL4P-TP");
  crap.attack("Handsam jack");
  crap.takeDamage(5);
  crap.takeDamage(7);
  crap.beRepaired(10);

  ScavTrap scav("SC4V-TP");
  scav.attack("test target");
  scav.takeDamage(10);
  scav.beRepaired(5);
  scav.guardGate();

  FragTrap frag("FR4G-TP");
  frag.attack("test target");
  frag.takeDamage(10);
  frag.beRepaired(5);
  frag.highFivesGuys();
  return 0;
}
