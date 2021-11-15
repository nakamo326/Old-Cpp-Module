#include "Brain.hpp"

int Brain::_index = 0;

Brain::Brain() {
  for (size_t i = 0; i < 100; i++) {
    std::stringstream ss;
    ss << "(" << _index << ")"
       << "idea No." << std::setfill('0') << std::right << std::setw(2) << i;
    _ideas[i] = ss.str();
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
  std::cout << "[Brain] there are my ideas." << std::endl;
  for (size_t i = 0; i < 10; i++) {
    for (size_t j = i * 10; j < (i + 1) * 10; j++) {
      std::cout << _ideas[j] << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << "[Brain] it's all ." << std::endl;
}