#include "Zombie.hpp"

Zombie::Zombie() {
  m_name = std::string("Nameless");
  m_type = std::string("none");
  std::cout << m_name << " (" << m_type << ")"
            << "'s corpse awakened..." << std::endl;
}

Zombie::Zombie(std::string name, std::string type) {
  m_name = name;
  m_type = type;
  std::cout << m_name << " (" << m_type << ")"
            << "'s corpse awakened..." << std::endl;
}

Zombie::~Zombie() {
  std::cout << m_name << " (" << m_type << ")"
            << " doesn't seem to move anymore..." << std::endl;
}

void Zombie::announce(void) {
  std::cout << "<" << m_name << " (" << m_type << ")>"
            << " Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::set_characteristics(std::string name, std::string type) {
  std::cout << m_name << " (" << m_type << ")";
  m_name = name;
  m_type = type;
  std::cout << " is changed name and type to " << m_name << " and " << m_type
            << std::endl;
}
