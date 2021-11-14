#include "Brain.hpp"

Brain::Brain() {
}

Brain::Brain(const Brain &other) {
  *this = other;
}

Brain::~Brain() {
}

Brain &Brain::operator=(const Brain &rhs) {
  if (this == &rhs)
    return *this;
  for (size_t i = 0; i < 100; i++) {
    _ideas[i] = rhs._ideas[i];
  }
  return *this;
}