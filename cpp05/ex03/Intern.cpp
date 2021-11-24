#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs) {
  (void)rhs;
  return *this;
}

Form *Intern::makeSForm(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

Form *Intern::makeRForm(const std::string &target) {
  return new RobotomyRequestForm(target);
}

Form *Intern::makePForm(const std::string &target) {
  return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(const std::string &name, const std::string &target) {
  Form *(Intern::*fp[4])(const std::string &target) = {
      NULL, &Intern::makeSForm, &Intern::makeRForm, &Intern::makePForm};
  int i = (name == "shrubbery creation") * 1 +
          (name == "robotomy request") * 2 +
          (name == "presidential pardon") * 3;

  if (i == 0) {
    std::cout << "This intern doesn't know form of " << name << std::endl;
    return NULL;
  }
  Form *f = (this->*fp[i])(target);
  std::cout << "Intern creates " << name << std::endl;
  return f;
}