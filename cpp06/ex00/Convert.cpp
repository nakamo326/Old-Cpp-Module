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
    case _char:
      printChar();
      break;
    case _int:
      printInt();
      break;
    case _float:
      printFloat();
      break;
    case _double:
      printDouble();
      break;
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
  if (std::isprint(*p) && !std::isdigit(*p) && *(p + 1) == '\0')
    return _char;
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

void Convert::printChar() {
  char c = _l.at(0);
  std::cout << "char: '" << c << "'" << std::endl;
  std::cout << "float: " << static_cast<int>(c) << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(c) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(c) << std::endl;
}

void Convert::printInt() {
  char *e;
  long l = std::strtol(_l.c_str(), &e, 10);
  if (!(l >= 32 && l <= 126))
    std::cout << "char: Not displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(l) << "'" << std::endl;

  if (l <= std::numeric_limits<int>::max() &&
      l >= std::numeric_limits<int>::min())
    std::cout << "int: " << l << std::endl;
  else
    std::cout << "int: impossible" << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << static_cast<float>(l) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(l) << std::endl;
}

void Convert::printFloat() {
  char *e;
  const char *p = _l.c_str();
  double d;
  d = std::strtod(p, &e);
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
  const char *p = _l.c_str();
  double d;
  d = std::strtod(p, &e);
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