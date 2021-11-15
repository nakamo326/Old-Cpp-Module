#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

int main() {
  Animal *arr[4];

  std::cout << GRN "make array of Animal." NC << std::endl;
  arr[0] = new Dog();
  arr[1] = new Dog();
  arr[2] = new Cat();
  arr[3] = new Cat();

  std::cout << GRN "show ideas from array." NC << std::endl;
  (dynamic_cast<Dog *>(arr[0]))->showIdeas();
  (dynamic_cast<Cat *>(arr[2]))->showIdeas();

  std::cout << GRN "copy deeply." NC << std::endl;
  Dog CopyDog(*dynamic_cast<Dog *>(arr[0]));
  Cat CopyCat(*dynamic_cast<Cat *>(arr[2]));

  std::cout << GRN "delete array." NC << std::endl;
  delete arr[0];
  delete arr[1];
  delete arr[2];
  delete arr[3];

  std::cout << GRN "show ideas from copy." NC << std::endl;
  CopyDog.showIdeas();
  CopyCat.showIdeas();

  std::cout << GRN "return." NC << std::endl;
  return 0;
}