#include "WrongCat.hpp"

WrongCat::WrongCat() {
  _type = std::string("WrongCat");
}

WrongCat::WrongCat(const WrongCat &other) {
  *this = other;
}

WrongCat::~WrongCat() {
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
  if (this == &rhs)
    return *this;
  _type = rhs._type;
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "[" << _type << "]  "
            << "Meow. Meoooooooooow." << std::endl;
}