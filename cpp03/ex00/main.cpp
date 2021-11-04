#include "FragTrap.hpp"

int main() {
  FragTrap ft("clap");

  ft.meleeAttack("Skag");
  ft.takeDamage(20);
  ft.beRepaired(30);
  ft.rangedAttack("Skag");
  ft.vaulthunter_dot_exe("Handsome Jack");
  return 0;
}
