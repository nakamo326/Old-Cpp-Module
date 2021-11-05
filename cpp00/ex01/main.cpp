#include <iostream>
#include <string>

#include "contact.hpp"
#include "phonebook.hpp"

int main(void) {
  std::string cmd;
  PhoneBook pb;

  while (std::cin.good()) {
    std::cout << "INPUT COMMAND: ";
    std::getline(std::cin, cmd);
    if (cmd == "ADD") {
      if (!pb.add())
        break;
    } else if (cmd == "SEARCH") {
      if (!pb.search())
        break;
    } else if (cmd == "EXIT") {
      std::cout << "BYE~" << std::endl;
      break;
    } else if (std::cin.good()) {
      std::cout << "INVALID COMMAND!" << std::endl;
      std::cout << "USAGE: ADD, SEARCH, EXIT" << std::endl;
      continue;
    }
  }
  if (std::cin.eof())
    std::cout << std::endl << "GOT EOF. BYE~" << std::endl;
  return 0;
}
