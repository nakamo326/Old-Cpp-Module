#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  Animal *arr = new Animal[4];

  arr[0] = Dog();
  arr[1] = Dog();
  arr[2] = Cat();
  arr[3] = Cat();

  return 0;
}