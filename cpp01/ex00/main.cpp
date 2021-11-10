#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
  Zombie a("Shaun");
  Zombie* p;

  p = newZombie("Ed");
  randomChump("Liz");

  a.announce();
  p->announce();

  delete p;

  return 0;
}
