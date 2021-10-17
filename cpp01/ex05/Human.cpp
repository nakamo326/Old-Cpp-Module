#include "Human.hpp"

Human::Human() {
}

Human::~Human() {
}

Brain& Human::getBrain() {
  std::cout << m_brain.identify() << std::endl;
  return m_brain;
};

std::string Human::identify() {
  return m_brain.identify();
};
