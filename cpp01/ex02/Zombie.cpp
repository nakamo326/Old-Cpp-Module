#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
  this->name = name;
  std::cout << this->name << "'s corpse awakened..." << std::endl;
}

Zombie::~Zombie() {
  std::cout << this->name << " doesn't seem to move anymore..." << std::endl;
}

void Zombie::announce(void) {
  std::cout << "<" << this->name << ">"
            << " BraiiiiiiinnnzzzZ..." << std::endl;
}
