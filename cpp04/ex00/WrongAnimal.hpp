#ifndef WRONGANIMAL_CPP
#define WRONGANIMAL_CPP

#include <iostream>

class WrongAnimal {
protected:
  std::string _type;

public:
  WrongAnimal();
  virtual ~WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal &operator=(const WrongAnimal &rhs);
  void makeSound() const;
  const std::string &getType() const;
};

#endif  // WRONGANIMAL_CPP