#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nameless"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
    : _name(name), _grade(grade) {
  if (_grade < _highestGrade)
    throw GradeTooHighException();
  if (_grade > _lowestGrade)
    throw GradeTooLowException();
  // std::cout << "[Bureaucrat] Bureaucrat " << _name << " grade " << _grade
  //          << " was generated." << std::endl;
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

// inc and dec
void Bureaucrat::incrementGrade() {
  if (_grade == _highestGrade)
    throw GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if (_grade == _lowestGrade)
    throw GradeTooLowException();
  _grade++;
}

// getter
const std::string &Bureaucrat::getName() const { return _name; }

unsigned int Bureaucrat::getGrade() const { return _grade; }

// Exception class
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &msg)
    : range_error(msg){};

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg)
    : range_error(msg){};

// stream overload
std::ostream &operator<<(std::ostream &stream, const Bureaucrat &b) {
  stream << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return stream;
}
