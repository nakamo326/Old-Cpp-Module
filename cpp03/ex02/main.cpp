#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

// need to "virtual" in claptrap constructor?

int main(void) {
  FragTrap test("testname");
  test.attack("test target");
  test.takeDamage(10);
  test.beRepaired(5);
  test.highFivesGuys();
  return 0;
}
