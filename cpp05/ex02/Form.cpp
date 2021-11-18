#include "Form.hpp"

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
    throw GradeTooHighException("Grade you input is too high!");
  if (_gradeToSign > 150 || _gradeToExecute > 150)
    throw GradeTooLowException("Grade you input is too low!");
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

void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() <= _gradeToSign) {
    _isSigned = true;
    std::cout << "[Form] Form Name: " << _name << " is signed by "
              << b.getName() << "." << std::endl;
    return;
  }
  throw GradeTooLowException("Bureaucrat's grade is too low to sign!");
}

// getter

bool Form::getIsSigned() const { return _isSigned; }

const std::string &Form::getName() const { return _name; }

unsigned int Form::getGradeToSign() const { return _gradeToSign; }

unsigned int Form::getGradeToExecute() const { return _gradeToExecute; }

// Exception class

Form::FormNotSignedException::FormNotSignedException(const char *msg)
    : _msg(msg) {}

const char *Form::FormNotSignedException::what() const throw() { return _msg; }

Form::GradeTooHighException::GradeTooHighException(const char *msg)
    : _msg(msg) {}

const char *Form::GradeTooHighException::what() const throw() { return _msg; }

Form::GradeTooLowException::GradeTooLowException(const char *msg) : _msg(msg) {}

const char *Form::GradeTooLowException::what() const throw() { return _msg; }

// stream overload

std::ostream &operator<<(std::ostream &stream, const Form &f) {
  stream << "Form Name: " << f.getName() << ", IsSigned: " << f.getIsSigned()
         << ", GradeToSigned: " << f.getGradeToSign()
         << ", GradeToExecute: " << f.getGradeToExecute();
  return stream;
}

// add for ex02
void Form::checkExecutable(Bureaucrat const &executor) const {
  if (executor.getGrade() <= _gradeToExecute)
    throw Form::GradeTooLowException(
        "Bureaucrat's grade is too low to execute!");
  if (!_isSigned)
    throw Form::FormNotSignedException("This form is not signed!");
};
