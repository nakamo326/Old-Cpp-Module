#include "Convert.hpp"

Convert::Convert() : _l(""), _t(displayable) {}

Convert::Convert(const std::string &literal) : _l(literal), _t(displayable) {}

Convert::Convert(const Convert &other) { *this = other; }

Convert::~Convert() {}

Convert &Convert::operator=(const Convert &rhs) {
  if (this == &rhs)
    return *this;
  _l = rhs._l;
  _t = rhs._t;
  return *this;
}

void Convert::print() {
  checkLiteral();
  switch (_t) {
    case nan:
      printNan();
      break;
    case pInf:
    case nInf:
      printInf();
      break;
    default:
      printDisplayable();
      break;
  }
}

void Convert::checkLiteral() {
  if (_l == "nan" || _l == "nanf")
    _t = nan;
  if (_l == "+inf" || _l == "+inff")
    _t = pInf;
  if (_l == "-inf" || _l == "-inff")
    _t = nInf;
}

void Convert::printNan() {
  std::cout << "char: impossible\n"
            << "int: impossible\n"
            << "float: nanf\n"
            << "double: nan" << std::endl;
}

void Convert::printInf() {
  std::cout << "char: impossible\n"
            << "int: impossible\n";
  if (_t == pInf)
    std::cout << "float: +inff\n"
              << "double: +inf" << std::endl;
  else if (_t == nInf)
    std::cout << "float: -inff\n"
              << "double: -inf" << std::endl;
}

void Convert::printDisplayable() {
  int i = std::atoi(_l.c_str());
  if (!std::isprint(i))
    std::cout << "char: Not displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
  std::cout << "int: " << i << std::endl;
}

void Convert::outputFloat() {}

void Convert::outputDouble() {}
