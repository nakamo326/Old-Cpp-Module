#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
  MateriaSource();
  MateriaSource(const MateriaSource &other);
  ~MateriaSource();
  MateriaSource &operator=(const MateriaSource &rhs);

private:
};

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource &other) { *this = other; }

MateriaSource::~MateriaSource() {}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

#endif  // MATERIASOURCE_HPP