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
  std::string _target;
};

RobotomyRequestForm::RobotomyRequestForm()
    : Form("RobotomyRequestForm", 72, 45), _target("blank") {}

RobotomyRequestForm::RobotomyRequestForm(std::string &target)
    : Form("RobotomyRequestForm", 72, 45), _target(target) {}

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