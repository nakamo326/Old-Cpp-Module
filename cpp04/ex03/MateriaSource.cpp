#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (size_t i = 0; i < _slotNum; i++) {
    _slot[i] = NULL;
  }
  std::cout << "[MateriaSource] MateriaSource was generated." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
  std::cout << "[MateriaSource] Copy constructor called." << std::endl;
  for (size_t i = 0; i < _slotNum; i++) {
    if (other._slot[i] != NULL)
      _slot[i] = other._slot[i]->clone();
    else
      _slot[i] = NULL;
  }
}

MateriaSource::~MateriaSource() {
  std::cout << "[MateriaSource] Destructor called." << std::endl;
  for (size_t i = 0; i < _slotNum; i++)
    if (_slot[i] != NULL)
      delete _slot[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
  std::cout << "[MateriaSource] Assignation called." << std::endl;
  if (this == &rhs)
    return *this;
  for (size_t i = 0; i < _slotNum; i++) {
    if (_slot[i] != NULL)
      delete _slot[i];
    _slot[i] = rhs._slot[i] ? rhs._slot[i]->clone() : NULL;
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
  if (m == NULL) {
    std::cout << RED "[MateriaSource] This Materia is NULL." NC << std::endl;
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
  std::cout << RED "[MateriaSource] All Materia slots are full!!" NC
            << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (size_t i = 0; i < _slotNum && _slot[i] != NULL; i++) {
    if (_slot[i]->getType() == type) {
      std::cout << "[MateriaSource] MateriaSource created a Materia of " GRN
                << type << NC " type." << std::endl;
      return _slot[i]->clone();
    }
  }
  std::cout << RED "[MateriaSource] This MateriaSource doesn't have " << type
            << " materia!!" NC << std::endl;
  return NULL;
}
