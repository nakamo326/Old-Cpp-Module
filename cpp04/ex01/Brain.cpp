#include "Brain.hpp"

int Brain::_index = 0;

Brain::Brain() {
  std::stringstream ss;
  std::string ret;
  for (size_t i = 0; i < 100; i++) {
    ss << "(" << _index << ")"
       << "idea No." << i << std::endl;
    ss >> ret;
    _ideas[i] = ret;
    ss.clear();
  }
  std::cout << "[Brain" << _index << "] Default constructor called."
            << std::endl;
  _index++;
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
    std::cout << _ideas[i] << ", ";
  }
  std::cout << std::endl;
  std::cout << "[Brain] it's all ." << std::endl;
}