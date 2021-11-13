#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  {
    std::cout << "===ClapTrap===" << std::endl;
    ClapTrap clap("CL4P-TP");
    clap.attack("Handsam jack");
    clap.takeDamage(5);
    clap.takeDamage(7);
    clap.beRepaired(10);
  }
  {
    std::cout << "===ScavTrap===" << std::endl;
    ScavTrap scav("SC4V-TP");
    scav.attack("test target");
    scav.takeDamage(10);
    scav.beRepaired(5);
    scav.guardGate();
  }
  {
    std::cout << "===ScavTrap as ClapTrap===" << std::endl;
    ClapTrap* v = new ScavTrap("test");
    v->attack("Handsam jack");
    v->takeDamage(5);
    v->takeDamage(7);
    v->beRepaired(10);
    delete v;
  }
  return 0;
}
