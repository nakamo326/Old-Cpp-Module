#include "Brain.hpp"

static int _index = 0;

Brain::Brain() {
  std::stringstream ss;
  for (size_t i = 0; i < 100; i++) {
    ss << "idea No." << i << std::endl;
    _ideas[i] = ss.str();
    ss.clear();
  }

  std::cout << "[Brain] Default constructor called." << std::endl;
}

Brain::Brain(const Brain &other) {
  *this = other;
  std::cout << "[Brain] Copy constructor called." << std::endl;
}

Brain::~Brain() {
  std::cout << "[Brain] Destructor called." << std::endl;
}

Brain &Brain::operator=(const Brain &rhs) {
  if (this != &rhs)
    return *this;
  for (size_t i = 0; i < 100; i++) {
    _ideas[i] = rhs._ideas[i];
  }
  std::cout << "[Brain] Assignation operator called." << std::endl;
  return *this;
}

void Brain::showIdeas() const {
  for (size_t i = 0; i < 100; i++) {
    std::cout << _ideas[i] << std::endl;
  }
  std::cout << "[Brain] it's all ." << std::endl;
}