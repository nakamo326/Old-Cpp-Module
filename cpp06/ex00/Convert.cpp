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
    case _char:
      return printChar();
    case _int:
      return printInt();
    case _float:
      return printFloat();
    case _double:
      return printDouble();
    default:
      return printNonDisplayable();
  }
}

Convert::e_type Convert::checkType() {
  if (_l == "nan" || _l == "nanf")
    return nan;
  if (_l == "+inf" || _l == "+inff")
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

void Convert::printNonDisplayable() {
  std::cout << "char: impossible\n"
            << "int: impossible" << std::endl;
  switch (_t) {
    case nan:
      std::cout << "float: nanf\n"
                << "double: nan" << std::endl;
      break;
    case pInf:
      std::cout << "float: +inff\n"
                << "double: +inf" << std::endl;
      break;
    case nInf:
      std::cout << "float: -inff\n"
                << "double: -inf" << std::endl;
      break;
    default:
      std::cout << "float: impossible\n"
                << "double: impossible" << std::endl;
      break;
  }
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
  if (l < 32)
    std::cout << "char: Non displayable" << std::endl;
  else if (!(l >= 32 && l <= 126))
    std::cout << "char: impossible" << std::endl;
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

// need overflow check?

void Convert::printFloat() {
  float f;
  std::istringstream iss(_l);
  iss >> f;
  if (f < 32)
    std::cout << "char: Non displayable" << std::endl;
  else if (!(f >= 32 && f <= 126))
    std::cout << "char: impossible" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

  if (f <= std::numeric_limits<int>::max() &&
      f >= std::numeric_limits<int>::min())
    std::cout << "int: " << static_cast<int>(f) << std::endl;
  else
    std::cout << "int: impossible" << std::endl;
  int p = getPrec(f);
  std::cout << "float: " << std::fixed << std::setprecision(p) << f << "f"
            << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(p)
            << static_cast<double>(f) << std::endl;
}

void Convert::printDouble() {
  double d;
  std::istringstream iss(_l);
  iss >> d;
  if (d < 32)
    std::cout << "char: Non displayable" << std::endl;
  else if (!(d >= 32 && d <= 126))
    std::cout << "char: impossible" << std::endl;
  else
    std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
  if (d <= std::numeric_limits<int>::max() &&
      d >= std::numeric_limits<int>::min())
    std::cout << "int: " << static_cast<int>(d) << std::endl;
  else
    std::cout << "int: impossible" << std::endl;
  int p = getPrec(d);
  std::cout << "float: " << std::fixed << std::setprecision(p)
            << static_cast<float>(d) << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(p) << d
            << std::endl;
}

int Convert::getPrec(double d) {
  if (std::floor(d) == d)
    return 1;
  else
    return 10;
}
