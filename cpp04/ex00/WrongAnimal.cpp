#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("None") {
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  *this = other;
}

WrongAnimal::~WrongAnimal() {
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "[" << _type << "] "
            << "I'M WRONG ANIMAL CLASS" << std::endl;
};

const std::string &WrongAnimal::getType() const {
  return _type;
}