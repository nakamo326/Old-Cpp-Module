#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nameless"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade)
    : _name(name), _grade(grade) {
  if (_grade < 1)
    throw GradeTooHighException();
  if (_grade > 150)
    throw GradeTooLowException();
  std::cout << "[Bureaucrat] Bureaucrat " << _name << " grade " << _grade
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

void Bureaucrat::incrementGrade() {
  if (_grade == 1)
    throw GradeTooHighException();
  Bureaucrat tmp = *this;
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if (_grade == 150)
    throw GradeTooLowException();
  Bureaucrat tmp = *this;
  _grade++;
}

bool Bureaucrat::signForm(Form &f) {
  if (f.getIsSigned()) {
    std::cout << _name << " cannot sign " << f.getName()
              << " because this form is signed already." << std::endl;
    return false;
  }
  try {
    f.beSigned(*this);
  } catch (const std::exception &e) {
    std::cout << _name << " cannot sign " << f.getName() << " because "
              << e.what() << "." << std::endl;
    return false;
  }
  std::cout << _name << " signs " << f.getName() << "." << std::endl;
  return true;
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
