#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "Color.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
  MateriaSource();
  MateriaSource(const MateriaSource &other);
  ~MateriaSource();
  MateriaSource &operator=(const MateriaSource &rhs);
  void learnMateria(AMateria *m);
  AMateria *createMateria(std::string const &type);

private:
  static const size_t _slotNum = 4;
  AMateria *_slot[_slotNum];
};

#endif  // MATERIASOURCE_HPP