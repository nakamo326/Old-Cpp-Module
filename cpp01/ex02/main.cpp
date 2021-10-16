#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void) {
  Zombie a("Shaun", "human");
  ZombieEvent e;
  Zombie* p;

  p = e.newZombie("Ed");
  e.randomChump();
  e.setZombieType("human");
  e.randomChump();

  a.announce();
  p->announce();

  delete p;

  return 0;
}
