#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
  Zombie* ptr = NULL;
  ptr = new Zombie(name);
  return ptr;
}
