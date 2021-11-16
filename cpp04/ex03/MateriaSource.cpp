#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (size_t i = 0; i < _slotNum; i++) {
    _slot[i] = NULL;
  }
  std::cout << "[MateriaSource] MateriaSource was generated." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
  for (size_t i = 0; i < _slotNum; i++) {
    if (other._slot[i] != NULL) {
      _slot[i] = other._slot[i]->clone();
    }
  }
  std::cout << "[MateriaSource] A copy fo MateriaSource was generated."
            << std::endl;
}

MateriaSource::~MateriaSource() {}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
  if (this == &rhs)
    return *this;
  for (size_t i = 0; i < _slotNum; i++) {
    if (_slot[i] != NULL)
      delete _slot[i];
    _slot[i] = rhs._slot[i] ? rhs._slot[i]->clone() : NULL;
  }
  std::cout << "[MateriaSource] Assignation called." << std::endl;
  return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
  if (m == NULL) {
    std::cout << RED "[MateriaSource] This materia is NULL" NC << std::endl;
    return;
  }
  for (size_t i = 0; i < _slotNum; i++) {
    if (_slot[i] == NULL) {
      _slot[i] = m->clone();
      std::cout << "[MateriaSource] MateriaSource learned " GRN << m->getType()
                << NC " materia to slot " << i << "." << std::endl;
      return;
    }
  }
  std::cout << RED "[MateriaSource] All materia slots are full!!" NC
            << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {}
