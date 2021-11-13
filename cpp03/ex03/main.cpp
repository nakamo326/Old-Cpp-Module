#include <iostream>

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  {
    std::cout << "===ClapTrap===" << std::endl;
    ClapTrap crap("CL4P-TP");
    crap.attack("Handsam jack");
    crap.takeDamage(5);
    crap.takeDamage(7);
    crap.beRepaired(10);
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
    std::cout << "===FragTrap===" << std::endl;
    FragTrap frag("FR4G-TP");
    frag.attack("test target");
    frag.takeDamage(10);
    frag.beRepaired(5);
    frag.highFivesGuys();
  }
  {
    std::cout << "===DiamondTrap===" << std::endl;
    DiamondTrap dia("Diamond");
    dia.whoAmI();
    dia.attack("test");
  }
  return 0;
}
