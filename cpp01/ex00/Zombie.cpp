#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
  std::cout << _name << "'s corpse awakened..." << std::endl;
}

Zombie::~Zombie() {
  std::cout << _name << " doesn't seem to move anymore..." << std::endl;
}

void Zombie::announce(void) {
  std::cout << "<" << _name << ">"
            << " BraiiiiiiinnnzzzZ..." << std::endl;
}
