#include "Human.hpp"

Human::Human() {
}

Human::~Human() {
}

Brain& Human::getBrain() {
  return m_brain;
};

std::string Human::identify() {
  return m_brain.identify();
};
