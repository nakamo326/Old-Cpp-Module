#ifndef CAT_CPP
#define CAT_CPP

#include <iostream>

class Cat {
  private:
  public:
  Cat();
  Cat(const Cat &other);
  ~Cat();
  Cat &operator=(const Cat &rhs);
  void makeSound();
};

#endif  // CAT_CPP