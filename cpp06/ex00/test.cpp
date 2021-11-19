#include <iostream>

void output(std::string l) {
  std::cout << "char: '" << (char)std::atoi(l.c_str()) << "'" << std::endl;
  std::cout << "int: " << std::atoi(l.c_str()) << std::endl;
  std::cout << "float: " << std::stod(l) << std::endl;
}

int main() {
  std::string a = "42";

  output(a);

  return 0;
}
