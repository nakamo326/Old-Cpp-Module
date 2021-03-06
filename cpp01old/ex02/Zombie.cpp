#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) {
  m_name = name;
  m_type = type;
  std::cout << m_name << "'s corpse awakened..." << std::endl;
}

Zombie::~Zombie() {
  std::cout << m_name << " doesn't seem to move anymore..." << std::endl;
}

void Zombie::announce(void) {
  std::cout << "<" << m_name << " (" << m_type << ")>"
            << " Braiiiiiiinnnssss..." << std::endl;
}
