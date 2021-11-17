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
  bool getIsSigned() const;
  const std::string &getName() const;
  unsigned int getGradeToSign() const;
  unsigned int getGradeToExecute() const;

  class GradeTooHighException : public std::exception {
  private:
    const char *_msg;

  public:
    GradeTooHighException(const char *msg);
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  private:
    const char *_msg;

  public:
    GradeTooLowException(const char *msg);
    const char *what() const throw();
  };

private:
  bool _isSigned;
  const std::string _name;
  const unsigned int _gradeToSign;
  const unsigned int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &stream, const Form &f);

#endif  // FORM_HPP