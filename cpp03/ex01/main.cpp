#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// need to "virtual" in claptrap constructor?

int main(void) {
  ClapTrap crap("CL4P-TP");
  crap.attack("Handsam jack");
  crap.takeDamage(5);
  crap.takeDamage(7);
  crap.beRepaired(10);

  ScavTrap test("SC4V-TP");
  test.attack("test target");
  test.takeDamage(10);
  test.beRepaired(5);
  test.guardGate();
  return 0;
}
