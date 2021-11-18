#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs) {
  (void)rhs;
  return *this;
}

Form *Intern::makeForm(const std::string &name, const std::string &target) {
  Form *f;
  int i = 0 + (name == "shrubbery creation") * 1 +
          (name == "robotomy request") * 2 +
          (name == "presidential pardon") * 3;

  switch (i) {
    case 1:
      f = new ShrubberyCreationForm(target);
      break;
    case 2:
      f = new RobotomyRequestForm(target);
      break;
    case 3:
      f = new PresidentialPardonForm(target);
      break;
    default:
      std::cout << "This intern doesn't know form of " << name << std::endl;
      f = NULL;
      return f;
  }
  std::cout << "Intern creates " << name << std::endl;
  return f;
}