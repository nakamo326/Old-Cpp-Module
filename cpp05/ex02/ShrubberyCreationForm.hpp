#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

private:
  std::string _target;
};

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("ShrubberyCreationForm", 145, 137), _target("blank") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target)
    : Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &other) {
  *this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

#endif  // SHRUBBERYCREATIONFORM_HPP