#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void) {
  Zombie a("Shaun", "human");
  ZombieEvent e;
  Zombie* p;

  std::cout << "[call ZombieEvent::newZombie]" << std::endl;
  p = e.newZombie("Ed");
  std::cout << "[call ZombieEvent::randomChump]" << std::endl;
  e.randomChump();
  std::cout << "[done ZombieEvent::randomChump]" << std::endl;

  e.setZombieType("human");
  std::cout << "[done ZombieEvent::setZombieType(\"human\")]" << std::endl;

  std::cout << "[call ZombieEvent::randomChump]" << std::endl;
  e.randomChump();
  std::cout << "[done ZombieEvent::randomChump]" << std::endl;

  a.announce();
  p->announce();

  std::cout << "[call call delete Ed]" << std::endl;
  delete p;

  return 0;
}
