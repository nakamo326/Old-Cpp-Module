#ifndef ANIMAL_CPP
#define ANIMAL_CPP

#include <iostream>

class WrongAnimal {
  protected:
  std::string _type;

  public:
  WrongAnimal();
  virtual ~WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal &operator=(const WrongAnimal &rhs);
  virtual void makeSound() const;
  const std::string &getType() const;
};

#endif  // ANIMAL_CPP