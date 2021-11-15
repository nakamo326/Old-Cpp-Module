#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  Animal *arr[4];

  arr[0] = new Dog();
  arr[1] = new Dog();
  arr[2] = new Cat();
  arr[3] = new Cat();

  (dynamic_cast<Dog *>(arr[0]))->showIdeas();
  (dynamic_cast<Cat *>(arr[2]))->showIdeas();

  return 0;
}