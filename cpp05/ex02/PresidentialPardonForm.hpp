#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "Form.hpp"

class PresidentialPardonForm : Form {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

private:
};

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string &target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other) {
  *this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    const PresidentialPardonForm &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

#endif  // PRESIDENTIALPARDONFORM_HPP