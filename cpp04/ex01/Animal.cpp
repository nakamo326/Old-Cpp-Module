#include "Animal.hpp"

Animal::Animal() : _type("None") {
}

Animal::Animal(const Animal &other) {
  *this = other;
}

Animal::~Animal() {
}

Animal &Animal::operator=(const Animal &rhs) {
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  return *this;
}

void Animal::makeSound() const {
  std::cout << "[" << _type << "] "
            << "I'M ANIMAL CLASS" << std::endl;
};

const std::string &Animal::getType() const {
  return _type;
}