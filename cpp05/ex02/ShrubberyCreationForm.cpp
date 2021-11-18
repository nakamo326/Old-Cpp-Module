#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("ShrubberyCreationForm", 145, 137), _target("blank") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  checkExecutable(executor);
  std::string filepath(_target + "_shrubbery");
  std::ofstream ofs(filepath.c_str());
  ofs.exceptions(std::ofstream::badbit | std::ofstream::failbit);
  // if (!ofs) {
  // std::cout << "its should be exception but temporary msg" << std::endl;
  // return;
  // }

  ofs << "       _-_\n"
      << "    /~~   ~~\\\n"
      << " /~~         ~~\\\n"
      << "{               }\n"
      << " \\  _-     -_  /\n"
      << "   ~  \\\\ //  ~\n"
      << "_- -   | | _- _\n"
      << "  _ -  | |   -_\n"
      << "      // \\\\\n";

  std::cout << "Shrubbery was created!" << std::endl;
}