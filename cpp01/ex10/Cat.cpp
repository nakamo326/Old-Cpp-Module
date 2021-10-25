#include "Cat.hpp"

Cat::Cat() {
}

Cat::~Cat() {
}

int Cat::outputError(const std::string& msg) {
  std::cout << "cato9tails: " << msg << std::endl;
  return EXIT_FAILURE;
}

int Cat::readStdIn() {
  std::string line;
  while (std::getline(std::cin, line)) {
    if (std::cin.eof())
      break;
    std::cout << line << std::endl;
  }
  return EXIT_SUCCESS;
}

int Cat::readFile(const char* path) {
  std::ifstream ifs(path);
  std::string line;

  if (!ifs)
    return outputError(std::string(path) + ": " + strerror(errno));
  while (std::getline(ifs, line)) {
    if (!ifs.eof()) {
      std::cout << line << std::endl;
    } else {
      std::cout << line;
    }
  }
  return EXIT_SUCCESS;
}
