#include "ZombieEvent.hpp"

#include <cstdlib>
#include <ctime>

ZombieEvent::ZombieEvent() {
  m_type = std::string("none");
  std::srand(std::time(NULL));
}

ZombieEvent::~ZombieEvent() {
}

void ZombieEvent::setZombieType(std::string type) {
  m_type = type;
};

Zombie* ZombieEvent::newZombie(std::string name) {
  Zombie* ptr = NULL;
  ptr = new Zombie(name, m_type);
  return ptr;
};

void ZombieEvent::randomChump() {
  const std::string name_list[6] = {
      "Adam", "Bob", "Charles", "Deny", "Elena", "Fabian"};

  int random_val = std::rand() % 6;
  Zombie chump(name_list[random_val], m_type);
  chump.announce();
  return;
}