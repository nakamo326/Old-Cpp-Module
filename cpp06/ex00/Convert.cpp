#include "Convert.hpp"

#include "Color.hpp"

Convert::Convert() {}

Convert::Convert(const std::string &literal)
    : _l(literal),
      _t(def),
      _overflowC(false),
      _overflowI(false),
      _overflowF(false),
      _overflowD(false),
      _isInf(false) {}

Convert::Convert(const Convert &other) { *this = other; }

Convert::~Convert() {}

Convert &Convert::operator=(const Convert &rhs) {
  if (this == &rhs)
    return *this;
  _l = rhs._l;
  _t = rhs._t;
  return *this;
}

void Convert::convert() {
  _t = detectType();
  if (_t == _int || _t == _float || _t == _double)
    getValue();
  detectOverflow(_d);
  switch (_t) {
    case _char:
      printAsChar();
      break;
    case _int:
      printAsInt();
      break;
    case _float:
      printAsFloat();
      break;
    case _double:
      printAsDouble();
      break;
    default:
      printNonDisplayable();
      break;
  }
  output();
}

Convert::e_type Convert::detectType() {
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
      std::cout << RED "[output as nan]" NC << std::endl;
      _ss_f << "nan";
      _ss_d << "nan";
      break;
    case pInf:
      std::cout << RED "[output as +inf]" NC << std::endl;
      _ss_f << "inff";
      _ss_d << "inf";
      break;
    case nInf:
      std::cout << RED "[output as -inf]" NC << std::endl;
      _ss_f << "-inff";
      _ss_d << "-inf";
      break;
    default:
      std::cout << RED "[output as invalid input or range error]" NC
                << std::endl;
      _ss_f << "impossible";
      _ss_d << "impossible";
      break;
  }
}

void Convert::getValue() {
  char *e;
  errno = 0;
  _d = std::strtod(_l.c_str(), &e);
  if (*e || errno == ERANGE || _l.at(_l.size() - 1) == '.') {
    _t = def;
  }
}

void Convert::detectOverflow(double d) {
  if (d < std::numeric_limits<char>::min() ||
      d > std::numeric_limits<char>::max())
    _overflowC = true;
  if (d < std::numeric_limits<int>::min() ||
      d > std::numeric_limits<int>::max())
    _overflowI = true;
  if (d < -std::numeric_limits<float>::max() ||
      d > std::numeric_limits<float>::max())
    _overflowF = true;
}

void Convert::printAsChar() {
  std::cout << GRN "[output as char]" NC << std::endl;
  char c = _l.at(0);
  printAll<char>(c);
}

void Convert::printAsInt() {
  std::cout << YLW "[output as int]" NC << std::endl;
  if (_overflowI) {
    _overflowF = true;
    _overflowD = true;
  }
  int i = static_cast<int>(_d);
  printAll<int>(i);
}

void Convert::printAsFloat() {
  std::cout << MGN "[output as float]" NC << std::endl;
  if (_overflowF) {
    _overflowD = true;
    _isInf = true;
  }
  float f = static_cast<float>(_d);
  printAll<float>(f);
}

void Convert::printAsDouble() {
  std::cout << CYN "[output as double]" NC << std::endl;
  printAll<double>(_d);
}

void Convert::output() {
  std::cout << "char:" << _ss_c.str() << "\n"
            << "int: " << _ss_i.str() << "\n"
            << "float: " << _ss_f.str() << "\n"
            << "double: " << _ss_d.str() << std::endl;
}