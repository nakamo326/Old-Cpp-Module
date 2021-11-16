#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
    : _name(name), _grade(grade) {
  if (_grade < 1)
    throw GradeTooHighException();
  if (_grade > 150)
    throw GradeTooLowException();
  std::cout << "[Bureaucrat] Bureaucrat named " << _name << " grade " << _grade
            << " was generated." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) { *this = other; }

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (this == &rhs)
    return *this;
  _name = rhs._name;
  _grade = rhs._grade;
  return *this;
}

Bureaucrat Bureaucrat::operator++(int) {
  if (_grade == 1)
    throw GradeTooHighException();
  Bureaucrat tmp = *this;
  _grade--;
  return tmp;
}

Bureaucrat Bureaucrat::operator--(int) {
  if (_grade == 150)
    throw GradeTooLowException();
  Bureaucrat tmp = *this;
  _grade++;
  return tmp;
}

const std::string &Bureaucrat::getName() const { return _name; }

unsigned int Bureaucrat::getGrade() const { return _grade; }

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &b) {
  stream << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return stream;
}
