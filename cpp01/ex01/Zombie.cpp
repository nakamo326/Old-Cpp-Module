#include "Zombie.hpp"

Zombie::Zombie() {
  this->name = std::string("Nameless");
  std::cout << this->name << "'s corpse awakened..." << std::endl;
}

Zombie::Zombie(std::string name) {
  this->name = name;
  std::cout << this->name << "'s corpse awakened..." << std::endl;
}

Zombie::~Zombie() {
  std::cout << this->name << " doesn't seem to move anymore..." << std::endl;
}

void Zombie::set_name(std::string name) {
  std::cout << this->name;
  this->name = name;
  std::cout << " is named " << this->name << "." << std::endl;
}

void Zombie::announce(void) {
  std::cout << "<" << this->name << ">"
            << " BraiiiiiiinnnzzzZ..." << std::endl;
}
