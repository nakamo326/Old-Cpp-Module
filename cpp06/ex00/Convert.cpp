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
  _t = checkLiteral();
  switch (_t) {
    case nan:
      printNan();
      break;
    case pInf:
    case nInf:
      printInf();
      break;
    case nonDisplayable:
      printNonDisplayable();
      break;
    default:
      printDisplayable();
      break;
  }
}

Convert::e_type Convert::checkLiteral() {
  if (_l == "nan" || _l == "nanf")
    return nan;
  if (_l == "+inf" || _l == "+inff" || _l == "inf" || _l == "inff")
    return pInf;
  if (_l == "-inf" || _l == "-inff")
    return nInf;
  return checkDisplayable();
  // リテラルの型判定後->変換、キャストして表示！
}

Convert::e_type Convert::checkDisplayable() {
  if (!isDigits())
    return nonDisplayable;

  return displayable;
}

bool Convert::isDigits() {
  const char *p = _l.c_str();
  while (std::isspace(static_cast<int>(*p))) p++;
  if (*p == '+' || *p == '-')
    p++;
  if (*p == '\0')
    return false;
  while (std::isdigit(static_cast<int>(*p))) p++;
  if (*p == '.')
    p++;
  while (std::isdigit(static_cast<int>(*p))) p++;
  if (*p == '\0' || (*p == 'f' && *(p + 1) == '\0'))
    return true;
  else
    return false;
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
  const char *c = _l.c_str();
  double d = std::strtod(c, &e);
  int i = std::atoi(c);
  if (!std::isprint(i))
    std::cout << "char: Not displayable" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}

void Convert::printNonDisplayable() {
  std::cout << "char: impossible\n"
            << "int: impossible\n"
            << "float: impossible\n"
            << "double: impossible" << std::endl;
}