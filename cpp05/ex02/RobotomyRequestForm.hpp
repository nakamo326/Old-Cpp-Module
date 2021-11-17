#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>

#include "Form.hpp"

class RobotomyRequestForm : Form {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  ~RobotomyRequestForm();
  RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

private:
};

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) {
  *this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

#endif  // ROBOTOMYREQUESTFORM_HPP