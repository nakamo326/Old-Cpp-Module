#ifndef WRONGCAT_CPP
#define WRONGCAT_CPP

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
  private:
  public:
  WrongCat();
  WrongCat(const WrongCat &other);
  ~WrongCat();
  WrongCat &operator=(const WrongCat &rhs);
  void makeSound() const;
};

#endif  // WRONGCAT_CPP