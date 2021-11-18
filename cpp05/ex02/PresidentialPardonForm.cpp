#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : Form("PresidentialPardonForm", 25, 5), _target("blank") {}

PresidentialPardonForm::PresidentialPardonForm(std::string &target)
    : Form("PresidentialPardonForm", 25, 5), _target(target) {}

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

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  checkExecutable(executor);
  std::cout << _target << " has been pardoned by Zafod Beeblebrox."
            << std::endl;
}
