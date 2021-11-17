#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nameless"), _grade(150) {}

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
  const_cast<std::string &>(_name) = rhs._name;
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

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Bureaucrat's grade will be too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Bureaucrat's grade will be too low!";
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &b) {
  stream << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return stream;
}
