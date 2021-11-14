#include "Cat.hpp"

Cat::Cat() {
  _type = std::string("Cat");
  _brain = new Brain();
}

Cat::Cat(const Cat &other) {
  *this = other;
}

Cat::~Cat() {
  delete _brain;
}

Cat &Cat::operator=(const Cat &rhs) {
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  return *this;
}

void Cat::makeSound() const {
  std::cout << "[" << _type << "]  "
            << "Meow. Meoooooooooow." << std::endl;
}