#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Color.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice &other);
  ~Ice();
  Ice &operator=(const Ice &rhs);
  AMateria *clone() const;
  void use(ICharacter &target);

private:
};

#endif  // ICE_HPP