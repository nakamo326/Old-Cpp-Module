#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
  Intern();
  Intern(const Intern &other);
  ~Intern();
  Intern &operator=(const Intern &rhs);
  Form *makeForm(const std::string &name, const std::string &target);
  Form *makeSForm(const std::string &target);
  Form *makeRForm(const std::string &target);
  Form *makePForm(const std::string &target);
};

#endif  // INTERN_HPP