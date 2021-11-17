#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Form {
public:
  Form();
  Form(const std::string &name, unsigned int gradeToSign,
       unsigned int gradeToExecute);
  Form(const Form &other);
  ~Form();
  Form &operator=(const Form &rhs);
  void beSigned(const Bureaucrat &b);

  class GradeTooHighException : public std::exception {
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };

private:
  bool _isSigned;
  const std::string _name;
  const unsigned int _gradeToSign;
  const unsigned int _gradeToExecute;
};

Form::Form()
    : _isSigned(false),
      _name("nameless"),
      _gradeToSign(1),
      _gradeToExecute(1) {}

Form::Form(const std::string &name, unsigned int gradeToSign,
           unsigned int gradeToExecute)
    : _isSigned(false),
      _name(name),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (_gradeToSign < 1 || _gradeToExecute < 1)
    throw GradeTooHighException();
  if (_gradeToSign > 150 || _gradeToExecute > 150)
    throw GradeTooLowException();
}

Form::Form(const Form &other)
    : _isSigned(other._isSigned),
      _name(other._name),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {}

Form::~Form() {}

Form &Form::operator=(const Form &rhs) {
  if (this == &rhs)
    return *this;
  const_cast<std::string &>(_name) = rhs._name;
  const_cast<unsigned int &>(_gradeToSign) = rhs._gradeToSign;
  const_cast<unsigned int &>(_gradeToExecute) = rhs._gradeToExecute;
  return *this;
}

void Form::beSigned(const Bureaucrat &b) {}

const char *Form::GradeTooHighException::what() const throw() {
  return "Bureaucrat's grade will be too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Bureaucrat's grade will be too low!";
}

std::ostream &operator<<(std::ostream &stream, const Form &f) {}

#endif  // FORM_HPP