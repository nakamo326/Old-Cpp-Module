#include "Convert.hpp"

Convert::Convert() : _l(""), _t(nonDisplayable) {}

Convert::Convert(const std::string &literal)
    : _l(literal), _t(nonDisplayable) {}

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
  _t = checkType();
  switch (_t) {
    case nan:
      printNan();
      break;
    case pInf:
    case nInf:
      printInf();
      break;
    case _int:
      printInt();
      break;
    case _float:
      printFloat();
      break;
    case _double:
      printDouble();
    default:
      printNonDisplayable();
      break;
  }
}

Convert::e_type Convert::checkType() {
  if (_l == "nan" || _l == "nanf")
    return nan;
  if (_l == "+inf" || _l == "+inff" || _l == "inf" || _l == "inff")
    return pInf;
  if (_l == "-inf" || _l == "-inff")
    return nInf;
  return checkDisplayable();
}

Convert::e_type Convert::checkDisplayable() {
  const char *p = _l.c_str();
  while (std::isspace(static_cast<int>(*p))) p++;
  if (*p == '+' || *p == '-')
    p++;
  if (*p == '\0')
    return nonDisplayable;
  while (std::isdigit(static_cast<int>(*p))) p++;
  if (*p == '\0')
    return _int;
  if (*p == '.')
    p++;
  while (std::isdigit(static_cast<int>(*p))) p++;
  if (*p == 'f' && *(p + 1) == '\0')
    return _float;
  if (*p == '\0')
    return _double;
  else
    return nonDisplayable;
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
  char *e;
  int i;
  double d;
  if (_t == _int)
    i = std::atoi(_l.c_str());
  else
    d = std::strtod(_l.c_str(), &e);
  if (!std::isprint(i))
    std::cout << "char: Not displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}
void Convert::printInt() {
  int i;
  double d;
  i = std::atoi(_l.c_str());
  if (!std::isprint(i))
    std::cout << "char: Not displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
  std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void Convert::printFloat() {
  char *e;
  double d;
  d = std::strtod(_l.c_str(), &e);
  if (!std::isprint(d))
    std::cout << "char: Not displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
  std::cout << "int: " << static_cast<int>(d) << std::endl;
  std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}
void Convert::printDouble() {
  char *e;
  double d;
  d = std::strtod(_l.c_str(), &e);
  if (!std::isprint(d))
    std::cout << "char: Not displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
  std::cout << "int: " << static_cast<int>(d) << std::endl;
  std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}

void Convert::printNonDisplayable() {
  std::cout << "char: impossible\n"
            << "int: impossible\n"
            << "float: impossible\n"
            << "double: impossible" << std::endl;
}