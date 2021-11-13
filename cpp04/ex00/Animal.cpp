#include "Animal.hpp"

Animal::Animal() {
}

Animal::Animal(const Animal &other) {
}

Animal::~Animal() {
}

Animal &Animal::operator=(const Animal &rhs) {
}

std::string &Animal::getType() {
  return _type;
}