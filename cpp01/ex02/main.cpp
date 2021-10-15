#include <iostream>

int main(void) {
  std::string str = std::string("HI THIS IS BRAIN");
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << *stringPTR << std::endl;
  std::cout << stringREF << std::endl;

  // *stringPTR = std::string("HELLO WORLD");
  // std::cout << *stringPTR << std::endl;
  // std::cout << stringREF << std::endl;

  // stringREF = std::string("HELL WORD");
  // std::cout << *stringPTR << std::endl;
  // std::cout << stringREF << std::endl;

  return 0;
}
