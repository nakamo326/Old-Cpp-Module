#include "Convert.hpp"

#include "Color.hpp"

Convert::Convert() : _l(""), _t(def) {}

Convert::Convert(const std::string &literal) : _l(literal), _t(def) {}

Convert::Convert(const Convert &other) { *this = other; }

Convert::~Convert() {}

Convert &Convert::operator=(const Convert &rhs) {
  if (this == &rhs)
    return *this;
  _l = rhs._l;
  _t = rhs._t;
  return *this;
}

Convert::e_type Convert::checkType() {
  if (_l == "nan" || _l == "nanf")
    return nan;
  if (_l == "+inf" || _l == "+inff")
    return pInf;
  if (_l == "-inf" || _l == "-inff")
    return nInf;
  if (_l.size() == 0 || _l == "inf")
    return def;
  if (std::isprint(_l.at(0)) && !std::isdigit(_l.at(0)) && _l.size() == 1)
    return _char;
  if (_l.size() && (_l.find(".", 0) != std::string::npos)) {
    if (_l.at(_l.size() - 1) == 'f') {
      _l = _l.substr(0, _l.size() - 1);
      return _float;
    }
    return _double;
  }
  return _int;
}

void Convert::printNonDisplayable() {
  _ss_c << "impossible";
  _ss_i << "impossible";
  switch (_t) {
    case nan:
      _ss_f << "nan";
      _ss_d << "nan";
      break;
    case pInf:
      _ss_f << "inff";
      _ss_d << "inf";
      break;
    case nInf:
      _ss_f << "-inff";
      _ss_d << "-inf";
      break;
    default:
      _ss_f << "impossible";
      _ss_d << "impossible";
      break;
  }
}

void Convert::convert() {
  _t = checkType();
  if (_t != _char)
    if (!getValue())
      return printNonDisplayable();

  switch (_t) {
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
  output();
}

bool Convert::getValue() {
  char *e;
  errno = 0;
  _d = std::strtod(_l.c_str(), &e);
  if (*e || errno == ERANGE || _l.at(_l.size() - 1) == '.') {
    return false;
  }
  return true;
}

void Convert::printChar() {
  std::cout << GRN "output as char" NC << std::endl;
  char c = _l.at(0);
  printAsChar<char>(c);
  printAsInt<char>(c);
  printAsFloat<char>(c);
  printAsDouble<char>(c);
}

void Convert::printInt() {
  std::cout << GRN "output as int" NC << std::endl;
  printAsChar<double>(_d);
  printAsInt<double>(_d);
  printAsFloat<double>(_d);
  printAsDouble<double>(_d);
}

void Convert::printFloat() {
  std::cout << GRN "output as float" NC << std::endl;
  printAsChar<double>(_d);
  printAsInt<double>(_d);
  printAsFloat<double>(_d);
  printAsDouble<double>(_d);
}

void Convert::printDouble() {
  std::cout << GRN "output as double" NC << std::endl;
  printAsChar<double>(_d);
  printAsInt<double>(_d);
  printAsFloat<double>(_d);
  printAsDouble<double>(_d);
}

void Convert::output() {
  std::cout << "char:" << _ss_c.str() << "\n"
            << "int: " << _ss_i.str() << "\n"
            << "float: " << _ss_f.str() << "\n"
            << "double: " << _ss_d.str() << std::endl;
}
