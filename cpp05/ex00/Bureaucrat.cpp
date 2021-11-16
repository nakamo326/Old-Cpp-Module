#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
    : _name(name), _grade(grade) {
  // throw exception, if grade not in 1~150
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) { *this = other; }

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

Bureaucrat &Bureaucrat::operator++(int) {
  // need to throw exception if grade under 1
  Bureaucrat tmp = *this;
  _grade--;
  return tmp;
}

Bureaucrat &Bureaucrat::operator--(int) {
  // need to throw exception if grade over 150
  Bureaucrat tmp = *this;
  _grade++;
  return tmp;
}

const std::string &Bureaucrat::getName() const { return _name; }

const unsigned int Bureaucrat::getGrade() const { return _grade; }
