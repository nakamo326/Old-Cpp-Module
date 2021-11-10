#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap crap("CL4P-TP");
  crap.attack("Handsam jack");
  crap.takeDamage(5);
  crap.takeDamage(7);
  crap.beRepaired(10);
  return 0;
}
