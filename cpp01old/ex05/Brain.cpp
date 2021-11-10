#include "Brain.hpp"

Brain::Brain() {
}

Brain::~Brain() {
}

std::string Brain::identify() {
  std::ostringstream address;
  address << (void const *)this;
  return address.str();
}
